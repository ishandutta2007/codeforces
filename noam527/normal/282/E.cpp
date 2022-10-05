#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

int n;
vector<ll> a;
ll X = 0;

bool can(ll v, const ll div) {
	v /= div;
	if (v == 0) return true;
	set<ll> A;
	A.insert(0);
	for (int i = 1; i < n; i++) {
		if (A.count(v ^ (a[i] / div))) return true;
		A.insert(a[i] / div);
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i, X ^= i;
	n++;
	a.insert(a.begin(), 0LL);
	for (int i = 1; i < n; i++) a[i] ^= a[i - 1];

	ll res = 0;
	for (ll i = 50; i >= 0; i--) {
		if (X & (1LL << i)) {
			if (!can(res, (1LL << i))) res ^= 1LL << i;
		}
		else {
			if (can(res ^ (1LL << i), 1LL << i)) res ^= 1LL << i;
		}
	}
	cout << (X ^ res) << '\n';
}