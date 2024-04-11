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

	int n, a;
	cin >> n >> a; --a;

	vector<int> t(n);
	for (int i = 0; i < n; i++) cin >> t[i];

	int ans = t[a];
	for (int dist = 1; dist <= n && (a - dist >= 0 || a + dist < n); dist++) {
		if ((a - dist < 0 || t[a - dist]) && (a + dist >= n || t[a + dist])) {
			ans += (a - dist >= 0) + (a + dist < n);
		}
	}
	cout << ans << '\n';
	return 0;
}