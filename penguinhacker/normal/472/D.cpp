#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2000;
int n, cnt, a[mxN][mxN], p[mxN];
vector<ar<int, 3>> e;
vector<ar<int, 2>> adj[mxN];

int find(int i) {
	return i^p[i]?p[i]=find(p[i]):i;
}

bool merge(int u, int v) {
	if (u==v)
		return 0;
	p[v]=u;
	return 1;
}

void dfs(int u, int p, int r, ll d) {
	if (a[r][u]^d) {
		//cout << r << " " << u << " " << d << endl;
		cout << "NO";
		exit(0);
	}
	for (ar<int, 2> v : adj[u])
		if (v[0]^p)
			dfs(v[0], u, r, d+v[1]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j) {
			cin >> a[i][j];
			if (i<j&&a[i][j])
				e.push_back({a[i][j], i, j});
		}
	sort(e.begin(), e.end());
	iota(p, p+n, 0);
	for (ar<int, 3> x : e) {
		int u=find(x[1]), v=find(x[2]);
		if (merge(u, v)) {
			++cnt;
			adj[x[1]].push_back({x[2], x[0]});
			adj[x[2]].push_back({x[1], x[0]});
			//cout << x[1] << " " << x[2] << endl;
		}
	}
	if (cnt^n-1) {
		cout << "NO";
		return 0;
	}
	for (int i=0; i<n; ++i)
		dfs(i, -1, i, 0);
	cout << "YES";
	return 0;
}