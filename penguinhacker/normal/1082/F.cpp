#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int INF=1e9;
int n, m=1, k, ans, c[501][26], cnt[501], dp[501][11], dp2[501][11], dp3[501][11];

void mrg(int* a, int* b) { // merge b into a
	for (int i=k; ~i; --i)
		for (int j=k-i; ~j; --j)
			a[i+j]=max(a[i+j], a[i]+b[j]);
}

void dfs2(int u, int d) {
	fill(dp2[u]+1, dp2[u]+k+1, -INF);
	for (int i=0; i<10; ++i) {
		if (!c[u][i])
			continue;
		int v=c[u][i];
		dfs2(v, d);
		mrg(dp2[u], dp2[v]);
	}
	for (int i=0; i<=k; ++i)
		dp2[u][i]=max(dp2[u][i], dp[u][i]-d*cnt[u]);
}

void dfs(int u=0, int d=0) {
	fill(dp2[u]+1, dp2[u]+k+1, -INF);
	for (int i=0; i<10; ++i) {
		if (!c[u][i])
			continue;
		int v=c[u][i];
		dfs(v, d+1);
		dfs2(v, d);
		mrg(dp2[u], dp2[v]);
	}
	for (int i=1; i<=k; ++i)
		dp[u][i]=max(dp2[u][i-1]+d*cnt[u], -INF);
}

void dfs3(int u=0) {
	fill(dp3[u]+1, dp3[u]+k+1, -INF);
	for (int i=0; i<10; ++i) {
		if (!c[u][i])
			continue;
		int v=c[u][i];
		dfs3(v);
		mrg(dp3[u], dp3[v]);
	}
	for (int i=0; i<=k; ++i)
		dp3[u][i]=max(dp3[u][i], dp[u][i]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		string s;
		int x;
		cin >> s >> x;
		ans+=x*s.size();
		int u=0;
		for (char d : s) {
			if (!c[u][d-'0'])
				c[u][d-'0']=m++;
			u=c[u][d-'0'];
			cnt[u]+=x;
		}
	}
	dfs();
	dfs3();
	/*for (int i=0; i<m; ++i) {
		cout << "Node: " << i << "  :  ";
		for (int j=1; j<=k; ++j)
			cout << " " << dp[i][j];
		cout << "\n";
	}*/
	cout << ans-*max_element(dp3[0], dp3[0]+k+1);
	return 0;
}