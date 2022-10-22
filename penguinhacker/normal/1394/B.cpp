#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=200001, P=37, MOD=1e9+9;
int n, m, k, val[mxN]; //hash val for each number 1-n
vector<pair<int, int>> adj[mxN];
int c[10][10];
ll need=0;

int ans=0;
void rec(int x=1, int sum=0) {
	if (x==k+1) {
		if (sum==need) ++ans;
		return;
	}
	for (int i=0; i<x; ++i)
		rec(x+1, (sum+c[x][i])%MOD);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i=0; i<m; ++i) {
		int a, b, w; cin >> a >> b >> w;
		adj[a].emplace_back(w, b);
	}
	ll pp=1;
	for (int i=1; i<=n; ++i) {
		val[i]=(i)*pp%MOD;
		need=(need+val[i])%MOD;
		pp=pp*P%MOD;
	}
	for (int i=1; i<=n; ++i) {
		sort(adj[i].begin(), adj[i].end());
		int s=adj[i].size();
		for (int j=0; j<s; ++j)
			c[s][j]=(c[s][j]+val[adj[i][j].second])%MOD;
	}
	rec();
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/