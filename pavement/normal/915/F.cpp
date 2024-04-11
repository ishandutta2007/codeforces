#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, ma, mi, link[1000005], sz[1000005];
bool P[1000005];
vector<int> adj[1000005];
pair<int, int> A[1000005];

int find(int x) {
	if (x == link[x]) return x;
	return link[x] = find(link[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (sz[b] > sz[a]) swap(a, b);
	sz[a] += sz[b];
	link[b] = a;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i].first;
		ma += A[i].first;
		mi += A[i].first;
		A[i].second = i;
		link[i] = i;
		sz[i] = 1;
	}
	for (int i = 0, u, v; i < N - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	sort(A + 1, A + 1 + N);
	for (int i = 1; i <= N; i++) {
		for (int u : adj[A[i].second])
			if (P[u]) {
				ma += sz[find(u)] * sz[find(A[i].second)] * A[i].first;
				unite(A[i].second, u);
			}
		P[A[i].second] = 1;
	}
	reverse(A + 1, A + 1 + N);
	memset(P, 0, sizeof P);
	for (int i = 1; i <= N; i++) {
		link[i] = i;
		sz[i] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int u : adj[A[i].second])
			if (P[u]) {
				mi += sz[find(u)] * sz[find(A[i].second)] * A[i].first;
				unite(A[i].second, u);
			}
		P[A[i].second] = 1;
	}
	cout << ma - mi << '\n';
}