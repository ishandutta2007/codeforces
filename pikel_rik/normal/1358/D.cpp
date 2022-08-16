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

	int n; ll x;
	cin >> n >> x;

	vector<int> d(2 * n);
	for (int i = 0; i < n; i++) cin >> d[i];

	copy(d.begin(), d.begin() + n, d.begin() + n);

	auto f = [&](ll x) -> ll {
		return (x * x + x) / 2;
	};

	int i = 0;
	ll cur_days = 0, cur_ans = 0, best_ans = 0;

	for (int j = 0; j < 2 * n; j++) {
		cur_days += d[j];
		cur_ans += f(d[j]);
		for (; cur_days > x; i++) {
			cur_days -= d[i];
			cur_ans -= f(d[i]);
		}
		ll left_over = x - cur_days;
		best_ans = max(best_ans, cur_ans + (i != 0 ? f(d[i - 1]) - f(d[i - 1] - left_over) : 0));
	}

	cout << best_ans << '\n';
	return 0;
}