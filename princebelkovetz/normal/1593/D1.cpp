#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <string>
#include <unordered_map>
#include <iomanip>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7, N = 5e5 + 3;
const ld eps = 1e-7;

int gcd(int a, int b) {
	return (b ? gcd(b, a % b) : a);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout << fixed << setprecision(6);
    
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		int ans = 0;
		for (int i = 1; i < n; ++i) {
			ans = gcd(ans, abs(a[i] - a[i - 1]));
		}
		cout << (!ans ? -1 : ans) << '\n';
	}

	return 0;
}