#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, x;
		cin >> n >> x;

		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		vector<bool> v(300);
		for (int aa : a) {
			v[aa] = true;
		}

		int ans = 0;
		for (int i = 1; i < 300; i++) {
			if (v[i]) continue;
			x--;
			if (x < 0) {
				ans = i - 1;
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}