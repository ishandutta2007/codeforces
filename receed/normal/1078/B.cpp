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

typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m = 101, w = 0;
	cin >> n;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[a[i]]++;
		w += a[i];
	}
	vector<vector<int>> dp(n + 1, vector<int>(w + 1));
	dp[0][0] = 1;
	for (int i = 0; i < m; i++) {
		if (!b[i])
			continue;
		for (int j = n - 1; j >= 0; j--)
			for (int k = 0; k < w; k++) {
				if (!dp[j][k])
					continue;
				for (int l = 1; l <= b[i]; l++)
					dp[j + l][k + l * i] = min(dp[j][k] + dp[j + l][k + l * i], 2);
			}
	}
	int ans = 0, d = 0;
	for (int i = 1; i < m; i++)
		if (b[i])
			d++;
	for (int i = 1; i < m; i++)
		for (int j = 1; j <= b[i]; j++)
			if (dp[j][i * j] == 1) {
				ans = max(ans, j);
				if (d == 2 && j == b[i])
					ans = n;
			}
	cout << ans;
}