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

const int MAXN = 1e6 + 10;
const int A = 26;

int n, m;
char s[MAXN];
char t[MAXN];

bool read() {
	scanf("%s\n", s);
	n = int(strlen(s));
	scanf("%s\n", t);
	m = int(strlen(t));
	return 1;
}

vi calc() {
	vi ans;
	vi cnt(A, 0);
	forn(i, n) {
		++cnt[s[i] - 'a'];
	}
	forn(i, n) {
		const int pos = i % m;
		const int c = t[pos] - 'a';
		if  (cnt[c]) {
			--cnt[c];
			continue;
		}
		ans.pb(c);
	}
	return ans;
}

void solve() {
	vi ans = calc();
	int ptr = 0;
	forn(i, n) {
		if  (s[i] == '?') {
			assert(ptr < sz(ans));
			s[i] = 'a' + ans[ptr];
			++ptr;
		}
	}
	puts(s);
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

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}