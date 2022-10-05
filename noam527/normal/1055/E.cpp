#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int total(vector<pair<int, int>> &c) {
	int cnt[1505] = {};
	for (const auto &i : c)
		for (int j = i.first; j <= i.second; j++)
			cnt[j] = 1;
	int rtn = 0;
	for (int i = 0; i < 1505; i++) if (cnt[i]) rtn++;
	return rtn;
}

int n, s, m, k;
int a[1505], b[1505], ps[1505], best[1505];
int dp[1505][1505];
vector<pair<int, int>> c;

int count(int l, int r) {
	if (l > r) return 0;
	if (l == 0) return ps[r];
	return ps[r] - ps[l - 1];
}

bool check() {
	for (int i = 0; i < n; i++) dp[i][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = 0;
			if (i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (best[i] != inf) {
				if (best[i] == 0) {
					dp[i][j] = max(dp[i][j], count(0, i));
				}
				else {
					dp[i][j] = max(dp[i][j], count(best[i], i) + dp[best[i] - 1][j - 1]);
				}
			}
		}
	}
	if (dp[n - 1][m] >= k) return true;
	return false;
}

int main() {
	fast;
	cin >> n >> s >> m >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	c.resize(s);
	for (auto &i : c) cin >> i.first >> i.second, --i.first, --i.second;

	if (total(c) < k) finish(-1);

	for (int i = 0; i < n; i++) best[i] = inf;
	for (auto &i : c)
		for (int j = i.first; j <= i.second; j++)
			best[j] = min(best[j], i.first);

	int lo = 1, hi = 1e9 + 2, mid;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		for (int i = 0; i < n; i++) {
			if (a[i] <= mid) b[i] = 1;
			else b[i] = 0;
		}
		ps[0] = b[0];
		for (int i = 1; i < n; i++) ps[i] = ps[i - 1] + b[i];

		if (check()) hi = mid;
		else lo = mid + 1;
	}
	if (lo > 1000000000) finish(-1);
	finish(lo);
}