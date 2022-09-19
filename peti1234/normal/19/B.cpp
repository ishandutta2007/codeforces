#include <bits/stdc++.h>

using namespace std;
long long dp[2005], n;
int main() {
	cin >> n;
	for (int i=1; i<=n; i++) {
        dp[i]=1e18;
	}
	for (int i=1; i<=n; i++) {
        long long t, c;
        cin >> t >> c;
        t=min(t+1, n);
        for (int i=n; i>=0; i--) {
            int s=min(n, i+t);
            dp[s]=min(dp[s], dp[i]+c);
        }
	}
	cout << dp[n] << "\n";
	return 0;
}