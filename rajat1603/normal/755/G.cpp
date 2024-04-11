#include "bits/stdc++.h"
using namespace std;
const int K = 1 << 15;
const int mod = 998244353;
const int G = 3;
const int GI = 332748118;
const int I = 998229121;
int dp[5][K];
int n , k;
void pre(){
    memset(dp , 0 , sizeof(dp));
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[2][0] = 1;
    dp[2][1] = 3;
    dp[2][2] = 1;
    dp[3][0] = 1;
    dp[3][1] = 5;
    dp[3][2] = 5;
    dp[3][3] = 1;
    dp[4][0] = 1;
    dp[4][1] = 7;
    dp[4][2] = 13;
    dp[4][3] = 7;
    dp[4][4] = 1;
}
int power(int a , int b){
    int res = 1;
    while(b){
        if(b & 1){
            res = (1LL * res * a) % mod;
        }
        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return res;
}
void fft(int a[] , bool invert){
    for(int i = 1 , j = 0 ; i < K + K ; ++i){
        int bit = K;
        for(; j >= bit ; bit >>= 1){
            j -= bit;
        }
        j += bit;
        if(i < j){
            swap(a[i] , a[j]);
        }
    }
    for(int len = 2 ; len <= K + K ; len <<= 1){
        int wlen = power(invert ? GI : G , (mod - 1) / len);
        for(int i = 0 ; i < K + K ; i += len){
            int w = 1;
            for(int j = 0 ; j + j < len ; ++j){
                int u = a[i + j];
                int v = (1LL * a[i + j + len / 2] * w) % mod;
                a[i + j] = (u + v < mod) ? (u + v) : (u + v - mod);
                a[i + j + len / 2] = (u >= v) ? (u - v) : (u - v + mod);
                w = (1LL * w * wlen) % mod;
            }
        }
    }
    if(invert){
        for(int i = 0 ; i < K + K ; ++i){
            a[i] = (1LL * a[i] * I) % mod;
        }
    }
}
int na[K];
int nb[K];
int nc[K];
int tmpa[K];
int tmpb[K];
int tmpc[K];
int ffta[K + K];
int fftb[K + K];
void mult(int res[] , int a[] , int b[]){
    memset(ffta , 0 , sizeof(ffta));
    memset(fftb , 0 , sizeof(fftb));
    for(int i = 0 ; i < K ; ++i){
        ffta[i] = a[i];
        fftb[i] = b[i];
    }
    fft(ffta , 0);
    fft(fftb , 0);
    for(int i = 0 ; i < K + K ; ++i){
        ffta[i] = (1LL * ffta[i] * fftb[i]) % mod;
    }
    fft(ffta , 1);
    for(int i = 0 ; i < K ; ++i){
        res[i] = ffta[i];
    }
}
void solve(int n){
    if(n < 5){
        for(int i = 0 ; i < K ; ++i){
            nc[i] = dp[n][i];
            nb[i] = dp[n - 1][i];
            na[i] = dp[n - 2][i];
        }
    }
    else if(n & 1){
        solve(n - 1);
        for(int i = 0 ; i < K ; ++i){
            na[i] = nb[i];
            nb[i] = nc[i];
        }
        nc[0] = nb[0];
        for(int i = 1 ; i < K ; ++i){
            nc[i] = (0u + nb[i] + nb[i - 1] + na[i - 1]) % mod;
        }
    }
    else{
        solve(n >> 1);
        mult(tmpc , nb , nb);
        mult(tmpb , na , na);
        for(int i = 1 ; i < K ; ++i){
            tmpc[i] += tmpb[i - 1];
            if(tmpc[i] >= mod){
                tmpc[i] -= mod;
            }
        }
        mult(tmpb , nc , nb);
        mult(tmpa , nb , na);
        for(int i = 1 ; i < K ; ++i){
            tmpb[i] += tmpa[i - 1];
            if(tmpb[i] >= mod){
                tmpb[i] -= mod;
            }
        }
        memcpy(na , tmpc , sizeof(int) * K);
        memcpy(nb , tmpb , sizeof(int) * K);
        nc[0] = nb[0];
        for(int i = 1 ; i < K ; ++i){
            nc[i] = (0u + nb[i] + nb[i - 1] + na[i - 1]) % mod;
        }
    }
}
int main(){
    scanf("%d %d" , &n , &k);
    pre();
    solve(n);
    for(int i = 1 ; i <= k ; ++i){
        printf("%d%c" , nc[i] , " \n"[i == k]);
    }
}