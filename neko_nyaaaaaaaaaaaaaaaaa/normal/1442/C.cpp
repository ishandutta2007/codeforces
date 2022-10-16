#include <bits/stdc++.h>
using namespace std;
 
const long long M = 998244353;
const long long INF = 1e18;
long long ans = INF;
 
void solve1(int n, int m, vector<pair<int, int>> edges) {
	vector<vector<int>> g(n), gr(n);
	for (auto [u, v]: edges) {
		g[u].push_back(v);
		gr[v].push_back(u);
	}
 
	priority_queue<pair<long long, pair<int, int>>> pq;
	vector<long long> dist(n*17, INF);
 
	pq.push({0, {0, 0}});
	dist[0] = 0;
 
	while (pq.size()) {
		auto [w, p] = pq.top();
		auto [now, l] = p;
		pq.pop();
 
		if (l % 2 == 0) {
			for (auto u: g[now]) {
				if (dist[now + l*n] + 1 < dist[u + l*n]) {
					dist[u + l*n] = dist[now + l*n] + 1;
					pq.push({-dist[u + l*n], {u, l}});
				}
			}
		} else {
			for (auto u: gr[now]) {
				if (dist[now + l*n] + 1 < dist[u + l*n]) {
					dist[u + l*n] = dist[now + l*n] + 1;
					pq.push({-dist[u + l*n], {u, l}});
				}
			}
		}
		
		if (l+1 < 17 && dist[now + l*n] + (1 << l) < dist[now + l*n + n]) {
			dist[now + l*n + n] = dist[now + l*n] + (1 << l);
			pq.push({-dist[now + l*n + n], {now, l+1}});
		}
	}
 
	for (int i = 0; i < 17; i++) {
		ans = min(ans, dist[i*n + n-1]);
		//cout << i << ' ' << dist[i*n + n-1] << '\n';
	}
 
	if (ans != INF) {
		cout << ans % M << '\n'; exit(0);
	}
}
 
long long p2(int n) {
	long long ans = 1;
	for (int i = 0; i < n; i++) {
		ans = (ans*2) % M;
	}
	return ans-1;
}
 
void solve2(int n, int m, vector<pair<int, int>> edges) {
	// transpositions are incredibly expensive
	vector<vector<pair<int, long long>>> g(n*2);
	for (int i = 0; i < 2; i += 2) {
		for (auto [u, v]: edges) {
			g[i*n + u].emplace_back(i*n + v, 1);
		}
	}
	for (int i = 1; i < 2; i += 2) {
		for (auto [u, v]: edges) {
			g[i*n + v].emplace_back(i*n + u, 1);
		}
	}
	for (int i = 0; i+1 < 2; i++) {
		for (int j = 0; j < n; j++) {
			g[i*n + j].emplace_back((i+1)*n + j, 1000000000);
			g[(i+1)*n + j].emplace_back(i*n + j, 1000000000);
		}
	}
 
	priority_queue<pair<long long, int>> pq;
	vector<long long> dist(n*2, INF);
 
	pq.push({0, 0});
	dist[0] = 0;
 
	while (pq.size()) {
		auto [w, now] = pq.top();
		pq.pop();
 
		for (auto u: g[now]) {
			if (dist[now] + u.second < dist[u.first]) {
				dist[u.first] = dist[now] + u.second;
				pq.push({-dist[u.first], u.first});
			}
		}
	}
 
	long long ansf = INF;
	for (int i = 0; i < 2; i++) {
		ansf = min(ansf, dist[i*n + n-1]);
	}
 
	long long trans = ansf/1000000000;
	long long edgec = ansf % 1000000000;
 
	ans = (edgec + p2(trans)) % M;
	cout << ans << '\n';
}
 
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
 
	int n, m; cin >> n >> m;
	vector<pair<int, int>> edges;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; u--; v--;
		edges.emplace_back(u, v);
	}
 
	solve1(n, m, edges);
	solve2(n, m, edges);
 
	return 0;
}