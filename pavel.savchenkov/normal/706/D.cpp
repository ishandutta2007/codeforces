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
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"


struct FenwTree {
	vi t;

	FenwTree(int n = 0) {
		t.assign(n, 0);
	}

	void upd(int pos, int add) {
		for (int i = pos; i < sz(t); i |= i + 1) {
			t[i] += add;
		}
	}

	int get(int r) {
		int s = 0;
		for (int i = r; i >= 0; i &= i + 1, --i) {
			s += t[i];
		}
		return s;
	}

	int get(int l, int r) {
		return get(r) - get(l - 1);
	}
};

struct Query {
	char type;
	int x;

	void read() {
		type = getchar();
		scanf("%d\n", &x);
	}
};

vector<Query> qs;
int cnt_q;

FenwTree T;
vi vals;

void upd_val(int x, int coef) {
	x = lower_bound(all(vals), x) - vals.begin();
	T.upd(x, coef);
}

const int B = 31;

void print() {
	for (int x : vals) cout << x << " ";
	cout << endl;
	forn(i, sz(vals)) {
		cout << T.get(i, i) << " ";
	}
	cout << endl;
}

bool have_val(int L, int R) {
	int l = lower_bound(all(vals), L) - vals.begin();
	int r = upper_bound(all(vals), R) - vals.begin();
	--r;

	if  (l > r) {
		return false;
	}

	bool ans = T.get(l, r) > 0;
	if  (!ans) {
		return false;
	}
	// printf("have [%d, %d]\n", L, R);
	return true;
}

int get_max(int x) {
	int l = 0;
	int r = (1u << B) - 1;
	int ans = 0;
	for (int b = B - 1; b >= 0; --b) {
		int have = (x >> b) & 1;
		int mid = l + (1 << b) - 1;
		assert(mid - l == r - mid - 1);
		if  (have) {
			if  (have_val(l, mid)) {
				r = mid;
				ans ^= 1 << b;
			} else {
				l = mid + 1;
			}
		} else {
			if  (have_val(mid + 1, r)) {
				l = mid + 1;
				ans ^= 1 << b;
			} else {
				r = mid;
			}
		}
	}
	return ans;
}	

void solve() {
	scanf("%d\n", &cnt_q);
	forn(i, cnt_q) {
		Query cur;
		cur.read();
		qs.pb(cur);
		vals.pb(cur.x);
	}
	vals.pb(0);
	
	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());

	T = FenwTree(sz(vals));

	upd_val(0, +1);

	for (const auto& q : qs) {
		if  (q.type == '+') {
			upd_val(q.x, +1);
		} else if  (q.type == '-') {
			upd_val(q.x, -1);
		} else {
			// print();
			printf("%d\n", get_max(q.x));
		}
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}