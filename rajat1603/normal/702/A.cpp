#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int arr[N];
int dp[N];
int ans;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    dp[0] = 0;
    ans = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(arr[i] > arr[i - 1]){
            dp[i] = dp[i - 1] + 1;
        }
        else{
            dp[i] = 1;
        }
        ans = max(ans , dp[i]);
    }
    cout << ans;
}