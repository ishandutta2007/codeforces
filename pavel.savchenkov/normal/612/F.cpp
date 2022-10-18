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
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

const ld EPS = 1e-9;
const int MAXN = 2e3 + 10;
const int INF = 1e9;
const int LEFT = 0;
const int RIGHT = 1;

int a[MAXN];
int ca[MAXN];
int n, s;
int dp[MAXN][2];
vi c;
vi pos[MAXN];
int dir[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &s) < 2) {
		return false;
	}
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	return true;
}

int dist_right(int i, int j) {
	// i + x == j mod n
	return (j - i + n) % n;
}

int dist_left(int i, int j) {
	// i - x == j mod n
	return (i - j + n) % n;
}

int dist(int i, int j) {
	return min(dist_left(i, j), dist_right(i, j));
}

void calc(int i, int w) {
	int& res = dp[i][w];
	res = INF;
	if  (w == 1) {
		if  (ca[i] == sz(c) - 1) {
			res = 0;
			return;
		}
		forn(j, n) {
			if  (ca[j] == ca[i] + 1) {
				res = min(res, dist(i, j) + dp[j][0]);
			}
		}
	} else {
		const vi& p = pos[ca[i]];
		int my_pos = lower_bound(all(p), i) - p.begin();
		// right
		int jj = my_pos;
		forn(it, sz(p)) {
			int ri = p[(jj + 1) % sz(p)];
			int cur = dist_right(i, p[jj]) + dist_left(p[jj], ri);
			res = min(res, cur + dp[ri][1]);
			jj = (jj + 1) % sz(p);
		}

		// left
		jj = my_pos;
		forn(it, sz(p)) {
			int li = p[(jj - 1 + sz(p)) % sz(p)];
			int cur = dist_left(i, p[jj]) + dist_right(p[jj], li);
			res = min(res, cur + dp[li][1]);
			jj = (jj - 1 + sz(p)) % sz(p);
		}
	}
}

void restore(int i, int w, vii& ans) {
	int res = dp[i][w];
	if  (w == 1 || sz(pos[ca[i]]) == 1) {
		if  (ca[i] == sz(c) - 1) {
			return;
		}
		forn(j, n) {
			if  (ca[j] == ca[i] + 1 && res == dist(i, j) + dp[j][0]) {
				dir[sz(ans)] = -1;
				ans.pb(mp(i, j));
				restore(j, 0, ans);
				return;
			}
		}
		assert(false);
	} else {
		const vi& p = pos[ca[i]];
		int my_pos = lower_bound(all(p), i) - p.begin();
		// right
		int jj = my_pos;
		forn(it, sz(p)) {
			int ri = p[(jj + 1) % sz(p)];
			int cur = dist_right(i, p[jj]) + dist_left(p[jj], ri);
			if  (res == cur + dp[ri][1]) {
				for (int j = my_pos; j != jj; j = (j + 1) % sz(p)) {
					int start = p[j];
					int end = p[(j + 1) % sz(p)];
					dir[sz(ans)] = RIGHT;
					ans.pb(mp(start, end));
				}
				if  ((jj + 1) % sz(p) == my_pos) {
					restore(p[jj], 1, ans);
					return;
				}
				dir[sz(ans)] = LEFT;
				ans.pb(mp(p[jj], p[(my_pos - 1 + sz(p)) % sz(p)]));
				for (int j = (my_pos - 1 + sz(p)) % sz(p); ; j = (j - 1 + sz(p)) % sz(p)) {
					int start = p[j];
					int end = p[(j - 1 + sz(p)) % sz(p)];
					if  (end == p[jj]) {
						break;
					}
					dir[sz(ans)] = LEFT;
					ans.pb(mp(start, end));
				}
				restore(ri, 1, ans);
				return;
			}
			jj = (jj + 1) % sz(p);
		}

		// left
		jj = my_pos;
		forn(it, sz(p)) {
			int li = p[(jj - 1 + sz(p)) % sz(p)];
			int cur = dist_left(i, p[jj]) + dist_right(p[jj], li);
			if  (res == cur + dp[li][1]) {
				for (int j = my_pos; j != jj; j = (j - 1 + sz(p)) % sz(p)) {
					int start = p[j];
					int end = p[(j - 1 + sz(p)) % sz(p)];
					dir[sz(ans)] = LEFT;
					ans.pb(mp(start, end));
				}
				if  ((my_pos + 1) % sz(p) == jj) {
					restore(p[jj], 1, ans);
					return;
				}
				dir[sz(ans)] = RIGHT;
				ans.pb(mp(p[jj], p[(my_pos + 1) % sz(p)]));
				for (int j = (my_pos + 1) % sz(p); ; j = (j + 1) % sz(p)) {
					int start = p[j];
					int end = p[(j + 1) % sz(p)];
					if  (end == p[jj]) {
						break;
					}
					dir[sz(ans)] = RIGHT;
					ans.pb(mp(start, end));
				}
				restore(li, 1, ans);
				return;
			}
			jj = (jj - 1 + sz(p)) % sz(p);
		}

		assert(false);
	}
}

int print_go(int i, int j, int d) {
	int x = -1;
	if  (d == LEFT) {
		x = (i - j + n) % n;
		printf("-%d\n", x);
		return -x;
	}
	if  (d == RIGHT) {
		x = (j - i + n) % n;
		printf("+%d\n", x);
	}
	if  (d == -1) {
		if  (dist_left(i, j) < dist_right(i, j)) {
			x = (i - j + n) % n;
			printf("-%d\n", x);	
			return -x;
		} else {
			x = (j - i + n) % n;
			printf("+%d\n", x);			
		}
	}
	return x;
}

void print_path(vii ans) {
	int p = s;
	forn(i, sz(ans)) {
		int x = print_go(ans[i].fst, ans[i].snd, dir[i]);
		// printf("%d -> %d, x = %d\n", ans[i].fst, ans[i].snd, x);
		// p = (p + x + n) % n;
		// printf("p = %d\n", p);
		// assert(p == ans[i].snd);
	}
}

void solve() {
	--s;
	c.clear();
	forn(i, n) {
		c.pb(a[i]);
	}
	sort(all(c));
	c.resize(unique(all(c)) - c.begin());

	forn(i, n) {
		ca[i] = lower_bound(all(c), a[i]) - c.begin();
		pos[ca[i]].pb(i);
	}

	ford(val, sz(c)) {
		ford(w, 2) {
			for (int p : pos[val]) {
				calc(p, w);
			}
		}
	}

	int min_i = -1;
	int min_dist = INF;
	forn(i, n) {
		int cur_dist = dp[i][0] + dist(s, i);
		if  (ca[i] == 0 && cur_dist < min_dist) {
			min_dist = cur_dist;
			min_i = i;
		}
	}

	printf("%d\n", min_dist);
	vii ans;
	dir[0] = -1;
	ans.pb(mp(s, min_i));
	restore(min_i, 0, ans);
	print_path(ans);
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
//	freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
	}	
	return 0;
}