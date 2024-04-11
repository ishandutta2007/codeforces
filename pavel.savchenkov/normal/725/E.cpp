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

const int MAXN = 2e5 + 10;
const int INF = 1e9;

int n, c;
int x[MAXN];

bool read() {
	if  (scanf("%d", &c) < 1) {
		return 0;
	}
	scanf("%d", &n);
	forn(i, n) {
		scanf("%d", &x[i]);
	}
	return 1;
}

int last[MAXN];
int prev[MAXN];

bool can(int sum, int pos) {
	if  (sum == 0) {
		return 1;
	}
	if  (pos == -1) {
		return 0;
	}
	// ford(i, pos + 1) {
	// 	if  (x[i] <= sum) {
	// 		sum -= x[i];
	// 	}
	// }
	// return sum == 0;
	if  (sum < x[pos]) {
		return can(sum, last[sum]);
	}

	int cnt = pos - prev[pos];
	int can_cnt = sum / x[pos];
	cnt = min(cnt, can_cnt);
	return can(sum - cnt * x[pos], pos - cnt);
}

int solve() {
	sort(x, x + n);

	memset (last, -1, sizeof last);
	forn(i, n) {
		last[x[i]] = i;
	}
	for (int i = 1; i <= c; ++i) {
		if  (last[i] == -1) {
			last[i] = last[i - 1];
		}
	}

	prev[0] = -1;
	for (int i = 1; i < n; ++i) {
		if  (x[i] == x[i - 1]) {
			prev[i] = prev[i - 1];
		} else {
			prev[i] = i - 1;
		}
	}

	if  (x[n - 1] == c) {
		return -1;
	}

	int ans = INF;

	{
		for (int cur = x[n - 1]; cur < c; ++cur) {
			if  (!can(c - cur, n - 1)) {
				if  (cur < ans) {
					ans = cur;
				}
				break;
			}
		}
	}

	int cc = c;
	ford(i, n) {
		if  (cc - x[i] < 0) {
			continue;
		}
		cc -= x[i];
		// printf("take %d\n", x[i]);
		if  (!i) {
			assert(cc == 0);
			break;
		}
		if  (cc == 0) {
			break;
		}
		int nxt = min(i - 1, last[cc]);
		for (int cur = x[nxt]; cur < cc && cur <= x[i]; ++cur) {
			// printf("cur = %d, cc = %d\n", cur, cc);
			if  (!can(cc - cur, i - 1)) {
				if  (cur < ans) {
					ans = cur;
				}
				break;
			}
		}
	}

	assert(cc == 0);

	return ans >= INF ? -1 : ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		int ans = solve();
		if  (ans == -1) {
			printf("Greed is good\n");
		} else {
			printf("%d\n", ans);
		}
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}