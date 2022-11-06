#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, K;
bool O[300005];
vector<int> adj[300005];

int dp(int n) {
	if (adj[n].size() == 0) return 1;
	if (O[n]) {
		int r = 1e9;
		for (auto u : adj[n]) r = min(r, dp(u));
		return r;
	} else {
		int r = 0;
		for (auto u : adj[n]) r += dp(u);
		return r;
	}
}

main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> O[i];
	for (int i = 2, Y; i <= N; i++) {
		cin >> Y;
		adj[Y].push_back(i);
	}
	for (int i = 1; i <= N; i++) K += !adj[i].size();
	cout << K - dp(1) + 1 << '\n';
}