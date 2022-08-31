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

	int n;
	cin >> n;

	int lwr_bound = (int)-2e9, upr_bound = (int)2e9;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		int x;
		cin >> x;

		char ans;
		cin >> ans;

		if (s == ">") {
			if (ans == 'Y') {
				lwr_bound = max(lwr_bound, x + 1);
			} else {
				upr_bound = min(upr_bound, x);
			}
		} else if (s == "<") {
			if (ans == 'Y') {
				upr_bound = min(upr_bound, x - 1);
			} else {
				lwr_bound = max(lwr_bound, x);
			}
		} else if (s == ">=") {
			if (ans == 'Y') {
				lwr_bound = max(lwr_bound, x);
			} else {
				upr_bound = min(upr_bound, x - 1);
			}
		} else {
			if (ans == 'Y') {
				upr_bound = min(upr_bound, x);
			} else {
				lwr_bound = max(lwr_bound, x + 1);
			}
		}
	}

	if (lwr_bound <= upr_bound) {
		cout << lwr_bound << '\n';
	} else cout << "Impossible\n";
	return 0;
}