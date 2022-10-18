#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int dist[N];

void solve() {
	int n, k;
	cin >> n >> k;
	k = min(20*n,k);
	
	vector<int> w(n), c(n);
	for (int i = 0; i < n; i++) {
		int b; cin >> b;
		w[i] = dist[b];
	}
	for (int &x: c) cin >> x;

	vector<int> dp(k+1);
	for (int i = 0; i < n; i++) {
		vector<int> ndp = dp;
		for (int j = w[i]; j <= k; j++) {
			ndp[j] = max(ndp[j], dp[j-w[i]] + c[i]);
		}
		swap(dp, ndp);
	}
	cout << dp[k] << '\n';
}

int main() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	auto consider = [&](int x, int d) {
		if (x < N) dist[x] = min(dist[x], d);
	};
	for (int x = 1; x < N; x++) {
		for (int y = 1; y <= x; y++) {
			consider(x + x/y, dist[x]+1);			
		}
	}

	int tc; cin >> tc;
	while (tc--) solve();
}