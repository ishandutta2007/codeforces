#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<string> c;
vector<string> s;
vector<vector<int>> v;
vector<vector<int>> g;
int r[1222333][3];

int cc;
int uu;

int bb[1222333];

void dfs1(int y, int x, int f, int w) {
	if (v[y][x] == f) {
		if (uu == 0) {
			r[cc][0] = w-g[y][x];
			r[cc][1] = y;
			r[cc][2] = x;
		}
		return;
	}
	if (!uu && v[y][x]) {
		uu = v[y][x];
		return;
	}
	v[y][x] = f;
	g[y][x] = w;
	if (s[y][x] == 'U') dfs1(y-1,x,f,w+1);
	if (s[y][x] == 'D') dfs1(y+1,x,f,w+1);
	if (s[y][x] == 'L') dfs1(y,x-1,f,w+1);
	if (s[y][x] == 'R') dfs1(y,x+1,f,w+1);
}

void dfs2(int y, int x, int k, int d) {
	if (c[y][x] == '0') bb[k] = 1;
	if (y-1 >= 1 && (r[d][1] != y-1 || r[d][2] != x) && s[y-1][x] == 'D') {
		dfs2(y-1,x,(k+1)%r[d][0],d);
	}
	if (y+1 <= n && (r[d][1] != y+1 || r[d][2] != x) && s[y+1][x] == 'U') {
		dfs2(y+1,x,(k+1)%r[d][0],d);
	}
	if (x-1 >= 1 && (r[d][1] != y || r[d][2] != x-1) && s[y][x-1] == 'R') {
		dfs2(y,x-1,(k+1)%r[d][0],d);
	}
	if (x+1 <= m && (r[d][1] != y || r[d][2] != x+1) && s[y][x+1] == 'L') {
		dfs2(y,x+1,(k+1)%r[d][0],d);
	}
}

void lol() {
	cin >> n >> m;
	v.resize(n+1);
	g.resize(n+1);
	for (int i = 1; i <= n; i++) {
		v[i].clear();
		v[i].resize(m+1);
		g[i].clear();
		g[i].resize(m+1);
	}
	c.resize(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		c[i] = "#"+c[i];
	}
	s.resize(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = "#"+s[i];
	}
	cc = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (v[i][j]) continue;
			cc++;
			uu = 0;
			dfs1(i,j,cc,0);
			if (uu) {cc--; dfs1(i,j,uu,0);}
		}
	}
	int c1 = 0, c2 = 0;
	for (int i = 1; i <= cc; i++) {
		for (int j = 0; j < r[i][0]; j++) bb[j] = 0;
		c1 += r[i][0];
		dfs2(r[i][1],r[i][2],0,i);
		for (int j = 0; j < r[i][0]; j++) if (bb[j]) c2++;
	}
	cout << c1 << " " << c2 << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) lol();
}