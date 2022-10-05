#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

const int mx = 200;

int n;
vector<int> a;
int dp[100005][mx + 2][2] = {};

int main() {
	fast;
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	if (a[0] == -1) {
		for (int j = 1; j <= mx; j++)
			dp[0][j][1] = 1, dp[0][j][0] = 0;
	}
	else {
		for (int j = 1; j <= mx; j++)
			dp[0][j][0] = dp[0][j][1] = 0;
		dp[0][a[0]][1] = 1;
	}

	int ps[mx + 2][2] = {};

	for (int i = 1; i < n; i++) {
		ps[1][0] = dp[i - 1][1][0];
		ps[1][1] = dp[i - 1][1][1];
		for (int j = 2; j <= mx; j++) {
			ps[j][0] = (ps[j - 1][0] + dp[i - 1][j][0]) % md;
			ps[j][1] = (ps[j - 1][1] + dp[i - 1][j][1]) % md;
		}
		
		
		for (int j = 1; j <= mx; j++) {
			dp[i][j][0] = ((((ll)dp[i - 1][j][1] + ps[mx][0] - ps[j - 1][0]) % md) + md) % md;
			dp[i][j][1] = ((ll)ps[j - 1][0] + ps[j - 1][1]) % md;
		}
		if (a[i] != -1) {
			for (int j = 1; j <= mx; j++)
				if (a[i] != j) dp[i][j][0] = dp[i][j][1] = 0;
		}
	}
	int ans = 0;
	for (int j = 1; j <= 200; j++)
		(ans += dp[n - 1][j][0]) %= md;
	cout << ans << endl;
}