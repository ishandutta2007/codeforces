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

	string s;
	cin >> s;

	int n;
	cin >> n;

	vector<pair<char, string>> q(n);
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;

		q[i].first = temp[0];
		if (temp.size() > 3) {
			q[i].second = temp.substr(3);
		}
	}

	vector<pair<ll, ll>> digits(10);
	for (int i = 0; i < 10; i++) {
		digits[i].first = 10;
		digits[i].second = i;
	}

	for (int i = n - 1; i >= 0; i--) {
		pair<ll, ll> new_val = make_pair(1, 0);
		for (int j = 0; j < q[i].second.length(); j++) {
			int c = q[i].second[j] - '0';
			new_val.first = new_val.first * digits[c].first % mod;
			new_val.second = (new_val.second * digits[c].first + digits[c].second) % mod;
		}
		digits[q[i].first - '0'] = new_val;
	}

	ll ans = 0;
	for (int i = 0; i < s.length(); i++) {
		int c = s[i] - '0';
		ans = (ans * digits[c].first + digits[c].second) % mod;
	}
	cout << ans << '\n';
	return 0;
}