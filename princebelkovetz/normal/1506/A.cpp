#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iomanip>

using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
const int mod = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n, m, x; cin >> n >> m >> x;
		x--;
		int i = x % n, j = x / n;
		cout << i * m + j + 1 << '\n';
	}
	return 0;
}