#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, m, a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> a[i];

		int f = -1;
		for (int i = n; i >= 1; i--) {
			if (a[i] != i) {
				f = i;
				break;
			}
		}

		int r;
		double p, ans = 1;
		while (m--) {
			cin >> r >> p;
			if (r >= f) {
				ans *= 1 - p;
			}
		}

		cout << fixed << setprecision(12);
		cout << (f == -1 ? 1.0 : 1 - ans) << '\n';
	}
	return 0;
}