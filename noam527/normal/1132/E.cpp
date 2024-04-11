#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e13;
const int OO = 0;
using namespace std;

const int T = 3000;

ll W, c[9], S = 0;
int dp[T + 100];

bool can(ll x) {
	ll d[9], F = 0;
	for (int i = 1; i <= 8; i++) d[i] = c[i];
	for (int i = 8; i >= 1; i--) {
		if (d[i] <= 20) continue;
		d[i] -= 20;
		if (F + d[i] * i + T < x)
			F += d[i] * i, d[i] = 20;
		else {
			ll cnt = max(0LL, (x - F - T) / i);
			F += cnt * i;
			d[i] -= cnt;
			while (F + T < x) F += i, d[i]--;
			d[i] += 20;
			break;
		}
	}

	for (int i = 0; i < T + 100; i++) dp[i] = 0;
	dp[0] = 1;

	for (int i = 1; i <= 8; i++) {
		ll cnt = min(d[i], ((ll)T + 300) / i);
		while (cnt--) {
			for (int j = T + 99; j >= i; j--)
				dp[j] = dp[j] | dp[j - i];
		}
	}
	return dp[x - F];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> W;
	for (int i = 1; i <= 8; i++)
		cin >> c[i], S += c[i] * i;
	if (S <= W) finish(S);
	ll x = W;
	while (!can(x)) x--;
	finish(x);
}