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

	int a1, a2, a3, b1, b2, b3, n;
	cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;

	bool possible = false;
	for (int i = 0; i <= n; i++) {
		if ((a1 + a2 + a3) <= 5 * i && (b1 + b2 + b3) <= 10 * (n - i)) {
			possible = true;
		}
	}

	cout << (possible ? "YES" : "NO") << '\n';
	return 0;
}