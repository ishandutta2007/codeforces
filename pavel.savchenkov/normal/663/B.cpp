#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

vi get_arr(ll x) {
	vi r;
	while (x) {
		r.pb(x % 10);
		x /= 10;
	}
	if (r.empty()) r.pb(0);
	return r;
}

ll get_num(const vi& r) {
	ll x = 0;
	ford(i, sz(r)) {
		x = x * 10 + r[i];
	}
	return x;
}

ll get_first(ll l, vi X) {
	vi L = get_arr(l);
	ll x = get_num(X);

	if  (sz(X) > sz(L)) {
		if  (X.back() == 0) {
			X.pb(1);
		}
		return get_num(X);
	}

	// 1
	{
		vi LL = L;
		while (sz(LL) > sz(X)) LL.pop_back();
		ll cur_l = get_num(LL);
		if  (x >= cur_l) {
			for (int i = sz(X); i < sz(L); ++i) {
				X.pb(L[i]);
			}
			return get_num(X);
		}
	}

	for (int i = sz(X); i < sz(L); ++i) {
		if  (L[i] != 9) {
			X.resize(sz(L));
			X[i] = L[i] + 1;
			for (int j = i - 1; j >= sz(X); --j) {
				X[j] = 0;
			}
			for (int j = i + 1; j < sz(L); ++j) {
				X[j] = L[j];
			}
			return get_num(X);
		}
	}

	while (sz(X) < sz(L)) {
		X.pb(0);
	}
	X.pb(1);
	return get_num(X);
}

ll solve(const vi& r) {
	int lx = sz(r);
	ll left = 1989;
	vi cur_r;
	forn(it, lx) {
		cur_r.pb(it < sz(r) ? r[it] : 0);
		left = get_first(left, cur_r) + 1;
	}
	return left - 1;
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	int q;
	scanf("%d\n", &q);
	while (q --> 0) {
		forn(it, 4) getchar();
		
		string s;
		getline(cin, s);
		vi rx;
		ford(i, sz(s)) {
			rx.pb(s[i] - '0');
		}

		cout << solve(rx) << '\n';
	}

	return 0;
}