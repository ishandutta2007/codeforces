#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1000;
int n, d, p[mxN], sz[mxN];

int find(int i) {
	return i^p[i]?p[i]=find(p[i]):i;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> d;
	iota(p, p+n, 0);
	fill(sz, sz+n, 1);
	multiset<int> s;
	for (int i=0; i<n; ++i)
		s.insert(1);
	int cnt=0;
	for (int i=0; i<d; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		u=find(u), v=find(v);
		if (u^v) {
			p[v]=u;
			s.erase(s.find(sz[u]));
			s.erase(s.find(sz[v]));
			sz[u]+=sz[v];
			s.insert(sz[u]);
		} else
			++cnt;
		int cur=cnt;
		int ans=-1;
		for (auto it=--s.end(); ~cur; --cur, --it)
			ans+=*it;
		cout << ans << "\n";
	}
	return 0;
}