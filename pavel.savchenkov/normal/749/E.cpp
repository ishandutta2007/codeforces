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
#include <numeric>

using namespace std;

#define ws ws_____________________
#define y1 y1_____________________
#define y0 y0_____________________
#define left left_________________
#define right right_______________
#define next next_________________
#define prev prev_________________
#define hash hash_________________

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;

#define FILE_NAME "a"

const int MAXN = 1e5 + 10;

int n;
int p[MAXN];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	forn(i, n) {
		scanf("%d", &p[i]);
		--p[i];
	}
	return 1;
}

struct FenwTree {
	vector<ll> t;

	FenwTree(int n = 0) {
		t.assign(n, 0);
	}

	ll get(int r) {
		ll res = 0;
		for (int i = r; i >= 0; i &= i + 1, --i) {
			res += t[i];
		}
		return res;
	}

	ll get(int l, int r) {
		return get(r) - get(l - 1);
	}

	void upd(int pos, ll val) {
		for (int i = pos; i < sz(t); i |= i + 1) {
			t[i] += val;
		}
	}
};

FenwTree T_cnt;
FenwTree T_sum;

ld solve() {
	T_cnt = FenwTree(n);
	T_sum = FenwTree(n);

	ld ans = 0;
	forn(j, n) {
		ans += T_sum.get(0, n - 1) * 1.0 * (n - j) / n / (n + 1);

		ans += T_cnt.get(p[j] + 1, n - 1);
		ans -= T_sum.get(p[j] + 1, n - 1) * 1.0 * (n - j) / n / (n + 1) * 2;

		T_cnt.upd(p[j], +1);
		T_sum.upd(p[j], j + 1);
	}

	return ans;
}

ld brut() {
	ld ans = 0;
	forn(j, n) {
		forn(i, j) {
			ans += (i + 1) * (n - j) * 1.0 / n / (n + 1);
			if  (p[i] > p[j]) {
				ld cur = (i + 1) * (n - j);
				cur = n * (n + 1) / 2 - cur;
				ans += cur / (n * (n + 1) / 2);
			}
		}
	}
	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif


	while (read()) {
		// printf("%.15f\n", (double) brut());
		printf("%.15f\n", (double) solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}