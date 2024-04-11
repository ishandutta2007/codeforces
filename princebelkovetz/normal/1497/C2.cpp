#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cassert>

using namespace std;
#define int long long 
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
const int mod = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(3);
	int tt; cin >> tt;
	while (tt--) {
		int n, k; cin >> n >> k;
		for (int i = 0; i < k - 3; ++i) cout << "1 ";
		n -= k - 3;
		if (n % 2 == 1) {
			cout << 1 << ' ' << n / 2 << ' ' << n / 2 << '\n';
		}
		else {
			if (n == 4) {
				cout << "2 1 1\n";
			}
			else if ((n / 2 - 1) & 1) {
				cout << n / 2 << ' ' << n / 4 << ' ' << n / 4 << '\n';
			}
			else {
				cout << n / 2 - 1 << ' ' << n / 2 - 1 << ' ' << 2 << '\n';
			}
		}
	}
}