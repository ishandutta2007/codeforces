#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, m, q, d1[mxN], d2[mxN], di[mxN], who[mxN], cnt;
vector<int> adj[mxN], c, cmp[mxN];
vector<ll> p[mxN];
map<ll, double> mp;

int bfs(int s, int d[]) {
	memset(d, -1, 4*n);
	d[s]=0;
	c.assign(1, s);
	for (int i=0; i<c.size(); ++i) {
		int u=c[i];
		for (int v : adj[u])
			if (d[v]==-1) {
				d[v]=d[u]+1;
				c.push_back(v);
			}
	}
	return c.back();
}

ll hsh(int a, int b) {
	++a, ++b;
	if (a>b)
		swap(a, b);
	return a*mxN+b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	cin >> n >> m >> q;
	for (int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i=0; i<n; ++i)
		if (!who[i]) {
			int s=bfs(i, d1);
			int t=bfs(s, d1);
			bfs(t, d2);
			di[cnt]=d1[t];
			for (int j : c) {
				who[j]=cnt;
				cmp[cnt].push_back(max(d1[j], d2[j]));
			}
			sort(cmp[cnt].begin(), cmp[cnt].end());
			p[cnt].resize(cmp[cnt].size()+1);
			for (int j=0; j<cmp[cnt].size(); ++j)
				p[cnt][j+1]=p[cnt][j]+cmp[cnt][j];
			++cnt;
		}
	while(q--) {
		int u, v;
		cin >> u >> v, --u, --v;
		int a=who[u], b=who[v];
		if (a==b) {
			cout << "-1\n";
			continue;
		}
		if (mp.find(hsh(a, b))!=mp.end()) {
			cout << mp[hsh(a, b)] << "\n";
			continue;
		}
		int s1=cmp[a].size(), s2=cmp[b].size();
		int c1=s1+s2, c2=3*(32-__builtin_clz(max(s1, s2)))*min(s1, s2);
		int bound=max(di[a], di[b]);
		ll tot=0;
		if (c1<=c2) { // very close in size
			ll cur=0;
			for (int i=0, j=s2; i<s1; ++i) {
				while(j&&cmp[b][j-1]+cmp[a][i]+1>bound)
					cur+=cmp[b][--j];
				tot+=(ll)j*bound;
				tot+=cur+(ll)(s2-j)*(cmp[a][i]+1);
			}
		} else { // one is much larger
			if (s1>s2)
				swap(a, b), swap(s1, s2);
			for (int i=0; i<s1; ++i) {
				int j=upper_bound(cmp[b].begin(), cmp[b].end(), bound-1-cmp[a][i])-cmp[b].begin();
				tot+=(ll)j*bound;
				tot+=p[b].back()-p[b][j]+(ll)(s2-j)*(cmp[a][i]+1);
			}
		}
		double cur=(double)tot/((ll)s1*s2);
		cout << (mp[hsh(a, b)]=cur) << "\n";
	}
	return 0;
}