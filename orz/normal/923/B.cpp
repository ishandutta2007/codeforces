#include <iostream>
#include <vector>

#define ll long long

using namespace std;

signed main() {

	ll n;
	cin >> n;
	vector<ll> volume(static_cast<unsigned ll>(n)), temp(static_cast<unsigned ll>(n));
	vector<ll> pref(static_cast<unsigned ll>(n + 1));
	for (ll i = 0; i < n; i++) {
		cin >> volume[i];
	}
	pref[0] = 0;
	for (ll i = 0; i < n; i++) {
		cin >> temp[i];
		pref[i + 1] = pref[i] + temp[i];
	}

	vector<ll> res(static_cast<unsigned ll>(n));
	vector<ll> full(static_cast<unsigned ll>(n));
	for (ll i = 0; i < n; i++) {
		ll l = i, r = n;
		while (r - l > 1) {
			ll m = (l + r) / 2;
			ll sum = pref[m] - pref[i];

			if (sum < volume[i]) {
				l = m;
			}
			else {
				r = m;
			}
		}

		full[i]++;
		if (pref[r] - pref[i] <= volume[i]) {
			if (r < n) {
				full[r]--;
			}
		}
		else {
			full[r - 1]--;
			res[r - 1] += (long)volume[i] - (pref[r - 1] - pref[i]);
		}
	}

	for (ll i = 1; i < n; i++) {
		full[i] += full[i - 1];
	}

	for (ll i = 0; i < n; i++) {
		cout << (long)full[i] * temp[i] + res[i] << ' ';
	}

	cout << '\n';
	return 0;

}