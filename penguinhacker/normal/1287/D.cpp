#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2000;
int n, p[mxN], c[mxN], rt, ans[mxN];
vector<int> adj[mxN], b[mxN];

void dfs(int u=rt) {
	for (int v : adj[u]) {
		dfs(v);
		if (b[v].size()>b[u].size())
			swap(b[u], b[v]);
		b[u].insert(b[u].end(), b[v].begin(), b[v].end());
		vector<int>().swap(b[v]);
	}
	if (c[u]>b[u].size()) {
		cout << "NO";
		exit(0);
	}
	b[u].insert(b[u].begin()+c[u], u);
	/*cout << u << " : ";
	for (int i : b[u])
		cout << i << " ";
	cout << endl;*/
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> p[i] >> c[i], --p[i];
		if (~p[i])
			adj[p[i]].push_back(i);
		else
			rt=i;
	}
	dfs();
	cout << "YES\n";
	assert(b[rt].size()==n);
	for (int i=0; i<n; ++i)
		ans[b[rt][i]]=i+1;
	for (int i=0; i<n; ++i)
		cout << ans[i] << " ";
	return 0;
}