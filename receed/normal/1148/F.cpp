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
	ll n;
	cin >> n;
	vector<pair<ll, ll>> a(n);
	ll sum = 0;
	rep(i, n) {
		cin >> a[i].first >> a[i].second;
		sum += a[i].first;
	}
	ll ms = 0, res = 0;
	for (int i = 0; i <= 61; i++) {
		ll s1 = 0, s2 = 0;
		rep(j, n)
			if (a[j].second < (1ll << (i + 1)) && (a[j].second & (1ll << i))) {
				if (__builtin_popcountll(a[j].second & ms) % 2)
					s1 += a[j].first;
				else
					s2 += a[j].first;
			}
		int fl = 0;
		if (s2 != s1)
			if (((s2 - s1) > 0) == (sum > 0))
				ms |= (1ll << i);
	}
	// ll ns = 0;
	// for (auto &pp : a) {
	// 	if (__builtin_popcountll(pp.second & ms) % 2)
	// 		ns -= pp.first;
	// 	else
	// 		ns += pp.first;
	// }
	// cout << ns << '\n';
	// assert((ns < 0 && sum > 0) || (ns > 0 && sum < 0));
	cout << ms;
}