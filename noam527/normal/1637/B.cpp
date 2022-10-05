#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

const int N = 105;

int n;
int a[N];
int dp[N][N];
int val[N][N];

int cnt[N];
int mex;

void clear() {
	mex = 0;
	for (int i = 0; i < N; i++)
		cnt[i] = 0;
}
int calc() {
	while (cnt[mex]) mex++;
	return mex;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		clear();
		for (int j = i; j < n; j++) {
			if (a[j] < N) cnt[a[j]] = 1;
			val[i][j] = calc();
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		dp[i][i] = 1 + val[i][i], ans += dp[i][i];
	for (int d = 1; d < n; d++) {
		for (int i = 0; i + d < n; i++) {
			int j = i + d;
			dp[i][j] = 1 + val[i][j];
			for (int k = i; k < j; k++) {
				dp[i][j] = max(dp[i][j], dp[i][k] + 1 + val[k + 1][j]);
			}
			ans += dp[i][j];
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}