#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n;
int arr[N];
long long dp[N];
long long solve(int pos){
    if(pos > n){
        return 1LL;
    }
    if(dp[pos] != -1){
        return dp[pos];
    }
    long long res = 0;
    int ok = 0;
    for(int i = pos ; i <= n ; ++i){
        ok += arr[i];
        if(ok == 1){
            res += solve(i + 1);
        }
    }
    return dp[pos] = res;
}
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    memset(dp , -1 , sizeof(dp));
    cout << solve(1);
}