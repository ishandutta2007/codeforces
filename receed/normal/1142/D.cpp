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
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

const int M = 11;
int dp[2][M][M][M], t1[M], t2[M][M], t4[M][M][M][M];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	rep(i, M) {
		t1[i] = (i + 1) % 11;
		rep(j, M) {
			t2[i][j] = (j + (i + j) * (j - i + 1 + 11) * 6) % 11;
			rep(k, M)
				rep(d, M)
					t4[i][k][j][d] = (k + (i + j + 10) * (j - i + 11) * 6 + d + 1) % 11;
		}
	}
	ll ans = 0;
	rep(i, n) {
		int d = s[i] - '0', r = i % 2, pr = 1 - r;
		rep(j, M)
			rep(k, M)
				memset(dp[r][j][k], 0, M * sizeof(int));
		rep(j, M)
			rep(k, M)
				for (int l = d + 1; l < M; l++)
					dp[r][t1[k]][t2[j][k]][t4[j][k][l][d]] += dp[pr][j][k][l];
		if (d > 0)
			dp[r][1][9][d]++;
		rep(j, M)
			rep(k, M)
				rep(l, M)
					ans += dp[r][j][k][l];
	}
	cout << ans;
}