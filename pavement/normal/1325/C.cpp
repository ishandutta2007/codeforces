#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, md, mn, mprev, O[100005];
bool done = 0;
vector<pair<int, int> > adj[100005];

void dfs(int n, int e, int d, int prev) {
	if (d >= md) {
		md = d;
		mn = n;
		mprev = prev;
	}
	for (auto u : adj[n])
		if (u.first != e)
			dfs(u.first, n, d + 1, u.second);
}

bool find(int n, int e) {
	if (done) return 1;
	if (n == mn) return 1;
	bool can = 0;
	for (auto u : adj[n]) {
		if (u.first != e) {
			if (!find(u.first, n)) {
				done = 1;
				O[u.second] = 3;
				return 1;
			} else can = 1;
			if (done) return 1;
		}
	}
	return can;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0, u, v; i < N - 1; i++) {
		cin >> u >> v;
		adj[u].emplace_back(v, i);
		adj[v].emplace_back(u, i);
	}
	if (N == 2) {
		cout << "0\n";
		return 0;
	}
	dfs(1, -1, 0, N);
	int first = mn;
	md = 0;
	O[mprev] = 1;
	dfs(mn, -1, 0, N);
	O[mprev] = 2;
	find(first, -1);
	if (done) {
		for (int i = 0, nxt = 3; i < N - 1; i++) {
			if (!O[i]) cout << nxt++ << '\n';
			else cout << O[i] - 1 << '\n';
		}
	} else {
		for (int i = 0; i < N - 1; i++) cout << i << '\n';
	}
}