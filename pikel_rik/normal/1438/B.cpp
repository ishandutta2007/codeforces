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

		vector<int> b(n);
		for (int i = 0; i < n; i++) cin >> b[i];

		sort(b.begin(), b.end());

		bool there = false;
		for (int i = 1; i < n; i++) {
			there |= b[i] == b[i - 1];
		}

		cout << (there ? "YES" : "NO") << '\n';
	}
	return 0;
}