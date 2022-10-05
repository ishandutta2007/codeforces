#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
//const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

int n, ans = -1, b[1001][1001];
vector<bool> vis;

void dfs(int x, int y, int prev) {
	vis[b[x][y]] = true;
	if (prev == 0) {
		for (int i = 0; i < 1001; i++)
			if (b[x][i] != -1 && !vis[b[x][i]]) dfs(x, i, prev ^ 1);
	}
	else {
		for (int i = 0; i < 1001; i++)
			if (b[i][y] != -1 && !vis[b[i][y]]) dfs(i, y, prev ^ 1);
	}
}

int main() {
	fast;
	for (int i = 0; i < 1001; i++) for (int j = 0; j < 1001; j++) b[i][j] = -1;
	cin >> n;
	vector<pair<int, int>> a(n);
	vis.resize(n, false);
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second, b[a[i].first][a[i].second] = i;

	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			ans++;
			dfs(a[i].first, a[i].second, 0);
			dfs(a[i].first, a[i].second, 1);
		}
	}
	cout << ans << endl;
}