#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

const int mxn = 1001;

int n;
int choose[mxn][mxn] = {};
ll dp[mxn], a[mxn];

int main() {
	fast;
	for (int i = 0; i < mxn; i++) choose[i][0] = 1;
	for (int j = 1; j < mxn; j++) for (int i = j; i < mxn; i++)
		choose[i][j] = (choose[i - 1][j] + choose[i - 1][j - 1]) % md;

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	dp[n] = 1;
	for (int i = n - 1; i >= 0; i--) {
		dp[i] = 0;
		if (0 < a[i] && a[i] < n) {
			for (int j = i + 1; j <= n; j++) {
				(dp[i] += (dp[j] * choose[j - i - 1][a[i]])) %= md;
			}
		}
	}
	ll s = 0;
	for (int i = 0; i < n - 1; i++)
		(s += dp[i]) %= md;
	finish(s);
}