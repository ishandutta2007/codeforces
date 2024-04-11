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

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, X;
	cin >> n >> X;

	vector<int> c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		c[i] = (n - i) * c[i];
	}

	sort(c.begin(), c.end());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (c[i] > X) {
			break;
		}
		X -= c[i];
		ans++;
	}
	cout << ans << '\n';
	return 0;
}