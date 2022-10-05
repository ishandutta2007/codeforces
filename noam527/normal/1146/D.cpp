#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

int gcd(int x, int y) {
	return !y ? x : gcd(y, x % y);
}

ll L, m, a, b;
ll ans = 1;

int cnt = 1;
bool vis[200005] = {};

void go(int x) {
	if (vis[x]) return;
	vis[x] = 1;
	cnt++;
	if (x + a <= L) go(x + a);
	if (x - b >= 0) go(x - b);
}

ll org;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> m >> a >> b;
	org = m;
	ll g = gcd(a, b);
	a /= g;
	b /= g;
	ll left = m % g;
	left = g - 1 - left;
	m /= g;
	vis[0] = 1;
	L = 1;
	while (L <= 200000 && L <= m) {
		if ((L - a >= 0 && vis[L - a])) go(L);
		if (OO) {
			cout << "L cnt " << L << " " << cnt << '\n';
		}
		ans += cnt;
		L++;
	}
	if (L > m) {
		ans *= g;
		ans -= cnt * left;
		finish(ans);
	}
	// sum L to m
	if (OO) cout << "ans " << ans << '\n';
	ans = (ans + (m + L + 2) * (m - L + 1) / 2);
	ans *= g;
	ans -= (m + 1) * left;
	finish(ans);
}