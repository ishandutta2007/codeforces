#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int sz = 1e3;
int n, m, xsrc, ysrc, xdst, ydst;
char a[sz][sz];
bool vis[sz][sz];
int dirs[][2]{ {0,1},{0,-1},{1,0},{-1,0} };

void dfs(int x, int y) {
	vis[x][y] = 1;
	for (int r = 0; r < 4; r++) {
		int myx = x + dirs[r][0], myy = y + dirs[r][1];
		if (myx < 0 || myy < 0 || myx >= n || myy >= m || vis[myx][myy] || a[myx][myy] == 'X')continue;
		dfs(myx, myy);
	}
}

void input() {
	cin >> n >> m;
	foru(i, 0, n) {
		string s;
		cin >> s;
		foru(j, 0, m)a[i][j] = s[j];
	}
	cin >> xsrc >> ysrc >> xdst >> ydst; xsrc--; ysrc--; xdst--; ydst--;
}

int main() {
	fast;
	input();
	dfs(xsrc, ysrc);
	int goodNeigh = 0;
	for (int r = 0; r < 4; r++) {
		int myx = xdst + dirs[r][0], myy = ydst + dirs[r][1];
		if (myx < 0 || myy < 0 || myx >= n || myy >= m || !vis[myx][myy])continue;
		goodNeigh++;
	}
	if (goodNeigh == 0) {
		cout << "NO" << endl;
	}
	else if (goodNeigh == 1) {
		if (a[xdst][ydst] == 'X')cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}
	return 0;
}