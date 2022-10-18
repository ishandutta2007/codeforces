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

const int MAXN = 1e5 + 10;

int n;

int ask(int x1, int y1, int x2, int y2) {
	static int cnt = 0;
	++cnt;
	assert(cnt <= 200);
	assert(1 <= x1 && x1 <= x2 && x2 <= n);
	assert(1 <= y1 && y1 <= y2 && y2 <= n);
	cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	int res;
	cin >> res;
	return res;
}

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
	}
	return true;
}

void print(const pair<pii, pii>& s) {
	cout << s.fst.fst << " " << s.fst.snd << " " << s.snd.fst << " " << s.snd.snd << " ";
}

void print(const pair<pii, pii>& s1, const pair<pii, pii>& s2) {
	cout << "! ";
	print(s1);
	print(s2);
	cout << endl;
	exit(0);
}

pair<pii, pii> solve1(int X1, int Y1, int X2, int Y2, int iter = 0) {
	if  (iter == 0) {
		int L = Y1 - 1;
		int R = Y2 + 1;
		while (L != R - 1) {
			int M = (L + R) / 2;
			int cur = ask(X1, Y1, X2, M);
			assert(cur < 2);
			if  (cur < 1) {
				L = M;
			} else {
				R = M;
			}
		}
		return solve1(X1, Y1, X2, R, iter + 1);
	} else if  (iter == 1) {
		int L = Y1 - 1;
		int R = Y2 + 1;
		while (L != R - 1) {
			int M = (L + R) / 2;
			int cur = ask(X1, M, X2, Y2);
			assert(cur < 2);
			if  (cur == 1) {
				L = M;
			} else {
				R = M;
			}
		}
		return solve1(X1, L, X2, Y2, iter + 1);
	} else if  (iter == 2) {
		int L = X1 - 1;
		int R = X2 + 1;
		while (L != R - 1) {
			int M = (L + R) / 2;
			int cur = ask(M, Y1, X2, Y2);
			assert(cur < 2);
			if  (cur == 1) {
				L = M;
			} else {
				R = M;
			}
		}
		return solve1(L, Y1, X2, Y2, iter + 1);
	} else if  (iter == 3) {
		int L = X1 - 1;
		int R = X2 + 1;
		while (L != R - 1) {
			int M = (L + R) / 2;
			int cur = ask(X1, Y1, M, Y2);
			if  (cur == 0) {
				L = M;
			} else {
				R = M;
			}
		}
		return solve1(X1, Y1, R, Y2, iter + 1);
	} else {
		assert(iter == 4);
		return mp(mp(X1, Y1), mp(X2, Y2));
	}
}

void solve() {
	{
		int L = 0;
		int R = n + 1;
		while (L != R - 1) {
			int M = (L + R) / 2;
			int cur = ask(1, 1, n, M);
			if  (cur < 1) {
				L = M;
			} else {
				R = M;
			}
		}
		if  (R + 1 <= n) {
			if  (ask(1, 1, n, R) == 1 && ask(1, R + 1, n, n) == 1) {
				pair<pii, pii> s1 = solve1(1, 1, n, R);
				pair<pii, pii> s2 = solve1(1, R + 1, n, n);
				print(s1, s2);
			}
		}
	}

	{
		int L = 0;
		int R = n + 1;
		while (L != R - 1) {
			int M = (L + R) / 2;
			int cur = ask(1, 1, M, n);
			if  (cur < 1) {
				L = M;
			} else {
				R = M;
			}
		}
		int res = ask(1, 1, R, n);
		assert(res == 1);
		pair<pii, pii> s1 = solve1(1, 1, R, n);
		pair<pii, pii> s2 = solve1(R + 1, 1, n, n);
		print(s1, s2);
	}
}

int main() {
#ifdef LOCAL
	// freopen(FILE_NAME ".in", "r", stdin);
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