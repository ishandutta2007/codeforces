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


const int MAXN = 3e3 + 10;
const int INF = 1e9;

int dist[MAXN][MAXN];
vi g[MAXN];
int n, m;

bool read() {
	// n = 3000;
	// m = 5000;
	// forn(i, m) {
	// 	int a = (rand() * rand()) % n;
	// 	int b = (rand() * rand()) % n;
	// 	g[a].pb(b);
	// }
	// return true;

	if  (scanf("%d%d", &n, &m) < 2) {
		return false;
	}
	forn(i, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		g[a].pb(b);
	}
	return true;
}

int Q[MAXN * 200];
int ql, qr;

void precalc() {
	forn(s, n) {
		forn(v, n) {
			dist[s][v] = INF;
		}
		dist[s][s] = 0;
		ql = qr = 0;
		Q[qr++] = s;
		while (ql != qr) {
			int v = Q[ql++];
			for (int to : g[v]) {
				if  (dist[s][to] > dist[s][v] + 1) {
					dist[s][to] = dist[s][v] + 1;
					Q[qr++] = to;
				}
			}
		}
	}
}

int mx[3][MAXN];
int Mx[3][3][MAXN];

void solve() {
	precalc();

	forn(s, n) {
		forn(i, 3) mx[i][s] = -1;
		forn(v, n) {
			int d = dist[s][v];
			if  (d >= INF) {
				continue;
			}
			forn(i, 3) {
				if  (mx[i][s] == -1 || d > dist[s][mx[i][s]]) {
					for (int j = i + 1; j < 3; ++j) {
						mx[j][s] = mx[j - 1][s];
					}
					mx[i][s] = v;
					break;
				}
			}
		}
	} 

	memset (Mx, -1, sizeof Mx);
	forn(b, n) {
		forn(j, 3) {
			forn(c, n) {
				if  (c == b) {
					continue;
				}
				if  (mx[j][c] == -1) {
					continue;
				}
				int cur_d = dist[b][c] + dist[c][mx[j][c]];
				if  (cur_d >= INF) {
					continue;
				}
				forn(i, 3) {
					int cc = Mx[j][i][b];
					if  (cc == -1 || cur_d > dist[b][cc] + dist[cc][mx[j][cc]]) {
						for (int k = i + 1; k < 3; ++k) {
							Mx[j][k][b] = Mx[j][k - 1][b];
						}
						Mx[j][i][b] = c;
						break;
					}
				}
			}
		}
	}

	int A = -1, B = -1, C = -1, D = -1;
	int ans = -INF;
	forn(a, n) {
		forn(b, n) {
			if  (a == b) {
				continue;
			}
			if  (dist[a][b] >= INF) {
				continue;
			}
			forn(j, 3) {
				forn(i, 3) {
					int c = Mx[j][i][b];
					if  (c == -1) {
						continue;
					}
					int d = mx[j][c];
					if  (c == a || c == b || d == a || d == b || d == c) {
						continue;
					}
					int cur = dist[a][b] + dist[b][c] + dist[c][d];
					if  (cur > ans) {
						ans = cur;
						A = a;
						B = b;
						C = c;
						D = d;
					}
				}
			}
		}
	}

	cerr << ans << endl;
	printf("%d %d %d %d\n", A + 1, B + 1, C + 1, D + 1);
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
		break;
	}

	return 0;
}