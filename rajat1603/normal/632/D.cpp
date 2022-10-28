#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n , m;
int arr[N];
int dp[N];
int cnt[N];
int idx;
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        if(arr[i] <= m){
            ++cnt[arr[i]];
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        for(int j = i ; j <= m ; j += i){
            dp[j] += cnt[i];
        }
    }
    idx = max_element(dp + 1 , dp + 1 + m) - dp;
    printf("%d %d\n" , idx , dp[idx]);
    for(int i = 1 ; i <= n ; ++i){
        if(idx % arr[i] == 0){
            printf("%d " , i);
        }
    }
}