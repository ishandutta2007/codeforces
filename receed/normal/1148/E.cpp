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
	int n, x;
	cin >> n;
	vector<vector<ll>> ans;
	deque<pair<ll, ll>> b(n);
	deque<ll> a(n);
	ll sa = 0, sb = 0;
	rep(i, n) {
		cin >> b[i].first;
		b[i].second = i + 1;
		sb += b[i].first;
	}
	rep(i, n) {
		cin >> a[i];
		sa += a[i];
	}
	if (sa != sb) {
		cout << "NO";
		return 0;
	}
	sort(all(b));
	sort(all(a));
	set<vector<ll>> b1, b2;
	rep(i, n) {
		ll cd = a[i] - b[i].first;
		if (cd > 0)
			b1.insert({b[i].first, cd, b[i].second});
		else if (cd < 0)
			b2.insert({b[i].first, -cd, b[i].second});
	}
	int res = 0;
	while (!b1.empty() || !b2.empty()) {
		if (b1.empty() || b2.empty()) {
			cout << "NO";
			return 0;
		}
		vector<ll> v1 = *b1.begin(), v2 = *b2.begin();
		if (v1[1] == 0) {
			b1.erase(b1.begin());
		}
		else if (v2[0] == 0) {
			b2.erase(b2.begin());
		}
		else if (v1[0] > v2[0] || v1[0] + v1[1] > v2[0] - v2[1]) {
			cout << "NO";
			return 0;
		}
		else {
			ll d = min(v1[1], v2[1]);
			b1.erase(b1.begin());
			b2.erase(b2.begin());
			v1[1] -= d;
			v2[1] -= d;
			v1[0] += d;
			v2[0] -= d;
			ans.push_back({v1[2], v2[2], d});
			if (v1[1] > 0)
				b1.insert(v1);
			if (v2[1] > 0)
				b2.insert(v2);
		}
	}
	cout << "YES\n" << ans.size() << '\n';
	rep(i, ans.size()) {
		rep(j, 3)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}		
}