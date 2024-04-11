#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

bool is2(ll x) {
	ll a = sqrtl(x);
	return a * a == x;
}
bool is3(ll x) {
	ll a = cbrtl(x);
	return a * a * a == x;
}
bool is4(ll x) {
	ll a = sqrtl(sqrtl(x));
	return a * a * a * a == x;
}
bool isprime(ll x) {
	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0) return false;
	return true;
}

int d(ll x) {
	if (is4(x) && isprime(sqrtl(sqrtl(x)))) return 5;
	if (is2(x) && isprime(sqrtl(x))) return 3;
	return 4;
}

ll gcd(ll x, ll y) {
	if (!y) return x;
	return gcd(y, x % y);
}

int n;
map<ll, int> a, m;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (ll i = 0, x, y; i < n; i++) {
		cin >> x;
		y = d(x);
		if (y == 3) m[(ll)sqrtl(x)] += 2;
		else if (y == 5) m[(ll)sqrtl(sqrtl(x))] += 4;
		else {
			if (is3(x)) m[(ll)cbrtl(x)] += 3;
			else a[x]++;
		}
	}
	ll ans = 1, g;
	bool b;
	for (auto it1 = a.begin(); it1 != a.end(); it1++) {
		b = false;
		for (auto it2 = a.begin(); !b && it2 != a.end(); it2++) {
			if (it1 != it2) {
				g = gcd(it1->first, it2->first);
				if (g != 1) {
					b = true;
					m[g] += it1->second;
					m[it1->first / g] += it1->second;
				}
			}
		}
		if (!b) {
			for (auto &i : m) {
				if (!b && it1->first % i.first == 0) {
					b = true;
					m[i.first] += it1->second;
					m[it1->first / i.first] += it1->second;
				}
			}
		}
		if (!b) {
			ans = ans * ll(it1->second + 1) % md;
			ans = ans * ll(it1->second + 1) % md;
		}
	}
	for (auto &i : m)
		ans = ans * (ll)(i.second + 1) % md;
	cout << ans << endl;
	fflush(stdout);
}