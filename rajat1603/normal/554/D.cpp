#include "bits/stdc++.h"
using namespace std;
long long dp[1 << 6] = {1 , 1} , k;
int n;
int main(){
    cin >> n >> k;
    for(int i = 2 ; i <= n ; ++i){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    for(int i = 1 ; i <= n ; ++i , cout << " "){
        if(dp[n - i] >= k){
            cout << i;
        }
        else{
            cout << i << " " << i++;
            k -= dp[n - i + 1];
        }
    }
}