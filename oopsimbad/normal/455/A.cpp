#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    ll cnt[100010];
    ll dp[100010];
    memset(cnt,0,800080);
    memset(dp,0,800080);
    for(int i = 0; i < n; i++) {
    	int ind;
    	cin >> ind;
    	cnt[ind]++;
    }
    dp[0] = 0;
    dp[1] = cnt[1];
    for(int i = 2; i < 100010; i++) {
        	dp[i] = max(dp[i-1],dp[i-2] + cnt[i] * i);
    }
    cout << dp[100009];
    //cin >> n;
    return 0;
}