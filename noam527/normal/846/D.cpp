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
const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

struct eve {
	int x, y, t;
	eve(int x = 0, int y = 0, int t = 0) : x(x), y(y), t(t) {};
	bool operator < (eve &z) {
		return t < z.t;
	}
};

int n, m, k, q;
vector<vector<int>> t, dp;
vector<eve> e;

bool check(int x) {
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) t[i][j] = dp[i][j] = 0;
	for (int i = 0; i <= x; i++) t[e[i].x][e[i].y] = 1;
	for (int i = 0; i < n; i++) dp[i][0] = t[i][0];
	for (int i = 0; i < m; i++) dp[0][i] = t[0][i];
	for (int i = 1; i < n; i++) for (int j = 1; j < m; j++) {
		if (t[i][j] == 0) dp[i][j] = 0;
		else dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (dp[i][j] >= k) return true;
	return false;
}

int main() {
	fast;
	cin >> n >> m >> k >> q;
	if (q == 0) return cout << -1 << endl, 0;
	t.resize(n, vector<int>(m)), dp.resize(n, vector<int>(m)), e.resize(q);
	for (int i = 0; i < q; i++) cin >> e[i].x >> e[i].y >> e[i].t, --e[i].x, --e[i].y;
	sort(e.begin(), e.end());
	int lo = 0, hi = q - 1, mid;
	while (lo < hi) {
		mid = lo + (hi - lo) / 2;
		if (check(mid)) hi = mid;
		else lo = mid + 1;
	}
	if (lo == q - 1 && !check(lo)) cout << -1 << endl;
	else cout << e[lo].t << endl;
}