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

using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair 
#define SZ(C) ((int) (C).size())
#define FORN(i, n) for (int i = 0; i < (int) n; ++i)
#define FORD(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define ALL(C) (C).begin(), (C).end()

template <typename T>
inline T sqr( T x ) {
	return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef vector <vector<pii> > vvii;

constexpr double EPS = 1e-9;
constexpr double M_PI = acos(1.0);
const int MAXN = 2 * int(1e5) + 10;
const int INF = int(1e9) + 10;

struct segm_tree {
	vi val;
	vi cnt;
	vi sum;
	int sz;

	segm_tree() {}

	segm_tree( const vii &a ) {
		sz = 1;
		while (sz < SZ(a)) sz *= 2;

		val.assign(sz * 2, 0);
		cnt.assign(sz * 2, 0);
		sum.assign(sz * 2, 0);

		FORN(i, SZ(a)) {
			val[sz + i] = a[i].F;
		}
	}

	void recalc( int v ) {
		sum[v] = sum[v * 2] + sum[v * 2 + 1];
		cnt[v] = cnt[v * 2] + cnt[v * 2 + 1];
	}

	void turn_on( int v, int tl, int tr, int pos ) {
		if  (tl == tr) {
			sum[v] += val[v];
			cnt[v] += 1;
			return;
		}

		int tm = (tl + tr) >> 1;
		if  (pos <= tm) {
			turn_on(v * 2, tl, tm, pos);
		} else {
			turn_on(v * 2 + 1, tm + 1, tr, pos);
		}

		recalc(v);
	}

	void turn_on( int pos ) {
		turn_on(1, 0, sz - 1, pos);
	}

	int get_sum( int v, int tl, int tr, int cnt_need ) {
		if  (tl == tr) {
			return cnt_need * val[v];
	   	}

	   	int tm = (tl + tr) >> 1;
	   	if  (cnt[v * 2] >= cnt_need) {
	   		return get_sum(v * 2, tl, tm, cnt_need);
	   	} else {
	   		return sum[v * 2] + get_sum(v * 2 + 1, tm + 1, tr, cnt_need - cnt[v * 2]);
	   	}                                                                       
	}

	int get_sum( int cnt_need ) {
		if  (cnt_need > cnt[1]) {
			return -1;
		}

		return get_sum(1, 0, sz - 1, cnt_need);
	}
};

vii events[MAXN];
vi cost[MAXN];
int our = 0;
segm_tree T;
vii C;

main() {
	int n;
	scanf("%d", &n);

	int sum_alive = 0;
	int cnt_alive = 0;
	FORN(i, n) {
		int a, b;
		scanf("%d%d", &a, &b);

		if  (a == 0) {
			++our;
		} else {
			C.PB(MP(b, a));
			cost[a].PB(b);
			sum_alive += b;
			++cnt_alive;	
		}
	}

	sort(ALL(C));
	T = segm_tree(C);

	FORN(i, MAXN) {
		sort(ALL(cost[i]));
		reverse(ALL(cost[i]));

		FORN(j, SZ(cost[i])) {
			events[j].PB(MP(cost[i][j], i));
		}
	}

	int ans = INF;

	if  (cnt_alive == 0) {
		ans = 0;
	}

	for (int level = 0; ; ++level) {
		int new_our = our + cnt_alive;
		int sum = sum_alive;

		if  (new_our <= level) {
			int cnt_need = level - new_our + 1;

			int add_sum = T.get_sum(cnt_need);

			if  (add_sum >= 0) {
				ans = min(ans, sum + add_sum);
			}
		} else {
			ans = min(ans, sum);	
		}	

		if  (events[level].empty()) {
			break;
		}

		FORN(i, SZ(events[level])) {
			int a = events[level][i].S;
			int b = events[level][i].F;

			--cnt_alive;
			sum_alive -= b;
			int pos = lower_bound(ALL(C), MP(b, a)) - C.begin();
			T.turn_on(pos);
		}
	}

	printf("%d\n", ans);
	return 0;
}