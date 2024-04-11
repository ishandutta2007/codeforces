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
		for (int i = 0; i < n; i++) cin >> a[i], --a[i];

		int last = 0;
		for (int v = 0; v < n; v++) {
			int idx = find(a.begin(), a.end(), v) - a.begin();
			if (idx > last) {
				for (int i = idx - 1; i >= last; i--) {
					swap(a[i], a[i + 1]);
				}
				last = idx;
			} else if (idx == last) {
				last = idx + 1;
			}
		}

		for (int x : a) cout << x + 1 << ' '; cout << '\n';
	}
	return 0;
}