#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
const long long hs = 149;
//const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

int n;
vector<vector<int>> g;
vector<int> col;

void dfs(int v, int c = 1) {
	if (col[v]) return;
	col[v] = c;
	for (auto &i : g[v])
		dfs(i, 3 - c);
}

int main() {
	fast;
	cin >> n;
	g.resize(n), col.resize(n, 0);
	for (int i = 0, u, v; i < n -1 ; i++) {
		cin >> u >> v, --u, --v;
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs(0);
	int cnt1 = 0, cnt2 = 0;
	for (auto &i : col)
		if (i == 1)
			cnt1++;
		else
			cnt2++;

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		if (col[i] == 1) {
			for (auto j : g[i])
				if (col[j] == 2) cnt++;
			ans += cnt2 - cnt;
		}
		else {
			for (auto j : g[i])
				if (col[j] == 1) cnt++;
			ans += cnt1 - cnt;
		}
	}
	cout << ans / 2 << endl;
}