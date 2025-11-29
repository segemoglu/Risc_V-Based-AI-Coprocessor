#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "weights.h"

float paint_image[784] = {
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0627f, 0.5922f, 0.8745f, 0.8745f, 
    0.6549f, 0.0941f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0627f, 0.5922f, 0.8745f, 1.0000f, 1.0000f, 1.0000f, 
    1.0000f, 1.0000f, 1.0000f, 0.8745f, 0.6549f, 0.0941f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0627f, 0.7176f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 
    1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.8745f, 0.6549f, 0.0941f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0627f, 0.7176f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 
    1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.8118f, 0.0941f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0627f, 0.7176f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 
    1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.8118f, 0.0941f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0627f, 0.7176f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 
    1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.7490f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.6235f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.9373f, 0.2824f, 0.0000f, 
    0.0000f, 0.1569f, 0.8431f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.9373f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.9373f, 0.2824f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.1569f, 0.8745f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.9373f, 0.2824f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.1569f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.0941f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0627f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.2824f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.7490f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.6235f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.9686f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.9373f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.7490f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.9059f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.1569f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.9686f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0627f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.7490f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.6235f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.1569f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.1255f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.9373f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.9686f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.7804f, 0.0941f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0627f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.8745f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.7490f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.8745f, 0.6549f, 0.0941f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0627f, 0.7176f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.2824f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.1569f, 0.9686f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 
    1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.7490f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 
    1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.8745f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.1569f, 0.8745f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 
    1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.9373f, 0.2824f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.1569f, 0.8431f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 
    1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.9373f, 0.2824f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.1569f, 0.8431f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 
    1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 1.0000f, 0.9059f, 0.2824f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
    0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 
};

// Bu yapi hem giris resmini, hem de katmanlar arasindaki verileri tutacak.
typedef struct {
    float *data;    // Verilerin durdugu tek boyutlu dizi (Pointer)
    int w;          // Genislik
    int h;          // Yukseklik
    int c;          // Kanal Sayisi (Derinlik)
} Volume;


// Yeni bir Volume (Veri bloku) olusturmak icin yardimci fonksiyon
// Ornegin: make_volume(32, 32, 1, 0.0) -> 32x32 boyutunda, tek kanalli, ici 0 dolu bir yapi doner.
Volume* make_volume(int w, int h, int c, float init_val) {
    Volume* v = (Volume*)malloc(sizeof(Volume));
    v->w = w;
    v->h = h;
    v->c = c;
    
    // Toplam eleman sayisi = Genislik * Yukseklik * Kanal
    int size = w * h * c;
    
    // Bellekten yer ayir (float boyutu * eleman sayisi kadar)
    v->data = (float*)malloc(size * sizeof(float));
    
    // Icini baslangic degeriyle doldur (Genelde 0)
    for (int i = 0; i < size; i++) {
        v->data[i] = init_val;
    }
    
    return v;
}


// Bellegi temizlemek icin fonksiyon (C'de Garbage Collector yok, biz temizlemeliyiz)
void free_volume(Volume* v) {
    if (v) {
        free(v->data); // Once icindeki veri dizisini sil
        free(v);        // Sonra yapinin kendisini sil
    }
}





// --- YARDIMCI FONKSÝYONLAR ---

// 1. Veri Okuma: "Bana (x, y, d) konumundaki sayýyý ver"
float get_vol(Volume* v, int x, int y, int d) {
    // Sýnýr kontrolü: Eðer resmin dýþýna taþarsak 0.0 (Siyah) kabul et.
    // Bu, "Padding" (Kenar doldurma) iþlemi için hayat kurtarýcýdýr.
    if (x < 0 || x >= v->w || y < 0 || y >= v->h || d < 0 || d >= v->c) {
        return 0.0f;
    }
    // Matematiksel Formül: (Derinlik * Geniþlik * Yükseklik) + (Y * Geniþlik) + X
    return v->data[(d * v->w * v->h) + (y * v->w) + x];
}

// 2. Veri Yazma: "Þu konuma þu sayýyý yaz"
void set_vol(Volume* v, int x, int y, int d, float val) {
    // Sýnýr dýþýna yazmaya çalýþýrsak hiçbir þey yapma (Güvenlik)
    if (x < 0 || x >= v->w || y < 0 || y >= v->h || d < 0 || d >= v->c) {
        return;
    }
    v->data[(d * v->w * v->h) + (y * v->w) + x] = val;
}





