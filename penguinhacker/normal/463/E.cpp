#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, q, ans[100000], dep[100000];
vector<int> adj[100000], d[100000];

void factor(int x, vector<int> &v) {
	for (int i=2; i*i<=x; ++i) {
		bool b=0;
		while(x%i==0) {
			b=1;
			x/=i;
		}
		if (b) v.push_back(i);
	}
	if (x>1) v.push_back(x);
}

const int mxP=2e6;
vector<int> oc[mxP];
void dfs(int u=0, int p=-1, int depth=0) {
	dep[u]=depth;
	ans[u]=-1;
	for (int i: d[u]) {
		if (oc[i].size()) {
			if (ans[u]==-1||dep[oc[i].back()]>dep[ans[u]])
				ans[u]=oc[i].back();
		}
		oc[i].push_back(u);
	}
	for (int v: adj[u]) if (v!=p)
		dfs(v, u, depth+1);
	for (int i: d[u])
		oc[i].pop_back();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for (int i=0; i<n; ++i) {
		int a; cin >> a;
		factor(a, d[i]);
	}
	for (int i=1; i<n; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs();
	while(q--) {
		int type; cin >> type;
		if (type==1) {
			int u; cin >> u, --u;
			cout << (ans[u]==-1?-1:ans[u]+1) << '\n';
		}
		else {
			int a, b; cin >> a >> b, --a;
			d[a].clear();
			factor(b, d[a]);
			dfs();
		}
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/