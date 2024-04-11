#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 6e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

const int N = 3003;

int n, m;
string s, t;
int dp[N][N];

int calc(int i, int j) {
	if (i == n) {
		return 1;
	}
	if (dp[i][j] != -1) return dp[i][j];
	dp[i][j] = 0;
	int r = n - 1 - (i - j);
	if (j >= t.size() || s[i] == t[j])
		dp[i][j] = (dp[i][j] + calc(i + 1, j + 1)) % md;
	if (r >= t.size() || s[i] == t[r])
		dp[i][j] = (dp[i][j] + calc(i + 1, j)) % md;
	return dp[i][j];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> s >> t;
	reverse(s.begin(), s.end());

	n = s.size(), m = t.size();
	for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++)
		dp[i][j] = -1;
	/*
	while (1) {
		int i, j;
		cin >> i >> j;
		cout << calc(i, j) << endl;
	}
	*/
	int ans = 0;
	for (int i = 0; i <= n - m; i++)
		ans = (ans + calc(i, 0)) % md;
	cout << ans << endl;
}