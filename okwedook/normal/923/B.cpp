#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

ll getsum(vector<ll> &pref, vector<ll> &arr, ll l, ll r) {
	if (r < l) return 0;
	return pref[r] - pref[l] + arr[l];
}
 
int main() {
	ll n;
	cin >> n;
	vector<ll> v(n), t(n);
	for (auto &i : v) cin >> i;
	for (auto &i : t) cin >> i;
	vector<ll> pref(n);
	vector<ll> addans(n, 0);
	vector<ll> died(n, 0);
	ll summ = 0;
	for (ll i = 0; i < n; ++i) {
		summ += t[i];
		pref[i] = summ;
	}
	for (ll i = 0; i < n; ++i) {
		ll l = i - 1, r = n;
		while (r - l > 1) {
			ll m = (r + l) / 2;
			if (getsum(pref, t, i, m) > v[i]) r = m;
			else l = m;
		}
		if (r < n) {
			addans[r] += v[i] - getsum(pref, t, i, l);
			died[r] += 1;
		}
	}
	ll alive = 0;
	for (ll i = 0; i < n; ++i) {
		++alive;
		alive -= died[i];
		cout << alive * t[i] + addans[i] << ' ';
	}
    return 0;
}