#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

template<class T> struct RMQ { //min range query (default)
	vector<vector<T>> st;
	vector<int> log;
	T combine(T a, T b) {return min(a, b);}
	void init(vector<T> a) {
		int n = a.size();
		log = vector<int>(n + 1);
		for (int i = 2; i <= n; ++i) log[i] = log[i >> 1] + 1;
		int k = log[n];
		st = vector<vector<T>>(n, vector<T>(k + 1));
		for (int i = 0; i < n; ++i) st[i][0] = a[i];
		for (int j = 1; j <= k; ++j) for (int i = 0; i + (1 << j) - 1 < n; ++i)
			st[i][j] = combine(st[i][j - 1], st[i + (1 << (j - 1))][j-1]);
	}
	T qry(int l, int r) {
		int k = log[r - l + 1];
		return combine(st[l][k], st[r - (1 << k) + 1][k]);
	}
};

const int mxN=1e5;
int n, q, p[mxN], d[mxN], oc[mxN], pos[mxN], npos[mxN], t;
vector<int> adj[mxN];
vector<ar<int, 2>> euler;
RMQ<ar<int, 2>> rmq1;

void dfs(int u=0) {
	pos[u]=t, npos[t]=u, oc[u]=euler.size(), ++t;
	euler.push_back({d[u], u});
	for (int v : adj[u]) {
		d[v]=d[u]+1, dfs(v);
		euler.push_back({d[u], u});
	}
}

int lca(int u, int v) {
	if ((u=oc[u])>(v=oc[v]))
		swap(u, v);
	return rmq1.qry(u, v)[1];
}

template<class T> struct RMQ2 {
	vector<vector<T>> st;
	vector<int> log;
	T combine(T a, T b) {
		return {min(a[0], b[0]), max(a[1], b[1]), lca(a[2], b[2])};
	}
	void init() {
		log = vector<int>(n + 1);
		for (int i = 2; i <= n; ++i) log[i] = log[i >> 1] + 1;
		int k = log[n];
		st = vector<vector<T>>(n, vector<T>(k + 1));
		for (int i = 0; i < n; ++i) st[i][0] = {pos[i], pos[i], i};
		for (int j = 1; j <= k; ++j) for (int i = 0; i + (1 << j) - 1 < n; ++i)
			st[i][j] = combine(st[i][j - 1], st[i + (1 << (j - 1))][j-1]);
	}
	T qry(int l, int r) {
		int k = log[r - l + 1];
		return combine(st[l][k], st[r - (1 << k) + 1][k]);
	}
};
RMQ2<ar<int, 3>> rmq2;

int lca(int l, int r, int u) {
	assert(l<=u&&u<=r);
	if (l==u)
		return rmq2.qry(l+1, r)[2];
	if (r==u)
		return rmq2.qry(l, r-1)[2];
	return lca(rmq2.qry(l, u-1)[2], rmq2.qry(u+1, r)[2]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i=1; i<n; ++i) {
		cin >> p[i], --p[i];
		adj[p[i]].push_back(i);
	}
	dfs();
	rmq1.init(euler);
	rmq2.init();
	/*
	for (int i=0; i<n; ++i) {
		cout << pos[i] << " ";
	} cout << endl;
	*/
	for (int i=0; i<q; ++i) {
		int l, r;
		cin >> l >> r, --l, --r;
		ar<int, 3> x=rmq2.qry(l, r);
		//cout << "S : " << x[0] << " " << x[1] << "\n";
		auto check=[&](int u)->ar<int, 2> {
			int a=lca(l, r, u);
			return {d[a], u};
		};
		ar<int, 2> ans=max(check(npos[x[0]]), check(npos[x[1]]));
		cout << ans[1]+1 << " " << ans[0] << "\n";
	}
	return 0;
}