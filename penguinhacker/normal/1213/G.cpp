#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

ll curr=0;

ll get(int k) {
	return 1ll*k*(k-1)/2;
}

struct dsu {
	int p[200000], sze[200000];
	dsu() {
		iota(p, p+200000, 0);
		fill(sze, sze+200000, 1);
	}
	int find(int u) {return p[u]==u?u:p[u]=find(p[u]);}
	void join(int u, int v) {
		u=find(u), v=find(v);
		assert(u!=v);
		curr+=get(sze[u]+sze[v])-get(sze[u])-get(sze[v]);
		p[v]=u, sze[u]+=sze[v];
	}
} d;

ll n, q, ans[200000];
vector<ar<int, 3>> e;
ar<int, 2> qry[200000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for (int i=0, u, v, w; i<n-1; ++i) {
		cin >> u >> v >> w, --u, --v;
		e.push_back({u, v, w});
	}
	sort(e.begin(), e.end(), [](ar<int, 3> a1, ar<int, 3> a2) {return a1[2]>a2[2];});
	for (int i=0; i<q; ++i)
		cin >> qry[i][0], qry[i][1]=i;
	sort(qry, qry+q);
	for (int i=0; i<q; ++i) {
		while(!e.empty()&&e.back()[2]<=qry[i][0]) {
			d.join(e.back()[0], e.back()[1]);
			e.pop_back();
		}
		ans[qry[i][1]]=curr;
	}
	for (int i=0; i<q; ++i)
		cout << ans[i] << ' ';
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/