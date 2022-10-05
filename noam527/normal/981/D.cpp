#include <bits/stdc++.h>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
#define yesno(X) cout << ((X) ? "YES" : "NO") << endl
#define noyes(X) cout << ((X) ? "NO" : "YES") << endl
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, k, dp[51][51];
ll a[51];

bool check(ll val) {
	for (int i = 0; i <= 50; i++) for (int j = 0; j <= 50; j++) dp[i][j] = 0;
//	cout << "checking for val " << val << endl;
	for (int i = 0; i < n; i++)
		if ((a[i] & val) == val) dp[i][1] = 1;
	for (int j = 2; j <= k; j++) {
		for (int i = j - 1; i < n; i++) {
			for (int pos = j - 2; pos < i; pos++)
				if (dp[pos][j - 1] && ((a[i] - a[pos]) & val) == val) dp[i][j] = 1;
		}
	}
	return dp[n - 1][k];
}

int main() {
	fast;
	ll val = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) a[i] += a[i - 1];

	for (ll i = 60, b = (1LL << 60); i >= 0; i--, b /= 2) {
		if (check(val + b)) val += b;
	}
	finish(val);
}