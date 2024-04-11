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

	int n, m, k;
	cin >> n >> m >> k;

	string ans;
	for (int i = 0; i < n - 1; i++) {
		ans += 'U';
	}

	for (int i = 0; i < m - 1; i++) {
		ans += 'L';
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			ans += (i & 1 ? 'L' : 'R');
		}
		if (i + 1 != n) {
			ans += 'D'; //n - 1 + m - 1 + n * (m - 1) + n - 1 = n + m - 3 + n * m
		}
	}
	cout << ans.length() << '\n' << ans << '\n';
	return 0;
}