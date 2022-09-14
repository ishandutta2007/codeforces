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
	ll q, n;
	cin >> q;
	map<ll, ll> mp;
	rep(z, q) {
		cin >> n;
		ll t = 0;
		for (ll i = n; i > 0; i /= 2)
			t = t * 2 + 1;
		if (n < t) {
			cout << t << '\n';
			continue;
		}
		if (mp.count(n)) {
			cout << mp[n] << '\n';
			continue;
		}
		ll d = n;
		for (ll i = 2; i * i <= n; i++)
			if (n % i == 0) {
				d = i;
				break;
			}
		cout << n / d << '\n';
		mp[n] = n / d;
	}
}