#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 998244353;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<int> a(n);
		for (int& i : a) cin >> i;

		if (accumulate(a.begin(), a.end(), 0ll) == m) {
			cout << "YES\n";
		} else cout << "NO\n";
	}
	return 0;
}