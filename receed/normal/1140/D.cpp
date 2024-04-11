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

const int N = 502;
ll dp[N][N];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;	
	rep(i, n)
		dp[i][3] = (i + 1) * ((i + 1) % n + 1) * ((i + 2) % n + 1);
	for (int i = 4; i <= n; i++)
		for (int l = 0, r = i - 1; l < n; l++, r = (r + 1) % n) {
			dp[l][i] = 1e13;
			for (int j = 1; j < i; j++) {
				int x = (l + j) % n;
				dp[l][i] = min(dp[l][i], dp[l][j + 1] + dp[x][i - j] + (l + 1) * (x + 1) * (r + 1));
			}
		}
	cout << dp[0][n] << '\n';
}