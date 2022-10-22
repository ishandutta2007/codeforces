#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, m, q, p[mxN], n2, id[mxN], tin[mxN];
vector<int> adj[mxN];
vector<ar<int, 2>> stk;

int find(int i) {
	return i^p[i]?p[i]=find(p[i]):i;
}

void dfs(int u, int d) {
	tin[u]=stk.size();
	stk.push_back({d, u});
	for (int v : adj[u]) {
		dfs(v, d+1);
		stk.push_back({d, u});
	}
}

struct {
	vector<vector<ar<int, 2>>> st;
	void init(vector<ar<int, 2>> a) {
		int n=a.size();
		st={a};
		for (int i=1; (1<<i)<=n; ++i) {
			st.push_back(vector<ar<int, 2>>(n-(1<<i)+1));
			for (int j=0; j+(1<<i)-1<n; ++j)
				st[i][j]=min(st[i-1][j], st[i-1][j+(1<<i-1)]);
		}
	}
	ar<int, 2> qry(int l, int r) {
		int k=31-__builtin_clz(r-l+1);
		return min(st[k][l], st[k][r-(1<<k)+1]);
	}
} lca_tree;

int lca(int u, int v) {
	return lca_tree.qry(min(tin[u], tin[v]), max(tin[u], tin[v]))[1];
}

struct {
	vector<vector<int>> st;
	void init(vector<int> a) {
		int n=a.size();
		st={a};
		for (int i=1; (1<<i)<=n; ++i) {
			st.push_back(vector<int>(n-(1<<i)+1));
			for (int j=0; j+(1<<i)-1<n; ++j)
				st[i][j]=lca(st[i-1][j], st[i-1][j+(1<<i-1)]);
		}
	}
	int qry(int l, int r) {
		int k=31-__builtin_clz(r-l+1);
		return lca(st[k][l], st[k][r-(1<<k)+1]);
	}
} rmq;

void solve() {
	cin >> n >> m >> q;
	iota(p, p+2*n, 0);
	n2=n;
	for (int i=0; i<2*n; ++i)
		adj[i].clear();
	for (int i=1; i<=m; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		u=find(u), v=find(v);
		if (u!=v) {
			p[u]=p[v]=n2;
			adj[n2].push_back(u);
			adj[n2].push_back(v);
			id[n2]=i;
			++n2;
		}
	}
	assert(n2==2*n-1);
	stk.clear();
	dfs(n2-1, 0);
	lca_tree.init(stk);
	vector<int> perm(n);
	iota(perm.begin(), perm.end(), 0);
	rmq.init(perm);
	while(q--) {
		int l, r;
		cin >> l >> r, --l, --r;
		if (l==r) {
			cout << "0 ";
			continue;
		}
		cout << id[rmq.qry(l, r)] << " ";
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}