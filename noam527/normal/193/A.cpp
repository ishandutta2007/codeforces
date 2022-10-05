#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <random>
#include <fstream>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

char xd;
int n, m, c[50][50] = {}, vis[50][50], cnt = 0;

void dfs(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y]) return;
	vis[x][y] = 1;
	if (c[x - 1][y]) dfs(x - 1, y);
	if (c[x + 1][y]) dfs(x + 1, y);
	if (c[x][y - 1]) dfs(x, y - 1);
	if (c[x][y + 1]) dfs(x, y + 1);
}

bool check() {
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) vis[i][j] = 0;
	int ct = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		if (c[i][j] && !vis[i][j]) {
			ct++;
			dfs(i, j);
		}
	return ct > 1;
}

int main() {
	fast;
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		cin >> xd;
		cnt += c[i][j] = (xd == '.' ? 0 : 1);
	}
	if (cnt < 3) finish(-1);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		if (c[i][j]) {
			c[i][j] = 0;
			if (check()) finish(1);
			c[i][j] = 1;
		}
	}
	finish(2);
}