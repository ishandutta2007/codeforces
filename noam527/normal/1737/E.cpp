#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

ll pw(ll b, ll e) {
	ll res = 1;
	while (e) {
		if (e & 1) res = res * b % md;
		e /= 2, b = b * b % md;
	}
	return res;
}

const int N = 1000005;
const ll I = (md + 1) / 2;

int dp[N], dps[N];

void solve() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << "1\n";
		return;
	}

	dps[n + 1] = 0;
	for (int i = n; i >= 1; i--) {
		if (i + i - 1 >= n) {
			dp[i] = 1;
			dps[i] = (pw(I, i) + dps[i + 1]) % md;
		}
		else {
			dp[i] = pw(2, i) * (dps[i + 1] - dps[2 * i]) % md;
			if (dp[i] < 0) dp[i] += md;
			dps[i] = pw(I, i) * (ll)dp[i] % md + (ll)dps[i + 1];
			dps[i] %= md;
		}
		//cout << dp[i] << " " << dps[i] << '\n';
	}


	cout << "0\n";
	for (int i = 2; i <= n; i++) {
		if (i + i - 1 >= n) {
			if (i < n)
				cout << pw(I, (i - 1) / 2 + 1) << '\n';
			else
				cout << pw(I, (i - 1) / 2) << '\n';
		}
		else {
			ll x = pw(I, (i - 1) / 2 + 1);
			ll y = dp[i];
			cout << x * y % md << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}