// --- CONVOLUTION KATMAN YAPISI ---
typedef struct {
    Volume **filters; // Filtreler dizisi (Ýçinde birden çok Volume tutacak)
    float *biases;    // Her filtre için bir ek sayý (Bias)
    int filter_count; // Kaç tane filtremiz var?
    int kernel_size;  // Filtre boyutu (Örn: 5x5)
    int stride;       // Kaç piksel kaydýracaðýz?
    int padding;      // Kenarlara kaç sýra 0 ekleyeceðiz?
} ConvLayer;


// Katmaný baþlatan ve bellekte yer ayýran fonksiyon
ConvLayer* init_conv_layer(int input_c, int filter_count, int kernel_size, int stride, int padding) {
    ConvLayer* layer = (ConvLayer*)malloc(sizeof(ConvLayer));
    layer->filter_count = filter_count;
    layer->kernel_size = kernel_size;
    layer->stride = stride;
    layer->padding = padding;

    // Filtreler ve Biaslar için yer ayýr
    layer->filters = (Volume**)malloc(filter_count * sizeof(Volume*));
    layer->biases = (float*)malloc(filter_count * sizeof(float));

    // Her filtreyi oluþtur ve içini rastgele doldur
    for (int i = 0; i < filter_count; i++) {
        // Filtre derinliði = Giriþ resminin derinliði (input_c)
        layer->filters[i] = make_volume(kernel_size, kernel_size, input_c, 0.0);
        
        // Rastgele sayý verme kýsmý (-0.1 ile 0.1 arasýnda)
        int size = kernel_size * kernel_size * input_c;
        for (int j = 0; j < size; j++) {
			int global_idx = (i * (kernel_size * kernel_size * input_c)) + j;
			layer->filters[i]->data[j] = conv_weights[global_idx];
        }
        
        layer->biases[i] = conv_biases[i];
    }
    return layer;
}


// --- CONVOLUTION ÝÞLEMÝ (MOTOR) ---
Volume* conv_forward(ConvLayer* layer, Volume* input) {
    // 1. Çýktý boyutlarýný hesapla: (Giriþ - Filtre + 2*Padding) / Adým + 1
    int out_w = (input->w - layer->kernel_size + 2 * layer->padding) / layer->stride + 1;
    int out_h = (input->h - layer->kernel_size + 2 * layer->padding) / layer->stride + 1;

    // Çýktý için boþ bir volume oluþtur
    Volume* output = make_volume(out_w, out_h, layer->filter_count, 0.0);
    
    // --- 6 KATLI DÖNGÜ (Korkma, mantýðý basit) ---
    
    // 1. Her Filtre için dön (Örn: 6 filtre)
    for (int f = 0; f < layer->filter_count; f++) {
        
        // 2. & 3. Çýktý resminin Y ve X koordinatlarýnda gez
        for (int y = 0; y < out_h; y++) {
            for (int x = 0; x < out_w; x++) {
                
                float sum = 0.0f; // Toplamý tutacak deðiþken
                
                // 4. Giriþ resminin kanallarýnda gez (RGB ise 3, SB ise 1)
                for (int c = 0; c < input->c; c++) {
                    
                    // 5. & 6. Filtrenin kendi içinde gez (Kernel X ve Y)
                    for (int ky = 0; ky < layer->kernel_size; ky++) {
                        for (int kx = 0; kx < layer->kernel_size; kx++) {
                            
                            // Giriþ resminde hangi piksele denk geliyoruz?
                            int in_x = x * layer->stride + kx - layer->padding;
                            int in_y = y * layer->stride + ky - layer->padding;
                            
                            // Deðerleri al: Giriþ Pikseli * Filtre Aðýrlýðý
                            float val_in = get_vol(input, in_x, in_y, c);
                            float val_w  = get_vol(layer->filters[f], kx, ky, c);

                            // Çarp ve topla (MAC Ýþlemi: Multiply-Accumulate)
                            sum += val_in * val_w;
                        }
                    }
                }
                
                // Ýþlem bitti, Bias (Önyargý) ekle
                sum += layer->biases[f];
                
                // Sonucu kaydet
                set_vol(output, x, y, f, sum);
            }
        }
    }
    
    return output;
}


