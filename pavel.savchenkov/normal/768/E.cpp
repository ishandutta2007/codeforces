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

const int MAXN = 60 + 10;

int n;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	return 1;
}

map<pair<int, set<int>>, int> mem;

int last[MAXN];
int timer;

int get(int s, set<int> x) {
	if  (!s) {
		return 0;
	}

	pair<int, set<int>> C{s, x};
	if  (mem.count(C)) {
		return mem[C];
	}

	set<int> was;
	for (int y = 1; y <= s; ++y) {
		if  (!x.count(y)) {
			auto nx = x;
			nx.insert(y);
			was.insert(get(s - y, nx));
		}
	}

	for (int i = 0; ; ++i) {
		if  (!was.count(i)) {
			return (mem[C] = i);
		}
	}

	assert(0);
}

int gr[MAXN];

void solve() {
	int ans = 0;
	forn(i, n) {
		int s;
		scanf("%d", &s);
		ans ^= gr[s];
	}
	puts(ans ? "NO" : "YES");
	return;

	for (int s = 0; s <= 60; ++s) {
		printf("gr[%d] = %d;\n", s, get(s, {}));
		cerr << s << endl;
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

gr[0] = 0;
gr[1] = 1;
gr[2] = 1;
gr[3] = 2;
gr[4] = 2;
gr[5] = 2;
gr[6] = 3;
gr[7] = 3;
gr[8] = 3;
gr[9] = 3;
gr[10] = 4;
gr[11] = 4;
gr[12] = 4;
gr[13] = 4;
gr[14] = 4;
gr[15] = 5;
gr[16] = 5;
gr[17] = 5;
gr[18] = 5;
gr[19] = 5;
gr[20] = 5;
gr[21] = 6;
gr[22] = 6;
gr[23] = 6;
gr[24] = 6;
gr[25] = 6;
gr[26] = 6;
gr[27] = 6;
gr[28] = 7;
gr[29] = 7;
gr[30] = 7;
gr[31] = 7;
gr[32] = 7;
gr[33] = 7;
gr[34] = 7;
gr[35] = 7;
gr[36] = 8;
gr[37] = 8;
gr[38] = 8;
gr[39] = 8;
gr[40] = 8;
gr[41] = 8;
gr[42] = 8;
gr[43] = 8;
gr[44] = 8;
gr[45] = 9;
gr[46] = 9;
gr[47] = 9;
gr[48] = 9;
gr[49] = 9;
gr[50] = 9;
gr[51] = 9;
gr[52] = 9;
gr[53] = 9;
gr[54] = 9;
gr[55] = 10;
gr[56] = 10;
gr[57] = 10;
gr[58] = 10;
gr[59] = 10;
gr[60] = 10;
gr[0] = 0;
gr[1] = 1;
gr[2] = 1;
gr[3] = 2;
gr[4] = 2;
gr[5] = 2;
gr[6] = 3;
gr[7] = 3;
gr[8] = 3;
gr[9] = 3;
gr[10] = 4;
gr[11] = 4;
gr[12] = 4;
gr[13] = 4;
gr[14] = 4;
gr[15] = 5;
gr[16] = 5;
gr[17] = 5;
gr[18] = 5;
gr[19] = 5;
gr[20] = 5;
gr[21] = 6;
gr[22] = 6;
gr[23] = 6;
gr[24] = 6;
gr[25] = 6;
gr[26] = 6;
gr[27] = 6;
gr[28] = 7;
gr[29] = 7;
gr[30] = 7;
gr[31] = 7;
gr[32] = 7;
gr[33] = 7;
gr[34] = 7;
gr[35] = 7;
gr[36] = 8;
gr[37] = 8;
gr[38] = 8;
gr[39] = 8;
gr[40] = 8;
gr[41] = 8;
gr[42] = 8;
gr[43] = 8;
gr[44] = 8;
gr[45] = 9;
gr[46] = 9;
gr[47] = 9;
gr[48] = 9;
gr[49] = 9;
gr[50] = 9;
gr[51] = 9;
gr[52] = 9;
gr[53] = 9;
gr[54] = 9;
gr[55] = 10;
gr[56] = 10;
gr[57] = 10;
gr[58] = 10;
gr[59] = 10;
gr[60] = 10;
gr[0] = 0;
gr[1] = 1;
gr[2] = 1;
gr[3] = 2;
gr[4] = 2;
gr[5] = 2;
gr[6] = 3;
gr[7] = 3;
gr[8] = 3;
gr[9] = 3;
gr[10] = 4;
gr[11] = 4;
gr[12] = 4;
gr[13] = 4;
gr[14] = 4;
gr[15] = 5;
gr[16] = 5;
gr[17] = 5;
gr[18] = 5;
gr[19] = 5;
gr[20] = 5;
gr[21] = 6;
gr[22] = 6;
gr[23] = 6;
gr[24] = 6;
gr[25] = 6;
gr[26] = 6;
gr[27] = 6;
gr[28] = 7;
gr[29] = 7;
gr[30] = 7;
gr[31] = 7;
gr[32] = 7;
gr[33] = 7;
gr[34] = 7;
gr[35] = 7;
gr[36] = 8;
gr[37] = 8;
gr[38] = 8;
gr[39] = 8;
gr[40] = 8;
gr[41] = 8;
gr[42] = 8;
gr[43] = 8;
gr[44] = 8;
gr[45] = 9;
gr[46] = 9;
gr[47] = 9;
gr[48] = 9;
gr[49] = 9;
gr[50] = 9;
gr[51] = 9;
gr[52] = 9;
gr[53] = 9;
gr[54] = 9;
gr[55] = 10;
gr[56] = 10;
gr[57] = 10;
gr[58] = 10;
gr[59] = 10;
gr[60] = 10;

	while (read()) {
		solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}