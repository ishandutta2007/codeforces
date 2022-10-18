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

int n, a, b;
int cnt[2];

bool check(int p) {
	vi c(2, 0);
	forn(i, a) forn(j, b) ++c[(i + j) & 1];
	return c[p] >= cnt[0] && c[p ^ 1] >= cnt[1];
}

void print(int p) {
	int p0 = 1;
	int p1 = 2;
	forn(i, a) {
		forn(j, b) {
			int cur = 0;

			int pp = (i + j) & 1;
			if  (pp == p) {
				if  (p0 <= n) {
					cur = p0;
					p0 += 2;
				}
			} else {
				if  (p1 <= n) {
					cur = p1;
					p1 += 2;
				}
			}

			printf("%d ", cur);
		}
		puts("");
	}
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	cin >> n >> a >> b;
	forn(i, n) {
		++cnt[i & 1];
	}

	forn(i, 2) {
		if  (check(i)) {
			print(i);
			return 0;
		}
	}

	puts("-1");

	return 0;
}