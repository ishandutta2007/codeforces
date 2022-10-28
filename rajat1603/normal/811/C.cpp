#include "bits/stdc++.h"
using namespace std;
const int N = 5e3 + 3;
int n;
int arr[N];
int idx1[N];
int idx2[N];
int dp[N];
int lst[N];
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        idx2[arr[i]] = i;
    }
    for(int i = n ; i >= 1 ; --i){
        idx1[arr[i]] = i;
    }
    dp[n + 1] = 0;
    for(int i = n ; i >= 1 ; --i){
        int mx = i;
        int cur = 0;
        dp[i] = dp[i + 1];
        for(int j = i ; j <= n ; ++j){
            if(idx1[arr[j]] < i){
                break;
            }
            if(lst[arr[j]] != i){
                cur ^= arr[j];
                lst[arr[j]] = i;
            }
            mx = max(mx , idx2[arr[j]]);
            if(mx <= j){
                dp[i] = max(dp[i] , cur + dp[j + 1]);
            }
        }
    }
    printf("%d\n" , dp[1]);
}