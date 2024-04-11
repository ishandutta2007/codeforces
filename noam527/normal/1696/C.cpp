#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = (int)1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

int n, m, k;
vector<ll> a, b;

vector<pair<ll, ll>> fix(const vector<ll> &c) {
	vector<pair<ll, ll>> res;
	for (auto &i : c) {
		ll x = i;
		ll c = 1;
		while (x % m == 0) {
			x /= m;
			c *= m;
		}
		res.emplace_back(x, c);
	}
	vector<pair<ll, ll>> res2;
	for (auto &i : res) {
		if (res2.size() == 0 || res2.back().first != i.first)
			res2.push_back(i);
		else
			res2.back().second += i.second;
	}
	return res2;
}

void solve() {
	cin >> n >> m;
	a.resize(n);
	for (auto &i : a) cin >> i;
	cin >> k;
	b.resize(k);
	for (auto &i : b) cin >> i;
	auto fa = fix(a);
	auto fb = fix(b);
	if (fa == fb) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}