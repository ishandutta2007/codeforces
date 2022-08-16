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

		string s;
		cin >> s;

		vector<bool> ok(n);
		bool less = false, gre = false;
		for (char ch : s) {
			if (ch == '<') {
				less = true;
			} else if (ch == '>') {
				gre = true;
			}
		}

		for (int i = 0; i < n; i++) {
			if (s[i] == '-') {
				ok[i] = ok[(i + 1) % n] = true;
			}
		}

		if (less && gre) {
			int sum = 0;
			for (bool i : ok) sum += i;
			cout << sum << '\n';
		} else {
			cout << n << '\n';
		}
	}
	return 0;
}