#include "bits/stdc++.h"
using namespace std;
const int LN = 20;
const int N = 1 << LN;
const int mod = 1e9 + 7;
int add(int a , int b){
    int res = a + b;
    if(res >= mod){
        return res - mod;
    }
    return res;
}
int n;
int arr[N];
int p[N];
int inp;
int res = 0;
int main(){
    scanf("%d" , &n);
    p[0] = 1;
    for(int i = 1 ; i <= n ; ++i){
        p[i] = add(p[i - 1] , p[i - 1]);
    }
    while(n--){
        scanf("%d" , &inp);
        ++arr[inp];
    }
    for(int i = 0 ; i < LN ; ++i){
        for(int j = N - 1 ; j >= 0 ; --j){
            if(!(j & (1 << i))){
                arr[j] += arr[j | (1 << i)];
            }
        }
    }
    for(int i = 0 ; i < N ; ++i){
        if(__builtin_popcount(i) & 1){
            res = add(res , mod - p[arr[i]]);
        }
        else{
            res = add(res , p[arr[i]]);
        }
    }
    printf("%d\n" , res);
}