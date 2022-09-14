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

const int N = 5001;
int z[N], mp[N], dp[N];
char s[N];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	// ios_base::sync_with_stdio(0); cin.tie(0);
	int n, a, b;
	cin >> n >> a >> b >> s;
	rep(i, n) {
		for (int j = 1, l = 0, r = 0; i + j < n; j++) {
			z[j] = max(0, min(r - j + 1, z[j - l]));
			while (i + j + z[j] < n && s[i + z[j]] == s[i + j + z[j]])
				z[j]++;
			if (j + z[j] - 1 > r) {
				r = j + z[j] - 1;
				l = j;
			}
			mp[i + j] = max(mp[i + j], min(j, z[j]));
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		dp[i] = a + dp[i + 1];
		if (mp[i] > 0)
			dp[i] = min(dp[i], b + dp[i + mp[i]]);
	}
	cout << dp[0];
}