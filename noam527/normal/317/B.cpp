#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <queue>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int te, x, y, g[200][200];
vector<int> ro = { -1, 0, 1, 0 }, co = { 0, 1, 0, -1 };

void dfs(int x, int y) {
	if (g[x][y] < 4) return;
	int a = g[x][y] / 4;
	g[x][y] %= 4;
	for (int i = 0; i < 4; i++) {
		g[x + ro[i]][y + co[i]] += a;
		dfs(x + ro[i], y + co[i]);
	}
}

int main() {
	fast;
	for (int i = 0; i < 200; i++) for (int j = 0; j < 200; j++) g[i][j] = 0;
	cin >> g[100][100] >> te;
	dfs(100, 100);
	while (te--) {
		cin >> x >> y;
		if (x < -100 || y < -100 || x > 99 || y > 99) cout << 0 << endl;
		else cout << g[x + 100][y + 100] << endl;
	}
}