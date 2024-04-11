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

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(n), b(n - 1);
	rep(i, n) {
		cin >> a[i];
		if (i > 0)
			b[i - 1] = a[i] - a[i - 1];
	}
	sort(all(b));
	ll ans = k;
	rep(i, n - k)
		ans += b[i];
	cout << ans;
}