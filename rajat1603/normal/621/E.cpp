#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;
const int X = 100;
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
int n , b , k , x;
vector < int > base(X , 0);
vector < int > res(X , 0);
vector < int > res2(X , 0);
int inp;
vector < int > power(int b){
    if(b == 1){
        return base;
    }
    vector < int > tmp = power(b >> 1);
    res.clear();
    res.resize(X , 0);
    int pw = power(10 , b >> 1 , x);
    for(int i = 0 ; i < x ; ++i){
        for(int j = 0 ; j < x ; ++j){
            res[add(mult(i , pw , x) , j , x)] = add(res[add(mult(i , pw , x) , j , x)] , mult(tmp[i] , tmp[j] , mod) , mod);
        }
    }
    if(b & 1){
        res2.clear();
        res2.resize(X , 0);
        for(int i = 0 ; i < x ; ++i){
            for(int j = 0 ; j < x ; ++j){
                res2[add(mult(i , 10 , x) , j , x)] = add(res2[add(mult(i , 10 , x) , j , x)] , mult(res[i] , base[j] , mod) , mod);
            }
        }
        return res2;
    }
    return res;
}
int main(){
    scanf("%d %d %d %d" , &n , &b , &k , &x);
    while(n--){
        scanf("%d" , &inp);
        ++base[inp % x];
    }
    printf("%d\n" , power(b)[k]);
}