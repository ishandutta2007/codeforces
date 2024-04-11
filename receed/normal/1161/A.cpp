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

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(k), b(n, -1), c(n, -1);
	rep(i, k) {
		cin >> a[i];
		a[i]--;
		c[a[i]] = i;
		if (b[a[i]] == -1)
			b[a[i]] = i;
	}
	int ans = 0;
	rep(i, n) {
		if (b[i] == -1)
			ans++;
		if (i < n - 1) {
			if (b[i] == -1 || b[i + 1] == -1)
				ans += 2;
			else if (c[i] < b[i + 1] || c[i + 1] < b[i])
				ans++;
		}
	}
	cout << ans;
}