#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
const int mxN=5001;

int n, m, a[3], col[mxN], dp[mxN][mxN];
vector<int> adj[mxN], cur;
vector<vector<int>> cmp;

void dfs(int u, int c=0) {
	cur.push_back(u);
	col[u]=c;
	for (int v : adj[u]) {
		if (col[v]==-1) {
			dfs(v, c^1);
		}
		else {
			if (col[u]==col[v]) {
				cout << "NO";
				exit(0);
			}
		}
	}
}

int ck(const vector<int> &v, int x) {
	int cnt=0;
	for (int i : v)
		cnt+=col[i]==x;
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> a[0] >> a[1] >> a[2];
	for (int i=0, u, v; i<m; ++i) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	fill(begin(col), end(col), -1);
	for (int i=0; i<n; ++i)
		if (col[i]==-1) {
			dfs(i);
			cmp.push_back(cur);
			cur.clear();
		}
	for (int i=0; i<mxN; ++i)
		for (int j=0; j<mxN; ++j)
			dp[i][j]=-1;
	for (int i=0; i<cmp.size(); ++i) {
		vector<int> &v=cmp[i];
		int x=ck(v, 0);
		if (i==0) {
			dp[0][x]=0;
			dp[0][v.size()-x]=1;
		}
		else {
			for (int j=0; j<=n; ++j)
				if (dp[i-1][j]!=-1) {
					//cout << j+x << ' ' << j+v.size()-x << '\n';
					dp[i][j+x]=0;
					dp[i][j+v.size()-x]=1;
				}
		}
	}
	if (dp[cmp.size()-1][a[1]]==-1) {
		cout << "NO";
		return 0;
	}
	for (int i=cmp.size()-1; ~i; --i) {
		int x=dp[i][a[1]];
		a[1]-=ck(cmp[i], x);
		for (int j : cmp[i]) {
			int k=col[j]^x;
			if (k==0)
				col[j]=2;
			else {
				if (a[0]>0) {
					--a[0];
					col[j]=1;
				}
				else
					col[j]=3;
			}
		}
	}
	cout << "YES\n";
	for (int i=0; i<n; ++i)
		cout << col[i];
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/