#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=200001;
int ans=0;
struct dsu {
	int p[mxN], sze[mxN];
	set<int> tow[mxN];
	void init() {
		iota(p, p+mxN, 0);
	}
	void add(int r, int t) {
		++sze[t];
		tow[t].insert(r);
	}
	int find(int u) {
		return u==p[u]?u:p[u]=find(p[u]);
	}
	void merge(int u, int v) {
		u=find(u), v=find(v);
		assert(u!=v);
		if (sze[u]<sze[v]) swap(u, v); //v is smaller
		sze[u]+=sze[v];
		p[v]=u;
		for (const int &i : tow[v]) {
			if (tow[u].find(i-1)!=tow[u].end()) --ans;
			if (tow[u].find(i+1)!=tow[u].end()) --ans;
		}
		for (const int &i : tow[v]) {
			tow[u].insert(i);
		}
		tow[v].clear();
	}
} d;

int n, m, a[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	d.init();
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		d.add(i, a[i]);
	}
	for (int i=0; i<n-1; ++i)
		if (a[i]!=a[i+1]) ++ans;
	cout << ans << '\n';
	for (int i=1, u, v; i<m; ++i) {
		cin >> u >> v;
		d.merge(u, v);
		cout << ans << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/