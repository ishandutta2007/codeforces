#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2000, dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
const ll INF=1e18;
int n, m, w, a[mxN][mxN], d[mxN][mxN];
ll mn1=INF, mn2=INF, ans=INF;
bool vis[mxN][mxN];

void bfs(int si, int sj, ll& mn) {
	memset(d, -1, sizeof(d));
	queue<ar<int, 2>> q;
	q.push({si, sj});
	d[si][sj]=0;
	while(!q.empty()) {
		int i=q.front()[0], j=q.front()[1];
		q.pop();
		for (int k=0; k<4; ++k) {
			int ni=i+dx[k], nj=j+dy[k];
			if (0<=ni&&ni<n&&0<=nj&&nj<m&&d[ni][nj]==-1&&a[ni][nj]!=-1) {
				d[ni][nj]=d[i][j]+1;
				q.push({ni, nj});
			}
		}
	}
	if (si==0&&d[n-1][m-1]!=-1)
		ans=min(ans, (ll)d[n-1][m-1]*w);
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (d[i][j]!=-1&&a[i][j]>0)
				mn=min(mn, (ll)w*d[i][j]+a[i][j]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> w;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> a[i][j];
	bfs(0, 0, mn1);
	bfs(n-1, m-1, mn2);
	//cout << mn1 << " " << mn2 << " " << ans << endl;
	ans=min(ans, mn1+mn2);
	cout << (ans==INF?-1:ans);
	return 0;
}