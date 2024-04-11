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
		int x;
		cin >> x;

		vector<int> ans;
		for (int i = 9; i >= 1 && x; i--) {
			if (i > x) {
				ans.push_back(x);
				x = 0;
			} else {
				ans.push_back(i);
				x -= i;
			}
		}

		if (x) {
			cout << "-1\n";
		} else {
			reverse(ans.begin(), ans.end());
			for (int i : ans) cout << i;
			cout << '\n';
		}
	}
	return 0;
}