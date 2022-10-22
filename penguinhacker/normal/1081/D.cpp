#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

ll n, m, k;
vector<ar<int, 3>> e;

struct dsu {
	int p[100001], cnt[100001]; //cnt is number of special vertices in that region
	dsu() {
		iota(p, p+100001, 0);
	}
	int find(int u) {
		return p[u]==u?u:p[u]=find(p[u]);
	}
	void join(int u, int v, int w) {
		u=find(u), v=find(v);
		if (u==v)
			return;
		p[v]=u, cnt[u]+=cnt[v];
		if (cnt[u]==k) { //print answer and exit
			for (int i=0; i<k; ++i)
				cout << w << ' ';
			exit(0);
		}
	}
} d;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i=0, a; i<k; ++i)
		cin >> a, d.cnt[a]=1;
	for (int i=0, u, v, w; i<m; ++i) {
		cin >> u >> v >> w;
		e.push_back({u, v, w});
	}
	sort(e.begin(), e.end(), [](ar<int, 3> a1, ar<int, 3> a2) {return a1[2]<a2[2];});
	for (int i=0; i<m; ++i)
		d.join(e[i][0], e[i][1], e[i][2]);
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/