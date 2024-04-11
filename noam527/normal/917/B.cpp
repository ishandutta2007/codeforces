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

struct edge {
	int to;
	int c;
	edge() {};
	edge(int tt, int cc) {
		to = tt;
		c = cc;
	}
};

int n, m, dp[100][100][2][26]; // 0,1 if at this state, the current player loses,wins
char c;
vector<vector<edge>> g;

int solve(int x, int y, int who, int last) {
	if (dp[x][y][who][last] != -1) return dp[x][y][who][last];
	dp[x][y][who][last] = 0;
	if (who == 0) {
		for (auto &i : g[x]) {
			if (i.c >= last && !solve(i.to, y, 1, i.c)) dp[x][y][who][last] = 1;
		}
	}
	else {
		for (auto &i : g[y]) {
			if (i.c >= last && !solve(x, i.to, 0, i.c)) dp[x][y][who][last] = 1;
		}
	}
	return dp[x][y][who][last];
}

int main() {
	fast;
	cin >> n >> m;
	g.resize(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v >> c;
		--u, --v;
		g[u].push_back(edge(v, c - 'a'));
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) for (int x = 0; x < 26; x++) dp[i][j][0][x] = dp[i][j][1][x] = -1;

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) solve(i, j, 0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j][0][0]) cout << 'A';
			else cout << 'B';
		}
		cout << endl;
	}
}