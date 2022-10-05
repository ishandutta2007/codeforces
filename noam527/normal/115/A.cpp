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

int n, ans = -1;
vector<vector<int>> g;

void dfs(int v, int dis = 1) {
	ans = max(ans, dis);
	for (auto &i : g[v]) dfs(i, dis + 1);
}

int main() {
	fast;
	cin >> n;
	g.resize(n);
	for (int i = 0, p; i < n; i++) {
		cin >> p;
		if (p != -1) g[p - 1].push_back(i);
	}

	for (int i = 0; i < n; i++) dfs(i);
	cout << ans << endl;
}