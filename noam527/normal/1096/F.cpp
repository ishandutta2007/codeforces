#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

struct fenwick {
	int n;
	vector<int> tree;
	fenwick(int sz) {
		n = sz;
		tree.resize(n + 1, 0);
	}
	void upd(int pos) {
		for (; pos <= n; pos += (pos & -pos)) tree[pos]++;
	}
	int query(int val) {
		int rtn = 0;
		for (; val; val -= (val & -val)) rtn += tree[val];
		return rtn;
	}
};

ll pw(ll b, ll e) {
	ll rtn = 1;
	while (e) {
		if (e & 1) rtn = rtn * b % md;
		e /= 2, b = b * b % md;
	}
	return rtn;
}
ll inv(ll x) {
	return pw(x, md - 2);
}
int fact(int x) {
	ll rtn = 1;
	for (int i = 1; i <= x; i++) rtn = rtn * i % md;
	return rtn;
}

int n;
vector<int> a, b;
vector<int> no;

int count1() {
	ll ans = 0;
	fenwick F(n);
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] != -1) {
			ans += F.query(a[i]);
			F.upd(a[i]);
		}
	}
	return ans % md;
}
int count2() {
	int m = no.size();
	ll rtn = (ll)m * (m - 1) / 2;
	rtn %= md;
	rtn = rtn * fact(m) % md;
	rtn = rtn * inv(2) % md;
	return rtn % md;
}
int count3() {
	ll tot = no.size(), cnt = 0;
	vector<int> less(n + 1, 0);
	for (int i = 1; i <= n; i++) less[i] = 1 ^ b[i];
	for (int i = 1; i <= n; i++) less[i] += less[i - 1];
	ll rtn = 0, F = fact(tot - 1);
	for (auto &i : a) {
		if (i == -1) cnt++;
		else {
			ll G = tot - less[i];
			ll L = less[i];
			rtn = (rtn + G * cnt % md * F) % md;
			rtn = (rtn + L * (tot - cnt) % md * F) % md;
		}
	}
	return rtn % md;
}

int main() {
	fast;
	cin >> n;
	a.resize(n);
	b.resize(n + 1, 0);
	for (auto &i : a) {
		cin >> i;
		if (i != -1) {
			b[i] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
		if (!b[i]) no.push_back(i);

	ll ans = (ll)count1() * fact((int)no.size()) + count2() + count3();
	ans %= md;
	ans = ans * inv(fact((int)no.size())) % md;
	finish(ans);
}