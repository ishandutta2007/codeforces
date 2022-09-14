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

const int N = 1 << 17;
ll t1[2][N * 2], m1[2][N * 2], a[N];
int t2[13][N * 2];
vector<pair<ll, int>> mf;
map<ll, ll> dnum;
ll n, mod, phi;

ll mulm(ll x, ll y) {
	return x * y % mod;
}
ll addm(ll x, ll y) {
	return (x + y) % mod;
}
ll pw(ll x, ll k) {
	ll ans = 1;
	for (int i = 29; i >= 0; i--) {
		ans = ans * ans % mod;
		if (k & (1 << i))
			ans = ans * x % mod;
	}
	return ans;
	// if (!k)
	// 	return 1;
	// if (k % 2)
	// 	return pw(x, k - 1) * x % mod;
	// return pw(x * x % mod, k / 2);
}
ll rev(ll x) {
	return pw(x % mod, phi - 1);
}
ll factor(ll x, vector<pair<ll, int>> &v) {
	ll nx = 1;
	v.clear();
	for (ll i = 2; i * i <= x; i++) {
		if (x % i)
			continue;
		v.push_back({i, 0});
		while (x % i == 0) {
			if (mod % i)
				nx *= i;
			x /= i;
			v.back().second++;
		}
	}
	if (x > 1) {
		if (mod % x)
			nx *= x;
		v.push_back({x, 1});
	}
	return nx;
}

void push1(int t, int v) {
	t1[t][v] = mulm(t1[t][v], m1[t][v]);
	if (v < N) {
		m1[t][v * 2] =  mulm(m1[t][v * 2], m1[t][v]);
		m1[t][v * 2 + 1] = mulm(m1[t][v * 2 + 1], m1[t][v]);
	}
	m1[t][v] = 1;
}
void rel1(int t, int v) {
	t1[t][v] = addm(t1[t][v * 2], t1[t][v * 2 + 1]);
}
void add1(int t, int cl, int cr, ll x, int v=1, int l=0, int r=N) {
	if (cr <= l || r <= cl) {
		push1(t, v);
		return;
	}
	if (cl <= l && r <= cr) {
		m1[t][v] = mulm(m1[t][v], x);
		push1(t, v);
		return;
	}
	push1(t, v);
	add1(t, cl, cr, x, v * 2, l, (l + r) / 2);
	add1(t, cl, cr, x, v * 2 + 1, (l + r) / 2, r);
	rel1(t, v);
}
ll sum1(int t, int cl, int cr, int v=1, int l=0, int r=N) {
	if (cr <= l || r <= cl) {
		push1(t, v);
		return 0;
	}
	if (cl <= l && r <= cr) {
		push1(t, v);
		return t1[t][v];
	}
	push1(t, v);
	ll ans = addm(sum1(t, cl, cr, v * 2, l, (l + r) / 2), sum1(t, cl, cr, v * 2 + 1, (l + r) / 2, r));
	rel1(t, v);
	return ans;
}

void add2(int t, int cl, int cr, ll x, int v=1, int l=0, int r=N) {
	if (cr <= l || r <= cl)
		return;
	if (cl <= l && r <= cr) {
		t2[t][v] += x;
		return;
	}
	add2(t, cl, cr, x, v * 2, l, (l + r) / 2);
	add2(t, cl, cr, x, v * 2 + 1, (l + r) / 2, r);
}
ll sum2(int t, int v) {
	ll ans = 0;
	for (int i = N + v; i; i /= 2)
		ans += t2[t][i];
	return ans;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> mod;
	factor(mod, mf);
	assert(mf.size() < 13);
	phi = mod;
	rep(i, N * 2)
		m1[0][i] = m1[1][i] = 1;
	rep(i, (int) mf.size()) {
		dnum[mf[i].first] = i;
		phi = phi / mf[i].first * (mf[i].first - 1);
	}
	vector<pair<ll, int>> ff;
	rep(i, n) {
		cin >> a[i];
		ll nx = factor(a[i], ff);
		t1[0][N + i] = a[i] % mod;
		t1[1][N + i] = nx % mod;
		for (auto &pp : ff)
			if (mod % pp.first == 0)
				t2[dnum[pp.first]][N + i] = pp.second;
	}
	for (int i = N - 1; i > 0; i--) {
		rel1(0, i);
		rel1(1, i);
	}
	ll q, t, l, r, x;
	cin >> q;
	rep(i, q) {
		cin >> t >> l;
		l--;
		if (t == 1) {
			cin >> r >> x;
			ll nx = factor(x, ff);
			add1(0, l, r, x % mod);
			add1(1, l, r, nx % mod);
			for (auto &pp : ff)
				if (mod % pp.first == 0) {
					add2(dnum[pp.first], l, r, pp.second);
				}
		}
		else if (t == 2) {
			cin >> x;
			ll nx = rev(factor(x, ff) % mod);
			add1(1, l, l + 1, nx);
			ll px = sum1(1, l, l + 1);
			rep(j, (int) ff.size())
				if (mod % ff[j].first == 0)
					t2[dnum[ff[j].first]][N + l] -= ff[j].second;
			rep(j, (int) mf.size()) {
				ll ppx = sum2(j, l);
				px = mulm(px, pw(mf[j].first % mod, ppx));	
			}
			add1(0, l, l + 1, 1);
			t1[0][N + l] = px;
			for (int j = (N + l) / 2; j; j /= 2)
				rel1(0, j);
		}
		else {
			cin >> r;
			cout << sum1(0, l, r) % mod << '\n';
		}
	}
}