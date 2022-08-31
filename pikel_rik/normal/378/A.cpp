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

	int a, b;
	cin >> a >> b;

	int ans[3] = {0};
	for (int i = 1; i <= 6; i++) {
		if (abs(a - i) < abs(b - i)) {
			ans[0]++;
		} else if (abs(a - i) > abs(b - i)) {
			ans[2]++;
		} else {
			ans[1]++;
		}
	}

	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
	return 0;
}