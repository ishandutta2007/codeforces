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

		vector<int> a(n), b(n);
		for (auto &i : a) cin >> i;
		for (auto &i : b) cin >> i;

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		for (int i : a) cout << i << ' '; cout << '\n';
		for (int i : b) cout << i << ' '; cout << '\n';
	}
	return 0;
}