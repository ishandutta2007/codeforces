#pragma GCC optimize ("O3")
#pragma GCC target ("sse4,avx")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <memory.h>
#include <iomanip>
#include <set>
#include <cassert>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1.5e18 + 123;

#define rep(i, s, t) for (auto i = (s); i < (t); ++(i))
#define per(i, s, t) for (auto i = (s); i >= (t); --(i))
#define sz(x) ((int) x.size())
#define all(x) (x).begin(), (x).end()

template<typename A, typename B> bool mini(A &x, const B &y) {
	if (y < x) {
		x = y;
		return 1;
	}
	return 0;
}

void run();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	run();
#ifdef _DEBUG
	cerr << "OK" << endl;
	while (1);
#endif
	return 0;
}

const int C = (int) 1e7 + 5;

ll t0;
ll a1, t1, p1;
ll a2, t2, p2;

ll calc(ll f, ll t) {
	if (f <= 0) {
		return 0;
	}
	if (t0 <= t1) {
		ll can = t / t0;
		if (can >= f) {
			return 0;
		}
		else {
			return LINF;
		}
	}
	if (t / t0 >= f) return 0;
	if (t / t1 < f) return LINF;
	ll b = (t0 * f - t + t0 - t1 - 1) / (t0 - t1);
	assert(0 <= b && b <= f);
	ll x = (b + a1 - 1) / a1;
	return x * p1;
}

void run() {
	ll f, t;
	cin >> f >> t >> t0;
	cin >> a1 >> t1 >> p1;
	cin >> a2 >> t2 >> p2;
	ll ans = LINF;
	rep(iter, 0, 2) {
		swap(t1, t2);
		swap(a1, a2);
		swap(p1, p2);
		mini(ans, calc(f, t));

		rep(x, 1, C) {
			ll step = a2 * t2;
			if (step > t) {
				continue;
			}
			ll need_t = step * x;
			if (need_t <= t) {
				mini(ans, p2 * x + calc(f - a2 * x, t - need_t));
			}
		}

		{
			ll can = t / t2;
			if (can >= f) {
				mini(ans, (can + a2 - 1) / a2 * p2);
			}
		}

		{
			ll can = t / t1;
			if (can >= f) {
				mini(ans, (can + a1 - 1) / a1 * p1);
			}
		}

		if (t / t0 >= f) ans = 0;
	}


	cout << (ans >= LINF - 100 ? -1 : ans) << "\n";
}