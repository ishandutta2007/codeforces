#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define ln '\n'
ll P;
bool calc(ll N, ll r) {
	ll nc3 = N * (N - 1) * (N - 2) / 3;
	ll a = r, b = N - r;
	ll up = 0;
	up += a * ((b - 1) * b / 2);
	up += a * (a - 1) * b;
	up += (a - 2) * (a - 1) * a / 3;
	return 10000 * up >= P * nc3;
}
signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll N;
	ld p;
	cin >> N >> p;
	P = p * 10000;
	if (P == 0) {
		cout << 0 << ln;
		return 0;
	}
	ll l, r;
	l = 0, r = N;
	while (r - l > 1) {
		ll mid = (l + r) / 2;
		if (calc(N, mid)) r = mid;
		else l = mid;
	}
	cout << r << ln;
}