#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
 
	vector<int> dp(n+1);
	vector<int> ip;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i-1];
 
		for (int f = max(0LL, (int)ip.size() - 3); f < ip.size(); f++) {
			int j = ip[f];
 
			dp[i] = max(dp[i], dp[j] + abs(a[i] - a[j+1]));
			dp[i] = max(dp[i], dp[j-1] + abs(a[i] - a[j]));
		}
 
		if (i == 1 || i == n) {
			ip.push_back(i);
		} else if (a[i] >= a[i-1] && a[i] >= a[i+1]) {
			ip.push_back(i);
		} else if (a[i] <= a[i-1] && a[i] <= a[i+1]){
			ip.push_back(i);
		}
	}
	cout << dp[n] << '\n';
 
	return 0;
}