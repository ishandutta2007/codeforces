#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, d[N], z[N], c[N], q[N << 1], l, r, u, v;
vector<int> G[N], a[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> d[i], d[i] ? q[r++] = i : 0;
	for(int i = 1; i < n; i++) cin >> u >> v, G[--u].push_back(--v), G[v].push_back(u);
	while(l < r) for(int v : G[u = q[l++]]) if(!d[v]) d[q[r++] = v] = d[u] + 1;
	for(int u = 0; u < n; u++) for(int v : G[u]) if(d[u] == d[v]) { a[d[u]].push_back(u); break; }
	memset(c, 63, sizeof c);
	for(int i = n; i; i--) if(a[i].size()) {
		l = r = 0, memset(z, 63, sizeof z);
		for(int u : a[i]) z[q[r++] = u] = 0;
		while(l < r) for(int v : G[u = q[l++]]) if(d[v] >= d[u]) if(int w = max(z[u] + (d[v] > d[u] ? -1 : 1), 0); w < z[v]) z[q[r++] = v] = w;
		for(int u = 0; u < n; u++) if(!z[u]) c[u] = i;
	}
	for(int i = 0; i < n; i++) cout << d[i] * 2 - min(d[i], c[i]) - 1 << ' ';
}