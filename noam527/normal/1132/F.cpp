#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e13;
const int OO = 0;
using namespace std;

string s;
int n;
int dp[505][505][27] = {};

void calc(int l, int r) {
	if (l > r) return;
	if (dp[l][r][0] != -1) return;
	if (l == r) {
		for (int k = 0; k < 27; k++) dp[l][r][k] = 1;
		dp[l][r][s[l] - 'a'] = 0;
		return;
	}
	for (int k = 0; k < 27; k++) dp[l][r][k] = 1e9;
	for (int i = l; i <= r; i++) {
		calc(l, i - 1), calc(i + 1, r);
		dp[l][r][s[i] - 'a'] = min(dp[l][r][s[i] - 'a'], dp[l][i - 1][s[i] - 'a'] + dp[i + 1][r][s[i] - 'a']);
	}
	for (int k = 0; k < 26; k++)
		dp[l][r][26] = min(dp[l][r][26], 1 + dp[l][r][k]);
	for (int k = 0; k < 26; k++) dp[l][r][k] = min(dp[l][r][k], dp[l][r][26]);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) for (int j = i; j < n; j++) for (int k = 0; k < 27; k++) dp[i][j][k] = -1;
	calc(0, n - 1);
	cout << dp[0][n - 1][26] << '\n';
}