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
		int n, c0, c1, h;
		cin >> n >> c0 >> c1 >> h;

		string s;
		cin >> s;

		array<int, 2> cnt = {0};
		for (char ch : s) {
			cnt[ch - '0']++;
		}

		int ans = INT_MAX;
		for (int i = 0; i <= n; i++) {
			int j = n - i;
			ans = min(ans, (h * abs(cnt[0] - i) + h * abs(cnt[1] - j)) / 2 + c0 * i + c1 * j);
		}
		cout << ans << '\n';
	}
	return 0;
}