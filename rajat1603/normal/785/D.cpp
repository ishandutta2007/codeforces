#include "bits/stdc++.h"
using namespace std;
const int N = 4e5 + 5;
const int mod = 1e9 + 7;
int n;
char str[N];
int x , y;
int ans;
int ifact[N];
int fact[N];
void pre(){
    fact[0] = 1;
    for(int i = 1 ; i < N ; ++i){
        fact[i] = (1LL * fact[i - 1] * i) % mod;
    }
    ifact[N - 1] = 977041169;
    for(int i = N - 2 ; i >= 0 ; --i){
        ifact[i] = (1LL * ifact[i + 1] * (i + 1LL)) % mod;
    }
}
int ncr(int n , int r){
    if(r >= 0 && r <= n){
        int res = fact[n];
        res = (1LL * res * ifact[r]) % mod;
        res = (1LL * res * ifact[n - r]) % mod;
        return res;
    }
    else{
        return 0;
    }
}
int main(){
    pre();
    scanf("%s" , str + 1);
    n = strlen(str + 1);
    x = 0;
    y = 0;
    ans = 0;
    for(int i = 1 ; i <= n ; ++i){
        y += (str[i] == ')');
    }
    for(int i = 1 ; i <= n ; ++i){
        y -= (str[i] == ')');
        if(str[i] == '('){
            ans += ncr(x + y , y - 1);
            if(ans >= mod){
                ans -= mod;
            }
        }
        x += (str[i] == '(');
    }
    printf("%d\n" , ans);
}