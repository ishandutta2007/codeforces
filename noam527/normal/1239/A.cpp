#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int dp[100005];

int calc(int n) {
	dp[1] = 2;
	dp[2] = 2;
	for (int i = 3; i <= n + 1; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % md;
	}
	return dp[n + 1];
}

int n, m;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	int ans = 0;
	(ans += calc(n)) %= md;
	(ans += calc(m)) %= md;
	ans = (ans - 2 + md) % md;
	cout << ans << '\n';
}