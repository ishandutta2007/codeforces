#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <sstream>
#include <deque>
#include <queue>
#include <random>
#include <cassert>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define RANDOM srand(94385)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define f first
#define s second
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
#define sz(a) signed(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }

struct pt {
	ll a, b, c;
	ll val() const {
		return a * a + b * b + c * c;
	}
	ll operator[](int ind) {
		if (ind == 0) return a;
		if (ind == 1) return b;
		if (ind == 2) return c;
	}
};

bool operator<(pt a, pt b) {
	if (a.a != b.a) return a.a < b.a;
	if (a.b != b.b) return a.b < b.b;
	return a.c < b.c;
}

bool in(ll c, ll a, ll b) {
	if (a > b) swap(a, b);
	return a <= c && c <= b;
}

bool in(pt c, pt a, pt b) {
	return in(c.a, a.a, b.a) && in(c.b, a.b, b.b) && in(c.c, a.c, b.c);
}

signed main() {
	FAST; FIXED; RANDOM;
	int n;
	cin >> n;
	vector<pair<pt, int>> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].f.a >> a[i].f.b >> a[i].f.c;
		a[i].s = i; 
	}
	sort(a);
	map<int, vector<pair<pt, int>>> st;
	for (auto i : a)
		st[i.f.a].pb(i);
	vector<pair<pt, int>> left;
	for (auto &i : st) {
		auto &v = i.s;
		sort(all(v), [](const auto &a, const auto &b) {
			if (a.f.b != b.f.b) return a.f.b < b.f.b;
			return a < b;
		});
		vector<bool> used(sz(v));
		for (int j = 0; j < sz(v) - 1; ++j) {
			if (v[j].f.b == v[j + 1].f.b) {
				cout << v[j].s + 1 << ' ' << v[j + 1].s + 1 << '\n';
				used[j] = used[j + 1] = true;
				++j;
			}
		}
		vector<pair<pt, int>> copy;
		for (int i = 0; i < sz(v); ++i) 
			if (!used[i]) copy.pb(v[i]);
		v = copy;
		
		sort(all(v), [](const auto &a, const auto &b) {
			if (a.f.c != b.f.c) return a.f.c < b.f.c;
			return a < b;
		});
		used = vector<bool> (sz(v));
		for (int j = 0; j < sz(v) - 1; ++j) {
			if (v[j].f.c == v[j + 1].f.c) {
				cout << v[j].s + 1 << ' ' << v[j + 1].s + 1 << '\n';
				used[j] = used[j + 1] = true;
				++j;
			}
		}
		copy.clear();
		for (int i = 0; i < sz(v); ++i) 
			if (!used[i]) copy.pb(v[i]);
		v = copy;

		sort(v);
		while (sz(v) >= 2) {
			auto b = v.back();
			v.popb();
			auto c = v.back();
			v.popb();
			cout << b.s + 1 << ' ' << c.s + 1 << '\n';
		}
		if (sz(v)) left.pb(v[0]);
	}
	for (int i = 0; i < sz(left); i += 2)
		cout << left[i].s + 1 << ' ' << left[i + 1].s + 1 << '\n';
	return 0;
}