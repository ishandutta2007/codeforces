#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
int n, m, x, p[mxN], eu[mxN], ev[mxN];
ll a[mxN];
set<int> adj[mxN];
set<ar<ll, 2>> s;

int find(int i) {
	return i^p[i]?p[i]=find(p[i]):i;
}

bool merge(int u, int v, int i) {
	assert(u^v);
	//if (u==v) return 0;
	if (adj[u].size()<adj[v].size())
		swap(u, v);
	adj[u].erase(i), adj[v].erase(i);
	for (const int& x : adj[v])
		adj[u].insert(x);
	p[v]=u;
	a[u]+=a[v]-x;
	assert(a[u]>=0);
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> x;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	if (accumulate(a, a+n, 0ll)<(ll)x*(n-1)) {
		cout << "NO\n";
		return 0;
	}
	for (int i=0; i<m; ++i) {
		cin >> eu[i] >> ev[i], --eu[i], --ev[i];
		adj[eu[i]].insert(i);
		adj[ev[i]].insert(i);
	}
	cout << "YES\n";
	for (int i=0; i<n; ++i)
		s.insert({a[i], i});
	iota(p, p+n, 0);
	while(s.size()>1) {
		/*for (const auto& x : s) {
			cout << x[0] << " " << x[1] << endl;
		}*/
		int u=(*s.rbegin())[1];
		assert(!adj[u].empty());
		int e, v;
		while(1) {
			e=*adj[u].begin();
			v=u^find(eu[e])^find(ev[e]);
			if (find(v)==u) {
				adj[u].erase(adj[u].begin());
				continue;
			}
			break;
		}
		v=find(v);
		//cout << u << " " << v << " " << e << endl << endl;
		s.erase({a[u], u});
		s.erase({a[v], v});
		merge(u, v, e);
		s.insert({a[find(u)], find(u)});
		cout << e+1 << "\n";
	}
	return 0;
}