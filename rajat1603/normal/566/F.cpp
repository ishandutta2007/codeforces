#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n;
int arr[N], dp[N];
int ans = 0;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &arr[i]);
    }
    for(int i = n ; i >= 1 ; --i){
        dp[arr[i]] = 1;
        for(int j = arr[i] + arr[i] ; j < N ; j += arr[i]){
            dp[arr[i]] = max(dp[arr[i]] , dp[j] + 1);
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        ans = max(ans , dp[arr[i]]);
    }
    printf("%d" , ans);
}