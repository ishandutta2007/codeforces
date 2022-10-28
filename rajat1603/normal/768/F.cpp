#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
const int mod = 1e9 + 7;
int add(int a , int b){
    return (a + b) % mod;
}
int mult(int a , int b){
    return (1LL * a * b) % mod;
}
int power(int a , int b){
    int res = 1;
    while(b){
        if(b & 1){
            res = mult(res , a);
        }
        a = mult(a , a);
        b >>= 1;
    }
    return res;
}
int food , wine , h;
int num , den;
int fact[N];
int ifact[N];
void pre(){
    fact[0] = 1;
    for(int i = 1 ; i < N ; ++i){
        fact[i] = mult(fact[i - 1] , i);
    }
    ifact[N - 1] = power(fact[N - 1] , mod - 2);
    for(int i = N - 2 ; i >= 0 ; --i){
        ifact[i] = mult(ifact[i + 1] , i + 1);
    }
}
int ncr(int n , int r){
    return mult(fact[n] , mult(ifact[r] , ifact[n - r]));
}
int place(int len , int sum){
    return ncr(len + sum - 1 , len - 1);
}
int main(){
    pre();
    cin >> food >> wine >> h;
    ++h;
    if(wine == 0){
        num = 1;
        den = 1;
    }
    else{
        for(int i = 1 ; i <= wine ; ++i){
            if(food < i - 1){
                break;
            }
            if(wine < i){
                break;
            }
            den = add(den , mult(place(i + 1 , food - (i - 1)) , place(i , wine - i)));
            if(1LL * i * h <= wine){
                num = add(num , mult(place(i + 1 , food - (i - 1)) , place(i , wine - i * h)));
            }
        }
    }
    printf("%d\n" , mult(num , power(den , mod - 2)));
}