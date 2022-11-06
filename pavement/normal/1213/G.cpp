#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, M, u, v, w, idx, p, link[200005], sz[200005], a[200005];
pair<int, int> q[200005];
tuple<int, int, int> ed[200005];

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
	cin >> N >> M;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v >> w;
		ed[i] = make_tuple(w, u, v);
	}
	for (int i = 1; i <= N; i++) link[i] = i, sz[i] = 1;
	sort(ed, ed + N - 1);
	for (int i = 0; i < M; i++) cin >> q[i].first, q[i].second = i;
	sort(q, q + M);
	for (int i = 0; i < M; i++) {
		while (idx < N - 1 && get<0>(ed[idx]) <= q[i].first) {
			p += sz[find(get<1>(ed[idx]))] * sz[find(get<2>(ed[idx]))];
			unite(get<1>(ed[idx]), get<2>(ed[idx]));
			idx++;
		}
		a[q[i].second] = p;
	}
	for (int i = 0; i < M; i++) cout << a[i] << ' ';
	cout << '\n';
}