// --- 4. RELU AKTIVASYON FONKSIYONU ---
// Negatif deðerleri sýfýrlar. Veriyi yerinde (in-place) deðiþtirir, bellek dostudur.
void relu_forward(Volume* v) {
    int total_size = v->w * v->h * v->c;
    for (int i = 0; i < total_size; i++) {
        if (v->data[i] < 0) {
            v->data[i] = 0.0f;
        }
    }
}

// --- 5. MAX POOLING (HAVUZLAMA) ---
// Resmi küçültür (Downsampling). Genelde 2x2 filtre ve 2 stride kullanýlýr.
Volume* max_pool_forward(Volume* input, int kernel_size, int stride) {
    int out_w = (input->w - kernel_size) / stride + 1;
    int out_h = (input->h - kernel_size) / stride + 1;
    
    Volume* output = make_volume(out_w, out_h, input->c, 0.0);
    
    // Her kanal için (Derinlik)
    for (int c = 0; c < input->c; c++) {
        // Çýktý Yüksekliði
        for (int y = 0; y < out_h; y++) {
            // Çýktý Geniþliði
            for (int x = 0; x < out_w; x++) {
                
                // O bölgedeki En Büyük Sayýyý (MAX) bulacaðýz
                float max_val = -1000000.0f; // Baþlangýçta çok küçük bir sayý verelim
                
                for (int ky = 0; ky < kernel_size; ky++) {
                    for (int kx = 0; kx < kernel_size; kx++) {
                        
                        int in_x = x * stride + kx;
                        int in_y = y * stride + ky;
                        
                        float val = get_vol(input, in_x, in_y, c);
                        
                        if (val > max_val) {
                            max_val = val;
                        }
                    }
                }
                
                // Bulunan en büyük deðeri çýktýya yaz
                set_vol(output, x, y, c, max_val);
            }
        }
    }
    return output;
}


// --- 6. FC (FULLY CONNECTED) KATMAN YAPISI ---
typedef struct {
    float *weights;  // Aðýrlýklar (Matris)
    float *biases;   // Biaslar
    int input_size;  // Giriþ sayýsý (Örn: 14*14*6 = 1176)
    int output_size; // Çýkýþ sayýsý (Örn: 10 rakam için 10)
} FCLayer;

// FC Katmanýný Baþlat
FCLayer* init_fc_layer(int input_size, int output_size) {
    FCLayer* layer = (FCLayer*)malloc(sizeof(FCLayer));
    layer->input_size = input_size;
    layer->output_size = output_size;
    
    layer->weights = (float*)malloc(input_size * output_size * sizeof(float));
    layer->biases = (float*)malloc(output_size * sizeof(float));
    
    // Rastgele Aðýrlýklar
    for (int i = 0; i < input_size * output_size; i++) {
        layer->weights[i] = fc_weights[i];
    }
    for (int i = 0; i < output_size; i++) {
        layer->biases[i] = fc_biases[i];
    }
    return layer;
}

// --- 7. FC FORWARD (Matris Çarpýmý: y = Wx + b) ---
// Not: Giriþ volume'unu otomatik olarak düzleþtirilmiþ (flat) varsayarýz.
Volume* fc_forward(FCLayer* layer, Volume* input) {
    Volume* output = make_volume(1, 1, layer->output_size, 0.0);
    
    // Her bir çýktý nöronu için hesapla
    for (int i = 0; i < layer->output_size; i++) {
        float sum = 0.0f;
        
        // Giriþ verisindeki tüm elemanlarla aðýrlýklarý çarp ve topla
        // Giriþ verisi 3D olsa bile bellekte arka arkaya durduðu için
        // input->data[j] diyerek hepsine sýrayla eriþebiliriz.
        int total_input_size = input->w * input->h * input->c;
        
        for (int j = 0; j < total_input_size; j++) {
            // weights matrisinde doðru sýradaki elemaný bul
            // index = j * output_size + i (veya tam tersi, tasarýma baðlý)
            // Bizim sýramýz: weight[giris_index * cýkýs_sayisi + cýkýs_index]
            float w = layer->weights[j * layer->output_size + i];
            sum += input->data[j] * w;
        }
        
        sum += layer->biases[i];
        output->data[i] = sum;
    }
    return output;
}

