#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
const ar<int, 2> id={-1, -1};
int n, m;
vector<vector<int>> a;
vector<vector<bool>> vis;

ar<int, 2> check() {
	vis=vector<vector<bool>>(n, vector<bool>(m));
	vector<ar<int, 2>> pos(n*m);
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			pos[a[i][j]]={i, j};
	vis[pos[0][0]][pos[0][1]]=1;
	for (int x=1; x<n*m; ++x) {
		int i=pos[x][0], j=pos[x][1];
		bool ok=0;
		for (int k=0; k<4; ++k) {
			int ni=i+dx[k], nj=j+dy[k];
			if (0<=ni&&ni<n&&0<=nj&&nj<m&&vis[ni][nj]) {
				ok=1;
				break;
			}
		}
		if (!ok) // first bad
			return {i, j};
		vis[i][j]=1;
	}
	return id;
}

bool bad(int i, int j) {
	if (a[i][j]) {
		for (int k=0; k<4; ++k) {
			int ni=i+dx[k], nj=j+dy[k];
			if (0<=ni&&ni<n&&0<=nj&&nj<m&&a[ni][nj]<a[i][j])
				return 0;
		}
		return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	a=vector<vector<int>>(n, vector<int>(m));
	for (int i=0; i<n; ++i)
		for (int& j : a[i])
			cin >> j, --j;
	ar<int, 2> pos=check();
	if (pos==id) {
		cout << 0;
		return 0;
	}
	set<ar<ar<int, 2>, 2>> cands;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (!(i==pos[0]&&j==pos[1])&&a[i][j]>a[pos[0]][pos[1]]) {
				bool ok=0;
				for (int k=0; k<4; ++k) {
					int ni=i+dx[k], nj=j+dy[k];
					if (0<=ni&&ni<n&&0<=nj&&nj<m&&vis[ni][nj]) {
						ok=1;
						break;
					}
				}
				if (ok)
					cands.insert({min(pos, ar<int, 2>{i, j}), max(pos, ar<int, 2>{i, j})});
			}
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (a[i][j]<a[pos[0]][pos[1]])
				for (int k=0; k<4; ++k) {
					int ni=pos[0]+dx[k], nj=pos[1]+dy[k];
					if (0<=ni&&ni<n&&0<=nj&&nj<m) {
						ar<int, 2>  x={i, j}, y={ni, nj};
						cands.insert({min(x, y), max(x, y)});
					}
				}
	int cnt_bad=0;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cnt_bad+=bad(i, j);
	//cout << cnt_bad << endl;
	int ans=0;
	for (auto thing : cands) {
		ar<int, 2> x=thing[0], y=thing[1];
		set<ar<int, 2>> tocheck;
		for (ar<int, 2> u : {x, y}) {
			int i=u[0], j=u[1];
			tocheck.insert(u);
			for (int k=0; k<4; ++k) {
				int ni=i+dx[k], nj=j+dy[k];
				if (0<=ni&&ni<n&&0<=nj&&nj<m)
					tocheck.insert({ni, nj});
			}
		}
		int change=0;
		for (ar<int, 2> u : tocheck)
			change-=bad(u[0], u[1]);
		swap(a[x[0]][x[1]], a[y[0]][y[1]]);
		for (ar<int, 2> u : tocheck)
			change+=bad(u[0], u[1]);
		ans+=(cnt_bad+change)==0;
		swap(a[x[0]][x[1]], a[y[0]][y[1]]);
	}
	if (ans) {
		cout << "1 " << ans;
		return 0;
	}
	cout << 2;
	return 0;
}