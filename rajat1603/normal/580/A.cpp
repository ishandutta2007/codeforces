#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int arr[N];
int dp[N];
int n;
int ans = 1;
int main(){
    cin >> n;
    arr[0] = -1;
    dp[0] = 0;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
        if(arr[i] >= arr[i - 1]){
            dp[i] = dp[i - 1] + 1;
        }
        else{
            dp[i] = 1;
        }
        ans = max(ans , dp[i]);
    }
    cout << ans;
}