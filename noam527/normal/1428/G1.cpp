#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

const int pw[6] = { 1, 10, 100, 1000, 10000, 100000 };

int k, q;
ll F[6];
vector<ll> C[6];

const int M = 10000;
const int mult = 100;
ll dp[M];
ll DP[M * mult];

void solve() {
	cin >> k;
	for (int i = 0; i < 6; i++) cin >> F[i];
	cin >> q;

	for (int i = 0; i < 6; i++) {
		C[i].resize(min(9 * k + 1, 1000000 / pw[i] + 1));
		for (int j = 0; j < C[i].size(); j++) {
			ll nine = j / 9;
			ll rem = j % 9;
			if (rem % 3 != 0 && k - nine == 1) {
				C[i][j] = nine * 3 * F[i];
			}
			else {
				C[i][j] = nine * 3 * F[i];
				C[i][j] += (rem / 3) * F[i];
			}
		}
	}
	if (OO) {
		cout << "ok\n";
	}
	for (int i = 0; i < M; i++) dp[i] = -inf;
	dp[0] = 0;

	for (int i = 2; i <= 5; i++) {
		int order = pw[i - 2];
		for (int j = M - 1; j >= 0; j--) {
			for (int k = 0; k < C[i].size(); k++) {
				ll worth = C[i][k];
				ll cost = order * k;
				if (cost <= j)
					dp[j] = max(dp[j], dp[j - cost] + worth);
			}
		}
	}
	if (OO) {
		cout << "ok\n";
		cout << C[1][6] << '\n';
		cout << C[0][40] << '\n';
	}
	const int iter = 15;
	for (int i = 0; i < M * mult; i++) {
		DP[i] = -inf;
		for (int j = 0; j < iter; j++) {
			ll small = min(i, (int)C[0].size() - 1);
			small -= ((small - i) % 10 + 10) % 10;
			ll big = (i - small) / 10;

			if (small < 0 || small >= C[0].size() || big < 0 || big >= C[1].size()) continue;
			DP[i] = max(DP[i], C[1][big] + C[0][small]);
		}
		for (int j = 0; j < iter; j++) {
			ll big = min(i / 10, (int)C[1].size() - 1) - j;
			ll small = i - big * 10;
			if (small < 0 || big < 0 || small >= C[0].size() || big >= C[1].size()) continue;
			DP[i] = max(DP[i], C[1][big] + C[0][small]);
		}
	}
	
	if (OO) {
		for (int i = 0; i <= 100; i++) {
			cout << i << ": " << DP[i] << '\n';
		}
	}

	while (q--) {
		int n;
		cin >> n;
		ll ans = -inf;
		for (int i = 0; i < M; i++) {
			ll big = i * mult;
			ll small = n - big;
			if (small < 0 || big < 0) continue;
			ans = max(ans, dp[i] + DP[small]);
		}
		cout << ans << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}