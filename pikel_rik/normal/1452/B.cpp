#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<ll> a(n);
		for (auto& item : a) cin >> item;

		ll sum = accumulate(a.begin(), a.end(), 0ll);
		ll mx = *max_element(a.begin(), a.end());

		if ((n - 1) * mx >= sum) {
			cout << (n - 1) * mx - sum << '\n';
		} else {
			//(n - 1) * mx >= sum => mx >= sum / (n - 1)
			cout << (n - 1) * ((sum + n - 2) / (n - 1)) - sum << '\n';
		}
	}
	return 0;
}