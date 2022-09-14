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
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1000003;
int a[N], dp[N][3][5];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, t;
	cin >> n >> m;
	rep(i, n) {
		cin >> t;
		a[t - 1]++;
	}
	rep(i, m + 1)
		rep(t1, 3)
			rep(t2, 5)
				dp[i][t1][t2] = -N;
	dp[0][0][0] = 0;	
	rep(i, m) {
		rep(t1, 3)
			rep(t2, 5)
				rep(t3, 5)
					rep(x, min(min(t1, t2) + 1, min(3, a[i] - t3 + 1)))
						dp[i + 1][min(t2 - x, 2)][t3] = max(dp[i + 1][min(t2 - x, 2)][t3], dp[i][t1][t2] + (a[i] - t3 - x) / 3 + x);
	}
	int ans = 0;
	rep(i, 3)
		rep(j, 5)
			ans = max(ans, dp[m][i][j]);
	cout << ans;
}