#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;


ll mysqrt(ll x) {
	ll lo = 0, hi = 3000000000LL, mid;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		if (mid * mid < x)
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}

ll calc(ll a, ll A) {
	if (a - 1 <= A) return 0;
	ll val = (a - 1 - A) / 3;
	ll s = mysqrt(val);
	for (ll i = max(0LL, s - 8); i <= s + 8; i++) {
		ll x = a - 3 * i * i - 3 * i - 1;
		if (x <= A)
			return min(i, a);
	}
	return -1;
}

int n;
ll k;
vector<ll> a;

vector<ll> calc(ll A) {
	vector<ll> b(n, 0);
	for (int i = 0; i < n; i++)
		b[i] = calc(a[i], A);
	return b;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	a.resize(n);
	for (auto &i : a) cin >> i;
	ll lo = -inf, hi = md, mid;
	vector<ll> b;
	while (lo < hi) {
		mid = lo + (hi - lo) / 2;
		vector<ll> tmp = calc(mid);
		//b = calc(mid);
		ll sum = 0;
		for (auto &i : tmp)
			sum += i;

		//cout << "mid sum " << mid << " " << sum << endl;

		if (sum <= k) {
			hi = mid;
			b = tmp;
		}
		else
			lo = mid + 1;
	}
	ll sum = 0;
	for (auto &i : b) sum += i;

	for (int i = 0; i < n && sum < k; i++) {
		if (a[i] - 3 * b[i] * b[i] - 3 * b[i] - 1 == lo) {
			b[i]++;
			sum++;
		}
	}
	for (const auto &i : b) cout << i << " "; cout << endl;
}