#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, M, K, P[200005], diste[200005];
queue<pair<int, int> > Q;
vector<int> adj[200005], nadj[200005];
bool MT[200005];

main() {
	memset(diste, 127, sizeof diste);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int u, v; M--; ) {
		cin >> u >> v;
		adj[u].push_back(v);
		nadj[v].push_back(u);
	}
	cin >> K;
	for (int i = 1; i <= K; i++) cin >> P[i];
	Q.emplace(P[K], 0);
	diste[P[K]] = 0;
	while (!Q.empty()) {
		auto ii = Q.front();
		Q.pop();
		if (diste[ii.first] ^ ii.second) continue;
		for (auto u : nadj[ii.first]) {
			if (diste[u] > ii.second + 1) {
				MT[u] = 0;
				diste[u] = ii.second + 1;
				Q.emplace(u, diste[u]);
			} else if (diste[u] == ii.second + 1) MT[u] = 1;
		}
	}
	M = 0;
	for (int i = 2; i <= K; i++)
		if (diste[P[i]] != diste[P[i - 1]] - 1)
			M++;
	cout << M << ' ';
	M = 0;
	for (int i = 2; i <= K; i++)
		if (MT[P[i - 1]] || diste[P[i]] != diste[P[i - 1]] - 1) M++;
	cout << M << '\n';
}