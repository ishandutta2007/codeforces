#include "bits/stdc++.h"
using namespace std;
const int N = 5e3 + 3;
const long long linf = 1e16;
int n , m , k;
long long arr[N];
long long dp[N][N];
long long solve(int pos , int k){
    if(pos > n - m + 1){
        if(!k){
            return 0;
        }
        else{
            return -linf;
        }
    }
    if(dp[pos][k] != -1){
        return dp[pos][k];
    }
    return dp[pos][k] = max(solve(pos + 1 , k) , arr[pos + m - 1] - arr[pos - 1] + solve(pos + m , k - 1));
}
int main(){
    cin >> n >> m >> k;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    memset(dp , -1 , sizeof(dp));
    cout << solve(1 , k);
}