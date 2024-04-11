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

		vector<string> a(n);
		for (auto& s : a) cin >> s;

		for (char c = '0'; c <= '9'; c++) {
			int ans = 0;
			for (int rot_r = 0; rot_r < 2; rot_r++) {
				for (int rot_c = 0; rot_c < 2; rot_c++) {
					int r = INT_MAX;
					for (int i = 0; i < n; i++) {
						int mx_c = INT_MIN, mn_c = INT_MAX;
						for (int j = 0; j < n; j++) {
							if (a[i][j] == c) {
								mx_c = max(mx_c, j);
								mn_c = min(mn_c, j);
								r = min(r, i);
							}
						}
						if (mx_c == INT_MIN) continue;
						if (mn_c != mx_c) {
							ans = max(ans, (mx_c - mn_c) * i);
							if (r != i) {
								ans = max(ans, (n - 1 - mn_c) * (i - r));
								ans = max(ans, mx_c * (i - r));
							}
						} else {
							ans = max(ans, max(n - 1 - mx_c, mx_c) * (i - r));
						}
					}
					for (int i = 0; i < n / 2; i++) {
						for (int j = 0; j < n; j++) {
							swap(a[i][j], a[n - i - 1][j]);
						}
					}
				}
				for (int i = 0; i < n; i++) {
					for (int j = i; j < n; j++) {
						swap(a[i][j], a[j][i]);
					}
				}
			}
			cout << ans << ' ';
		}
		cout << '\n';
	}
	return 0;
}