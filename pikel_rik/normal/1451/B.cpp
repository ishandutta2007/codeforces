#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int n, q;
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> q;
		cin >> s;

		while (q--) {
			int l, r;
			cin >> l >> r; --l; --r;

			bool ok = false;
			for (int i = 0; i < l; i++) {
				ok |= s[i] == s[l];
			}

			for (int i = r + 1; i < n; i++) {
				ok |= s[i] == s[r];
			}
			cout << (ok ? "YES" : "NO") << '\n';
		}
	}
	return 0;
}