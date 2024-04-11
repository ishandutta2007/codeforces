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

#define FILE_NAME "a"

const int MAXN = 1e4 + 10;

int n;
vi s[2];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	forn(i, 2) {
		int cnt;
		scanf("%d", &cnt);
		s[i].resize(cnt);
		forn(j, cnt) {
			scanf("%d", &s[i][j]);
		}
		sort(all(s[i]));
		s[i].resize(unique(all(s[i])) - s[i].begin());
	}
	return 1;
}

int dp[MAXN * 2];
int deg_out[MAXN * 2];

int code(int who, int pos) {
	return n * who + pos;
}

void solve() {
	memset (dp, -1, sizeof dp);
	memset (deg_out, 0, sizeof deg_out);

	queue<int> q;
	forn(who, 2) forn(pos, n) {
		int v = code(who, pos);
		if  (pos == 0) {
			dp[v] = 0;
			q.push(v);
		}
		deg_out[v] = sz(s[who]);
	}

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		assert(dp[v] != -1);

		vi fr;
		int who = v / n;
		int pos = v % n;
		assert(code(who, pos) == v);
		for (int x : s[who ^ 1]) {
			int npos = (pos - x + n) % n;
			fr.pb(code(who ^ 1, npos));
		}

		for (int from : fr) {
			if  (dp[from] != -1) {
				continue;
			}
			if  (dp[v] == 0) {
				dp[from] = 1;
				q.push(from);
				continue;
			}
			if  (dp[v] == 1) {
				--deg_out[from];
				if  (deg_out[from] == 0) {
					dp[from] = 0;
					q.push(from);
				}
				continue;
			}
		}
	}

	forn(who, 2) {
		for (int pos = 1; pos < n; ++pos) {
			int v = code(who, pos);
			if  (dp[v] == 0) {
				printf("Lose ");
			} else if  (dp[v] == 1) {
				printf("Win ");
			} else {
				printf("Loop ");
			}
		}
		puts("");
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}