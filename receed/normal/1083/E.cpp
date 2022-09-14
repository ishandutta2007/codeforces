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
#define rep(i, n) for (ll i = 0; i < (n); i++)
 
typedef long long ll;
typedef long double ld;
using namespace std;

ll f(pair<ll, ll> p, ll x) {
	return p.first * x + p.second;
}

bool td(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3) {
	ld ax = (ld) (p1.second - p2.second) / (p2.first - p1.first);
	ld bx = (ld) (p3.second - p2.second) / (p2.first - p3.first);
	return ax < bx;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<pair<ll, ll>> s {{0, 0}};
	vector<vector<ll>> a(n, vector<ll>(3));
	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	sort(a.begin(), a.end());
	int pos = 0;
	ll ans = 0;
	for (auto &p : a) {
		pos = min(pos, (int) s.size() - 1);
		while (pos + 1 < s.size() && f(s[pos], p[1]) <= f(s[pos + 1], p[1]))
			pos++;
		ll cd = f(s[pos], p[1]) + p[0] * p[1] - p[2];
		ans = max(ans, cd);
		pair<ll, ll> np = {-p[0], cd};
		while (s.size() > 1 && td(s[s.size() - 2], s.back(), np))
			s.pop_back();
		s.push_back(np);
	}
	cout << ans;
}