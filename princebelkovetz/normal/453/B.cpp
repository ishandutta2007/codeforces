#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#define int long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int inf = 1e9 + 7;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int n; cin >> n;
	vector <int> a(n);
	for (auto& x : a) cin >> x;
	vector <int> prime;
	for (int i = 2; i < 61; ++i) {
		bool c = true;
		for (int j = 2; j * j <= i; ++j) {
			if (i % j == 0) {
				c = false; break;
			}
		}
		if (c) prime.push_back(i);
	}
	vector <int> fact(61);
	for (int i = 2; i < 61; ++i) {
		for (int j = 0; j < 17; ++j) {
			if (i % prime[j] == 0) {
				fact[i] += (1 << j);
			}
		}
	}
	int b = (1 << 17);
	vector <vector <int>> dp(n + 1, vector <int>(b, inf));
	vector <vector <int>> prev(n + 1, vector <int>(b, 0));
	for (auto &x : dp[0])
		x = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 60; ++j) {
			int x = (~fact[j]) & (b - 1);
			for (int s = x; ; s = (s - 1) & x) {
				if (dp[i - 1][s] + abs(a[i - 1] - j) < dp[i][(s | fact[j])]){
					dp[i][(s | fact[j])] = dp[i - 1][s] + abs(a[i - 1] - j);
					prev[i][(s | fact[j])] = j;
				}
				if (!s) break;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < b; ++i) {
		if (dp[n][ans] > dp[n][i])
			ans = i;
	}
	vector <int> res(n);
	int cur = n - 1;
	while (cur >= 0) {
		res[cur] = prev[cur + 1][ans];
		ans -= fact[res[cur--]];
	}
	for (auto x : res) cout << x << ' ';
	cout << '\n';
	return 0;
}