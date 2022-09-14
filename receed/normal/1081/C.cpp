#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
 
typedef long long ll;
typedef long double ld;
using namespace std;

const int MOD = 998244353;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m, k;
	cin >> n >> m >> k;
	vector<vector<ll>> c(n, vector<ll>(k + 1, 0));
	for (ll i = 0; i < n; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= min(i, k); j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	}
	ll ans = c[n - 1][k] * m % MOD;
	for (int i = 0; i < k; i++)
		ans = ans * (m - 1) % MOD;
	cout << ans;
}