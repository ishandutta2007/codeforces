#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
const int mxN=1000;
int n, m, a[mxN][mxN], ans[mxN][mxN], p[mxN*mxN], s[mxN*mxN], cnt, cur;
ll k;
ar<int, 3> ord[mxN*mxN];
bool vis[mxN][mxN];

int find(int i) {
	return i^p[i]?p[i]=find(p[i]):i;
}

void merge(int u, int v) {
	u=find(u), v=find(v);
	if (u==v)
		return;
	if (s[u]<s[v])
		swap(u, v);
	p[v]=u, s[u]+=s[v];
}

void dfs(int i, int j) {
	++cnt, vis[i][j]=1, ans[i][j]=cur;
	for (int d=0; d<4; ++d) {
		int ni=i+dx[d], nj=j+dy[d];
		if (0<=ni&&ni<n&&0<=nj&&nj<m&&!vis[ni][nj]&&a[ni][nj]>=cur&&cnt<k/cur)
			dfs(ni, nj);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> a[i][j];
			ord[i*m+j]={a[i][j], i, j};
		}
	}
	sort(ord, ord+n*m);
	iota(p, p+n*m, 0);
	fill(s, s+n*m, 1);
	for (int i=n*m-1; ~i; --i) {
		int x=ord[i][1], y=ord[i][2];
		vis[x][y]=1;
		for (int d=0; d<4; ++d) {
			int ni=x+dx[d], nj=y+dy[d];
			if (0<=ni&&ni<n&&0<=nj&&nj<m&&vis[ni][nj])
				merge(x*m+y, ni*m+nj);
		}
		if (k%a[x][y]==0&&s[find(x*m+y)]>=k/a[x][y]) {
			cout << "YES\n";
			cur=a[x][y];
			memset(vis, 0, sizeof(vis));
			dfs(x, y);
			for (int i2=0; i2<n; ++i2) {
				for (int j=0; j<m; ++j)
					cout << ans[i2][j] << " ";
				cout << "\n";
			}
			return 0;
		}
	}
	cout << "NO";
	return 0;
}