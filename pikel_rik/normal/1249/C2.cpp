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

	int q;
	cin >> q;

	auto ternary = [&](ll x) -> vector<int> {
		vector<int> ans;
		while (x) {
			ans.push_back(x % 3);
			x /= 3;
		}
		return ans;
	};

	vector<ll> three(40);

	three[0] = 1;
	for (int i = 1; i < three.size(); i++) {
		three[i] = 3 * three[i - 1];
	}

	while (q--) {
		ll n;
		cin >> n;

		auto v = ternary(n);
		v.push_back(0);

		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 2) {
				fill(v.begin(), v.begin() + i + 1, 0);
				v[i + 1]++;
			} else if (v[i] == 3) {
				v[i] = 0;
				v[i + 1]++;
			}
		}

		n = 0;
		for (int i = 0; i < v.size(); i++) {
			n += three[i] * v[i];
		}
		cout << n << '\n';
	}
	return 0;
}