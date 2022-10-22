#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1000;
int n, max_d;
vector<int> adj[mxN], at[mxN];

ar<int, 2> qry(vector<int> c) {
	cout << "? " << c.size();
	for (int i : c)
		cout << " " << i+1;
	cout << endl;
	int x, y;
	cin >> x >> y;
	return {x-1, y};
}

void dfs(int u, int p=-1, int d=0) {
	max_d=max(max_d, d);
	at[d].push_back(u);
	for (int v : adj[u])
		if (v^p)
			dfs(v, u, d+1);
}

void root(int u) {
	max_d=0;
	for (int i=0; i<n; ++i)
		at[i].clear();
	dfs(u);
}

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		adj[i].clear();
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> all(n);
	iota(all.begin(), all.end(), 0);
	ar<int, 2> t=qry(all);
	int u=t[0], d=t[1];
	root(u);
	int lb=1, rb=min(max_d, d);
	while(lb<rb) {
		int mid=(lb+rb+1)/2;
		if (qry(at[mid])[1]==d)
			lb=mid;
		else
			rb=mid-1;
	}
	u=qry(at[lb])[0];
	root(u);
	int v=qry(at[d])[0];
	cout << "! " << u+1 << " " << v+1 << endl;
	string good;
	cin >> good;
	if (good=="Incorrect")
		exit(0);
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