// --- 8. SOFTMAX (Olasýlýk Hesaplama) ---
// Sayýlarý 0 ile 1 arasýna sýkýþtýrýr, toplamlarý 1 olur.
void softmax(Volume* v) {
    float max_val = -1000000.0f;
    int size = v->w * v->h * v->c;
    
    // Taþmayý önlemek için en büyük sayýyý bul
    for (int i = 0; i < size; i++) {
        if (v->data[i] > max_val) max_val = v->data[i];
    }
    
    float sum = 0.0f;
    for (int i = 0; i < size; i++) {
        v->data[i] = exp(v->data[i] - max_val); // e üzeri x
        sum += v->data[i];
    }
    
    for (int i = 0; i < size; i++) {
        v->data[i] /= sum; // Toplama böl
    }
}





int main() {
    srand(time(NULL));
    printf("--- RISC-V PROJESI: CNN C SÝMÜLASYONU ---\n\n");

    // 1. GÝRÝÞ (INPUT)
    // 28x28 boyutunda bir resim (Örn: El yazýsý 5 rakamý)
	Volume* input = make_volume(28, 28, 1, 0.0);
    for(int i=0; i < 28*28; i++) {
        input->data[i] = paint_image[i]; // Artýk paint resmini kullanýyoruz
    }
    printf("[1] Giris Resmi (Paint Cizimi) Yuklendi.\n");

    // ----------------------------------------------------
    // KATMAN 1: ÖZELLÝK ÇIKARMA (Feature Extraction)
    // ----------------------------------------------------
    
    // Kurulum: 6 Filtre, 5x5 Kernel
    ConvLayer* c1 = init_conv_layer(1, 6, 5, 1, 2);
    
    // Ýþlem: Conv -> ReLU -> Pool
    Volume* v1 = conv_forward(c1, input);    // 28x28x6 olur
    relu_forward(v1);                        // Negatifleri sil
    Volume* v2 = max_pool_forward(v1, 2, 2); // 14x14x6 olur (Boyut yarýya indi)
    
    printf("[2] Katman 1 (Conv+Relu+Pool) Tamam. Cikti: %dx%dx%d\n", v2->w, v2->h, v2->c);

    // ----------------------------------------------------
    // KATMAN 2: SINIFLANDIRMA (Classification)
    // ----------------------------------------------------
    
    // Flatten (Düzleþtirme) iþlemi otomatik yapýlacak.
    // Giriþ Boyutu: 14 * 14 * 6 = 1176 tane sayý
    // Çýkýþ Boyutu: 10 tane rakam (0..9 arasý)
    int input_neurons = 14 * 14 * 6;
    int output_classes = 10;
    
    FCLayer* fc1 = init_fc_layer(input_neurons, output_classes);
    
    // Ýþlem: FC -> Softmax
    Volume* v3 = fc_forward(fc1, v2); // Sonuç: 1x1x10
    softmax(v3);                      // Ýhtimale çevir
    
    printf("[3] Katman 2 (FC+Softmax) Tamam. Cikti: %dx%dx%d\n", v3->w, v3->h, v3->c);

    // ----------------------------------------------------
    // SONUÇLARI GÖSTER
    // ----------------------------------------------------
    printf("\n--- TAHMIN SONUCLARI ---\n");
    int en_yuksek_index = 0;
    float en_yuksek_deger = 0.0;
    
    for (int i = 0; i < 10; i++) {
        float olasilik = v3->data[i];
        printf("Rakam %d ihtimali: %% %.2f\n", i, olasilik * 100);
        
        if (olasilik > en_yuksek_deger) {
            en_yuksek_deger = olasilik;
            en_yuksek_index = i;
        }
    }
    
    printf("\n>>> SON KARAR: Bu resim %d rakamidir! (%%%.2f) <<<\n", en_yuksek_index, en_yuksek_deger * 100);

    // TEMÝZLÝK
    free_volume(input);
    free_volume(v1);
    free_volume(v2);
    free_volume(v3);
    // Katmanlarý (c1, fc1) silmek için ayrý fonksiyon yazmadýk ama iþletim sistemi halleder.
    
    printf("\nCikmak icin tusa basin...");
    getchar();
    return 0;
}
