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

int binp(int b) {
	if (!b) return 1;
	if (b & 1) return 2 * binp(b - 1) % mod;
	int t = binp(b / 2);
	return t * t % mod;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout << fixed << setprecision(6);
    
	int x, y; cin >> x >> y;
	if (y % x) {
		cout << "0\n";
		return 0;
	}
	vector <int> dels;
	y /= x;
	for (int i = 1; i * i <= y; ++i) {
		if (y % i == 0) {
			dels.push_back(i);
			if (i * i != y) dels.push_back(y / i);
		}
	}
	sort(dels.rbegin(), dels.rend());
	vector <int> dp(dels.size(), 0);
	for (int i = 0; i < dels.size(); ++i) {
		dp[i] = (dp[i] + binp(y / dels[i] - 1)) % mod;
		for (int j = i + 1; j < dels.size(); ++j) {
			if (dels[i] % dels[j] == 0)
				dp[j] = (dp[j] - dp[i] + mod) % mod;
		}
	}


	cout << dp.back() << '\n';
	return 0;
}