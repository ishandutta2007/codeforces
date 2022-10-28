#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int add(int a , int b , int mod){
    int res = a + b;
    if(res >= mod){
        return res - mod;
    }
    return res;
}
int mult(int a , int b , int mod){
    long long res = a;
    res *= b;
    if(res >= mod){
        return res % mod;
    }
    return res;
}
int power(int a , int b , int mod){
    int res = 1;
    while(b){
        if(b & 1){
            res = mult(res , a , mod);
        }
        a = mult(a , a , mod);
        b >>= 1;
    }
    return res;
}
int c2(int x , int mod){
    if(x & 1){
        return mult(x , (x + 1) >> 1 , mod);
    }
    else{
        return mult(x >> 1 , x + 1 , mod);
    }
}
int n;
int arr[N];
int suf[N];
int pre[N];
int inp;
int res = 1;
int main(){
    scanf("%d" , &n);
    while(n--){
        scanf("%d" , &inp);
        ++arr[inp];
    }
    pre[0] = 1;
    for(int i = 1 ; i < N ; ++i){
        pre[i] = mult(pre[i - 1] , arr[i] + 1 , mod - 1);
    }
    suf[N - 1] = 1;
    for(int i = N - 2 ; i >= 0 ; --i){
        suf[i] = mult(suf[i + 1] , arr[i] + 1 , mod - 1);
    }
    for(int i = 1 ; i < N ; ++i){
        res = mult(res , power(i , mult(c2(arr[i] , mod - 1) , mult(pre[i - 1] , suf[i + 1] , mod - 1) , mod - 1) , mod) , mod);
    }
    printf("%d\n" , res);
}