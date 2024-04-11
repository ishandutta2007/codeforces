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
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
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

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define FILE_NAME "a"

const int MAXN = 100 + 10;

int n, m;
int grid[MAXN][MAXN];

bool read() {
	if  (scanf("%d%d\n", &n, &m) < 2) {
		return 0;
	}
	static char buf[MAXN];
	forn(i, n) {
		scanf("%s\n", buf);
		forn(j, m + 2) {
			grid[i][j] = buf[j] == '1';
		}
	}
	return 1;
}

const int INF = 1e9;

int left[MAXN];
int right[MAXN];

int dp[MAXN][2][2];

struct State {
	int i;
	int is_left;
	int is_empty;
};

int& get_dp(State st) {
	return dp[st.i][st.is_left][st.is_empty];
}

void update(queue<State>& q, State st, int new_dp) {
	if  (get_dp(st) > new_dp) {
		get_dp(st) = new_dp;
		q.push(st);
	}
}

int solve() {
	forn(i, n) {
		left[i] = INF;
		right[i] = -INF;

		forn(j, m + 2) {
			if  (grid[i][j]) {
				left[i] = min(left[i], j);
				right[i] = max(right[i], j);
			}
		}

		// eprintf("i=%d, left=%d, right=%d\n", i, left[i], right[i]);
	}

	forn(i, n) {
		forn(lr, 2) forn(emp, 2) {
			dp[i][lr][emp] = INF;
		}
	}

	int last = -1;
	forn(i, n) {
		if  (left[i] < INF) {
			last = i;
			break;
		}
	}
	if  (last == -1) {
		return 0;
	}

	int ans = INF;
	
	State st0{n - 1, 1, 0};
	get_dp(st0) = 0;
	queue<State> q;
	q.push(st0);
	while (!q.empty()) {
		State st = q.front();
		q.pop();

		int cur_dp = get_dp(st);

		// eprintf("i=%d, is_left=%d, is_empty=%d --> %d\n", st.i, st.is_left, st.is_empty, cur_dp);

		if  (st.is_empty) {
			if  (st.i == last) {
				ans = min(ans, cur_dp);
				continue;
			}
			update(q, State{st.i - 1, st.is_left, 0}, cur_dp + 1);
			update(q, State{st.i, st.is_left ^ 1, 1}, cur_dp + (m + 1));
		} else {
			if  (st.i == last) {
				assert(left[st.i] < INF);
				if  (st.is_left) {
					ans = min(ans, cur_dp + right[st.i]);
				} else {
					ans = min(ans, cur_dp + (m + 1) - left[st.i]);
				}
				continue;
			}

			update(q, State{st.i, st.is_left ^ 1, 1}, cur_dp + (m + 1));
			if  (st.is_left) {
				// eprintf("cur_dp = %d\n", cur_dp);
				update(q, State{st.i, st.is_left, 1}, left[st.i] == INF ? cur_dp : cur_dp + right[st.i] * 2);
			} else {
				update(q, State{st.i, st.is_left, 1}, left[st.i] == INF ? cur_dp : cur_dp + (m + 1 - left[st.i]) * 2);
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
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}