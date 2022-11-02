#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
#include <numeric>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

ll a, b;

unordered_map<ll, ll> getDivisors(ll x) {
	unordered_map<ll, ll> ans;
	for (ll i = 2; i * i <= x; i++) {
		if (x%i == 0) {
			int cnt = 0;
			while (x%i == 0) {
				cnt++;
				x /= i;
			}
			ans.insert(mp(i, cnt));
		}
	}
	if (x != 1)ans.insert(mp(x, 1));
	return ans;
}

ll foo(ll a, ll b) {
	if (!b)return 0;
	return 1 + foo(a, b - gcd(a, b));
}

ll solve(ll a, ll b) {
	unordered_map<ll, ll> v = getDivisors(a);
	ll res = b / a;
	b %= a;//???
	while (b > 0) {
		if (a == 1) {
			res += b;
			break;
		}
		ll mnDist = 1e18, mnDiv = -1;
		for (auto x : v) {
			if (!x.second)continue;
			if (b % x.first == 0) {
				mnDist = 0;
				mnDiv = x.first;
			}
			else if (mnDist > b - x.first*(b / x.first)) {
				mnDist = b - x.first * (b / x.first);
				mnDiv = x.first;
			}
		}
		res += mnDist;
		b -= mnDist;
		ll g = gcd(b, a);
		a /= g;
		b /= g;
		unordered_map<ll, ll> gmap = getDivisors(g);
		for (auto x : gmap) {
			v[x.first] -= x.second;
			if (!v[x.first])v.erase(x.first);
		}
	}
	return res;
}

int main() {
	fast;
	ll x, y;
	cin >> x >> y;
	cout << solve(x, y) << endl;
	return 0;
}