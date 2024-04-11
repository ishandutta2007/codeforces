#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
vector<ll> a;
map<ll, ll> cache;

int check(ll v) {
	if (cache.count(v)) return cache[v];
	ll res = 0;
	for (auto &i : a) {
		ll m = i % v;
		if (m == i) res += v - m;
		else {
			res += min(m, v - m);
		}
		if (res >= n) return cache[v] = n;
	}
	return cache[v] = res;
}

vector<ll> calc(ll v) {
	vector<ll> ans;
	for (ll i = 2; i * i <= v; i++) {
		if (v % i == 0) {
			ans.push_back(i);
			while (v % i == 0) v /= i;
		}
	}
	if (v > 1)
		ans.push_back(v);
	return ans;
}

int rnd() {
	return ((rand() % (1 << 15)) << 15) + (rand() % (1 << 15));
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	srand(time(NULL));
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	int ans = n;
	
	int times = 20;
	while (times--) {
		int ind = rnd() % n;
		for (ll t = max(1LL, a[ind] - 1); t <= a[ind] + 1; t++) {
			vector<ll> f = calc(t);
			for (const auto &v : f)
				ans = min(ans, check(v));
		}
	}
	cout << ans << '\n';
}