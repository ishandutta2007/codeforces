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


const int MAXN = 2e5 + 10;
const int MAXL = 18;
const int INF = 2e9;

int a[MAXN];
int b[MAXN];
int n;

int mn[MAXN][MAXL];
int mx[MAXN][MAXL];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
	}
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	forn(i, n) {
		scanf("%d", &b[i]);
	}
	return true;
}

int max_pow[MAXN];

void precalc() {
	forn(i, n) {
		mx[i][0] = a[i];
	}
	for (int p = 1; p < MAXL; ++p) {
		int len = 1 << p;
		forn(i, n) {
			if  (i + len - 1 >= n) {
				break;
			}
			mx[i][p] = max(mx[i][p - 1], mx[i + len / 2][p - 1]);
		}
	}

	forn(i, n) {
		mn[i][0] = b[i];
	}
	for (int p = 1; p < MAXL; ++p) {
		int len = 1 << p;
		forn(i, n) {
			if  (i + len - 1 >= n) {
				break;
			}
			mn[i][p] = min(mn[i][p - 1], mn[i + len / 2][p - 1]);
		}
	}

	forn(p, MAXL) {
		for (int i = (1 << p); i < MAXN; ++i) {
			max_pow[i] = p;
		}
	}
}

int get_min(int l, int r) {
	int p = max_pow[r - l + 1];
	return min(mn[l][p], mn[r - (1 << p) + 1][p]);
}

int get_max(int l, int r) {
	int p = max_pow[r - l + 1];
	return max(mx[l][p], mx[r - (1 << p) + 1][p]);
}

ll solve() {
	ll ans = 0;
	forn(l, n) {
		int L = l - 1;
		int R = n;
		while (L != R - 1) {
			int M = (L + R) / 2;
			int func = get_max(l, M) - get_min(l, M);
			if  (func < 0) {
				L = M;
			} else {
				R = M;
			}
		}

		int left = R;
		if  (left == n || get_max(l, left) != get_min(l, left)) {
			continue;
		}

		L = l - 1;
		R = n;
		while (L != R - 1) {
			int M = (L + R) / 2;
			int func = get_max(l, M) - get_min(l, M);
			if  (func <= 0) {
				L = M;
			} else {
				R = M;
			}
		}

		int right = L;

		// printf("l = %d, left=%d, right=%d\n", l, left, right);
		ans += right - left + 1;
	}

	return ans;

}

// int first_not_gr(const vi& B, int p) {
// 	int L = -1;
// 	int R = sz(B);
// 	while (L != R - 1) {
// 		int M = (L + R) / 2;
// 		if  (B[M] > p) {
// 			L = M;
// 		} else {
// 			R = M;
// 		}
// 	}
// 	return R;
// }

// ll solve() {
// 	ll ans = 0;

// 	vi A;
// 	vi B;
// 	ford(i, n) {
// 		while (!A.empty() && a[A.back()] <= a[i]) {
// 			A.pop_back();
// 		}
// 		A.pb(i);

// 		while (!B.empty() && b[B.back()] >= b[i]) {
// 			B.pop_back();
// 		}
// 		B.pb(i);

// 		int L = -1;
// 		int R = sz(A);
// 		while (L != R - 1) {
// 			int M = (L + R) / 2;
// 			int pos_b = first_not_gr(B, A[M]);
// 			int func = a[A[M]] - b[B[pos_b]];
// 			if  (func < 0) {
// 				L = M;
// 			} else {
// 				R = M;
// 			}
// 		}

// 		// printf("A:");
// 		// forn(j, sz(A)) {
// 		// 	printf("%d ", A[j]);
// 		// }
// 		// puts("");

// 		// printf("B:");
// 		// forn(j, sz(B)) {
// 		// 	printf("%d ", B[j]);
// 		// }
// 		// puts("");

// 		for (int j = max(0, L - 2); j < sz(A) && j < R + 3; ++j) {
// 			int L = -1;
// 			int R = sz(B);
// 			while (L != R - 1) {
// 				int M = (L + R) / 2;
// 				if  (b[B[M]] < a[A[j]]) {
// 					L = M;
// 				} else {
// 					R = M;
// 				}
// 			}

// 			L = R;
// 			if  (L < sz(B) && a[A[j]] == b[B[L]]) {
// 				// printf("j = %d, L = %d\n", j, L);
				
// 				int l = A[j];
// 				int r = (j == 0) ? n - 1 : A[j - 1] - 1;

// 				// printf("l = %d, r = %d\n", l, r);

// 				int jj = L;
// 				l = max(l, B[jj]);
// 				r = min(r, (jj == 0) ? n - 1 : B[jj - 1] - 1);

// 				if  (l <= r) {
// 					ans += r - l + 1;
// 				}
// 			}
// 		}

// 		// puts("");
// 	}

// 	return ans;
// }

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		precalc();

		cout << solve() << endl;
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}