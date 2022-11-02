#include <bits/stdc++.h>
using namespace std;
vector<long long> dp;

const long long M = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    long long ans = 0;

    int a[n];

    dp.resize(1000005);
    fill(dp.begin(), dp.end(), 0);
    dp[0] = 1;

    for(int i = 0; i<n; i++){
        cin >> a[i];


        for(int j = 1000; j>=1; j--){
            if((a[i] % j) == 0 && (j*j) <= a[i]){
                if((j*j) != a[i]){
                    dp[a[i] / j] += dp[a[i] / j - 1];
                    dp[a[i] / j] %= M;
                }

                dp[j] += dp[j - 1];
                dp[j] %= M;


            }
        }

    }

    for(int i = 1; i<n + 1; i++){
        ans += dp[i];
        ans %= M;
    }

    cout << ans;



}