#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int add(int a , int b){
    int res = a + b;
    if(res >= mod){
        return res - mod;
    }
    return res;
}
int dp[N];
int sum[N];
int t , k;
int a , b;
int main(){
    scanf("%d %d" , &t , &k);
    for(int i = 0 ; i < k ; ++i){
        dp[i] = 1;
        sum[i] = i;
    }
    for(int i = k ; i < N ; ++i){
        dp[i] = add(dp[i - 1] , dp[i - k]);
        sum[i] = add(sum[i - 1] , dp[i]);
    }
    while(t--){
        scanf("%d %d" , &a , &b);
        printf("%d\n" , add(sum[b] , mod - sum[a - 1]));
    }
}