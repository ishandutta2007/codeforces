#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <set>
#include <map>
#include <random>

typedef long long ll;
typedef long double ld;
using namespace std;

const int N = 300002, MOD = 1e9 + 9;
int used[N], d[N];
ll c[8][N], dp[N];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, t, g = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		used[t] = 1;
		g = __gcd(g, t);
	}
	if (g > 1) {
		cout << -1;
		return 0;
	}
	for (int i = 1; i < N; i++)
		for (int j = i; j < N; j += i)
			d[i] += used[j];
	for (int i = 0; i < N; i++)
		c[0][i] = 1;
	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < N; j++) {
			c[i][j] = c[i][j - 1] + c[i - 1][j - 1];
			if (c[i][j] >= MOD)
				c[i][j] -= MOD;
		}
		for (int j = N - 1; j > 0; j--) {
			dp[j] = c[i][d[j]];
			for (int k = j * 2; k < N; k += j) {
				dp[j] -= dp[k];
				if (dp[j] < 0)
					dp[j] += MOD;
			}
		}
		if (dp[1] != 0) {
			cout << i;
			return 0;
		}
	}
}