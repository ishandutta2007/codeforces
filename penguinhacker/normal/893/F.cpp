#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

//#warning change B
const int mxN=1e5, B=2*400;
int n, m, r, a[mxN], tl[mxN], dp[mxN][B], jmp[mxN], d[mxN], p[mxN];
vector<int> adj[mxN];

void dfs1(int u=r) {
	dp[u][0]=a[u];
	vector<int> nadj;
	for (int v : adj[u]) {
		adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
		dfs1(v);
		tl[u]=max(tl[u], tl[v]+1);
		for (int i=1; i<B&&i<=tl[v]+1; ++i)
			dp[u][i]=min(dp[u][i], dp[v][i-1]);
		if (tl[v]>=B/2-1)
			nadj.push_back(v);
	}
	for (int i=1; i<B&&i<=tl[u]; ++i)
		dp[u][i]=min(dp[u][i], dp[u][i-1]);
	swap(adj[u], nadj);
}

void dfs2(int u=r) {
	for (int v : adj[u])
		p[v]=u, dfs2(v);
	if (adj[u].size()!=1) {
		jmp[u]=u, d[u]=0;
		return;
	}
	int v=adj[u][0];
	if (d[v]==B/2) {
		d[u]=B/2, jmp[u]=p[jmp[v]];
	} else {
		d[u]=d[v]+1, jmp[u]=jmp[v];
	}
}

int solve(int u, int k) {
	//cout << u << " " << k << endl;
	if (k<B||adj[u].empty())
		return dp[u][min(k, tl[u])];
	int r=dp[u][min(tl[u], B-1)];
	if (jmp[u]==u) {
		for (int v : adj[u])
			r=min(r, solve(v, k-1));
	} else {
		r=min(r, solve(jmp[u], k-d[u]));
	}
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> r, --r;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(dp, 0x3f, sizeof(dp));
	dfs1();
	dfs2();
	/*for (int i=0; i<n; ++i) {
		cout << i << " : ";
		for (int j : adj[i])
			cout << j << " ";
		cout << endl;
	}*/
	/*cout << endl << endl;
	for (int i=0; i<n; ++i) {
		cout << jmp[i] << " " << d[i] << endl;
	}*/
	int ans=0;
	cin >> m;
	while(m--) {
		int p, q;
		cin >> p >> q;
		int u=(p+ans)%n, k=(q+ans)%n;
		//cout << u << " " << k << endl;
		ans=solve(u, k);
		cout << ans << "\n";
	}
	return 0;
}