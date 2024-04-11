#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
long long n , k , x;
long long arr[N];
long long ans = 0;
long long pre[N];
long long suf[N];
int main(){
    scanf("%lld %lld %lld" , &n , &k , &x);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%lld" , arr + i);
    }
    for(int i = 1 ; i <= n ; ++i){
        pre[i] = pre[i - 1] | arr[i];
    }
    for(int i = n ; i >= 1 ; --i){
        suf[i] = suf[i + 1] | arr[i];
    }
    for(int i = 1 ; i <= n ; ++i){
        long long temp = arr[i];
        for(int j = 0 ; j < k ; ++j){
            temp *= x;
        }
        ans = max(ans , pre[i - 1] | temp | suf[i + 1]);
    }
    printf("%lld\n" , ans);
}