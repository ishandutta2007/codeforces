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

		bool ok = s.substr(0, 4) == "2020" || s.substr((int)s.length() - 4, 4) == "2020";
		for (int j = 1; j < 4; j++) {
			ok |= s.substr(0, j) + s.substr((int)s.length() - (4 - j), 4 - j) == "2020";
		}

		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}