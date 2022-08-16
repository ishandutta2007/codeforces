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

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		int best_k = 1;
		string best_s = s;
		for (int k = 2; k <= n; k++) {
			string t = s.substr(k - 1, s.length()) + s.substr(0, k - 1);
			if ((n - k + 1) % 2 != 0) {
				reverse(t.end() - k + 1, t.end());
			}
			if (t < best_s) {
				best_s.swap(t);
				best_k = k;
			}
		}
		cout << best_s << '\n' << best_k << '\n';
	}
	return 0;
}