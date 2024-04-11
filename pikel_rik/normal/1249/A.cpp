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

	int q;
	cin >> q;

	while (q--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		sort(a.begin(), a.end());

		bool adj_same = false;
		for (int i = 1; i < n; i++) {
			adj_same |= a[i] == a[i - 1] + 1;
		}

		cout << 1 + adj_same << '\n';
	}
	return 0;
}