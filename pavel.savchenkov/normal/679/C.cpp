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


const int MAXN = 500 + 10;

struct DSU {
	vi par;

	DSU(int n = 0) {
		par.assign(n, -1);
	}

	int get(int x) {
		return par[x] < 0 ? x : par[x] = get(par[x]);
	}

	bool union_set(int x, int y) {
		x = get(x);
		y = get(y);
		if  (x == y) {
			return false;
		}
		if  (-par[x] < -par[y]) {
			swap(x, y);
		}
		par[x] += par[y];
		par[y] = x;
		return true;
	}

	int size(int x) {
		return -par[get(x)];
	}
};

bool a[MAXN][MAXN];
int n, k;

bool read() {
	if  (scanf("%d%d\n", &n, &k) < 2) {
		return false;
	}
	static char s[MAXN];
	forn(i, n) {
		gets(s);
		forn(j, n) {
			a[i][j] = s[j] == '.';
		}
	}
	return true;
}

const int di[4] = { 1, -1, 0, 0 };
const int dj[4] = { 0, 0, 1, -1 };

bool on(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < n;
}

int code(int i, int j) {
	return i * n + j;
}

int cnt[MAXN * MAXN];
DSU dsu;
int cur_ans;
int was_now[MAXN * MAXN];
int timer;
int cnt_not;

bool was(int i, int j) {
	if  (!a[i][j]) {
		return true;
	}
	return cnt[dsu.get(code(i, j))] > 0;
}

void add(int i, int j) {
	if  (!a[i][j]) {
		++cnt_not;
		return;
	}
	int x = dsu.get(code(i, j));
	if  (!cnt[x]) {
		cur_ans += dsu.size(x);
	}
	++cnt[x];
}

void rem(int i, int j) {
	if  (!a[i][j]) {
		--cnt_not;
		return;
	}
	int x = dsu.get(code(i, j));
	if  (cnt[x] == 1) {
		cur_ans -= dsu.size(x);
	}
	--cnt[x];
}

void clear_now() {
	++timer;
}

bool now(int i, int j) {
	if  (!a[i][j]) {
		return true;
	}
	int x = dsu.get(code(i, j));
	return was_now[x] == timer;
}

void set_now(int i, int j) {
	if  (!a[i][j]) {
		return;
	}
	int x = dsu.get(code(i, j));
	was_now[x] = timer;
}

int solve() {
	dsu = DSU(n * n);
	int ans = 0;
	forn(i, n) forn(j, n) {
		if  (!a[i][j]) {
			continue;
		}
		forn(k, 4) {
			int ni = i + di[k];
			int nj = j + dj[k];
			if  (!on(ni, nj) || !a[ni][nj]) {
				continue;
			}
			dsu.union_set(code(i, j), code(ni, nj));
			ans = max(ans, dsu.size(code(i, j)));
		}
	}

	// forn(i, n) {
	// 	forn(j, n) {
	// 		printf("%d ", dsu.size(code(i, j)));
	// 	}
	// 	puts("");
	// }

	for (int i0 = 0; i0 + k - 1 < n; ++i0) {
		memset (cnt, 0, sizeof cnt);
		cur_ans = 0;
		cnt_not = 0;

		forn(i, k) forn(j, k) {
			add(i0 + i, j);
		}

		for (int j0 = 0; j0 + k - 1 < n; ++j0) {
			clear_now();

			int cur = cur_ans;
			forn(j, k) {
				int I = i0 - 1;
				int J = j0 + j;
				if  (!on(I, J)) {
					continue;
				}
				if  (now(I, J)) {
					continue;
				}
				if  (was(I, J)) {
					continue;
				}
				set_now(I, J);
				cur += dsu.size(code(I, J));
			}

			forn(j, k) {
				int I = i0 + k;
				int J = j0 + j;
				if  (!on(I, J)) {
					continue;
				}
				if  (now(I, J)) {
					continue;
				}
				if  (was(I, J)) {
					continue;
				}
				set_now(I, J);
				cur += dsu.size(code(I, J));	
			}

			forn(i, k) {
				int I = i0 + i;
				int J = j0 - 1;
				if  (!on(I, J)) {
					continue;
				}
				if  (now(I, J)) {
					continue;
				}
				if  (was(I, J)) {
					continue;
				}
				set_now(I, J);
				cur += dsu.size(code(I, J));
			}

			forn(i, k) {
				int I = i0 + i;
				int J = j0 + k;
				if  (!on(I, J)) {
					continue;
				}
				if  (now(I, J)) {
					continue;
				}
				if  (was(I, J)) {
					continue;
				}
				set_now(I, J);
				cur += dsu.size(code(I, J));
			}

			ans = max(ans, cur + cnt_not);
			// printf("ans = %d, i0=%d, j0=%d\n", ans, i0, j0);

			if  (j0 + k == n) {
				break;
			}

			forn(i, k) {
				rem(i0 + i, j0);
				add(i0 + i, j0 + k);
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
		printf("%d\n", solve());
	}

#ifdef LOCAL
	printf("Time: %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}