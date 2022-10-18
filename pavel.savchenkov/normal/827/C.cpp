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
#define end end___________

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

#define TEST 0

const int MAXN = 1e5 + 10;

int code(char c) {
	if  (c == 'A') {
		return 0;
	}
	if  (c == 'C') {
		return 1;
	}
	if  (c == 'G') {
		return 2;
	}
	if  (c == 'T') {
		return 3;
	}
	assert(0);
	return -1;
}

int n;
int s[MAXN];

bool read() {
#if TEST
	n = 1 + rand() % int(1e5);
	forn(i, n) {
		s[i] = rand() % 4;
	}
#else
	static char S[MAXN];
	scanf("%s\n", S);
	n = strlen(S);
	forn(i, n) {
		s[i] = code(S[i]);
	}
#endif
	return 1;
}

const int K = 250;
const int BLOCKS = MAXN / K + 2;
const int L = 10;

int start_pos[BLOCKS];
int end_pos[BLOCKS];
int cnt[BLOCKS][L][L][4];
int id_block[MAXN];
int B;

void update(int pos, int c, bool assign = false) {
	const int id = id_block[pos];
	for (int len = 1; len <= L; ++len) {
		if  (!assign) {
			--cnt[id][len - 1][pos % len][s[pos]];
		}
		++cnt[id][len - 1][pos % len][c];
	}
	s[pos] = c;
}

void precalc() {
	B = 0;
	for (int l = 0; l < n; l += K) {
		const int r = min(n - 1, l + K - 1);
		start_pos[B] = l;
		end_pos[B] = min(n - 1, r);
		memset (cnt[B], 0, sizeof cnt[B]);
		for (int i = l; i <= r; ++i) {
			id_block[i] = B;
			update(i, s[i], true);
		}
		++B;
	}
}

int ask_block(int start, int id, const vi& e) {
	int ans = 0;
	const int sz = sz(e);
	for (int i = start_pos[id]; i <= end_pos[id] && i - start_pos[id] < sz; ++i) {
		const int real_pos = (i - start) % sz;
		const int c = e[real_pos];
		ans += cnt[id][sz - 1][i % sz][c];
	}
	return ans;
}

int ask_brut(int start, int l, int r, const vi& e) {
	// const int id = id_block[l];
	// if  (start_pos[id] == l && end_pos[id] == r) {
	// 	return ask_block(start, id, e);
	// }
	int ans = 0;
	for (int i = l; i <= r; ++i) {
		if  (e[(i - start) % sz(e)] == s[i]) {
			++ans;
		}
	}
	return ans;
}

int ask(int start, int l, int r, const vi& e) {
	assert(l <= r);
	if  (r - l < K + 2) {
		return ask_brut(start, l, r, e);
	}
	const int id_l = id_block[l];
	if  (start_pos[id_l] < l) {
		int nxt = end_pos[id_l] + 1;
		assert(nxt <= r);
		return ask_brut(start, l, nxt - 1, e) + ask(start, nxt, r, e);
	}	
	int ans = 0;
	while (id_block[l] != id_block[r]) {
		ans += ask_block(start, id_block[l], e);
		l = end_pos[id_block[l]] + 1;
	}
	ans += ask_brut(start, l, r, e);
	return ans;
}

void solve() {
	precalc();

	int q;
#if !TEST
	scanf("%d\n", &q);
#else
	q = 1 + rand() % int(1e5);
	// q = 1;
#endif
	forn(it, q) {
		int type;
#if !TEST	
		scanf("%d ", &type);
#else
		type = 1 + rand() % 2;
		// type = 2;
#endif 		
		// eprintf("type = %d\n", type);
		if  (type == 1) {
			int x;
			int c;
#if !TEST
			char ch;
			scanf("%d %c\n", &x, &ch);
			c = code(ch);
			--x;
#else
			x = rand() % n;
			c = rand() % 4;
#endif
			update(x, c);
		} else if  (type == 2) {
			int l, r;
			vi E;
#if !TEST
			static char e[20];
			scanf("%d %d %s\n", &l, &r, e);
			--l;
			--r;
			for (int i = 0; e[i]; ++i) {
				E.pb(code(e[i]));
			}
#else
			l = rand() % n;
			r = rand() % n;
			if  (l > r) {
				swap(l, r);
			}
			int len = 1 + rand() % 10;
			forn(it, len) {
				E.pb(rand() % 4);
			}
#endif		

			int my_ans = ask(l, l, r, E);

#if TEST
			// int corr = ask_brut(l, l, r, E);
			// if  (my_ans != corr) {
			// 	printf("FAIL\n");
			// 	printf("my=%d, br=%d\n", my_ans, corr);
			// 	printf("s:\n");
			// 	forn(i, n) {
			// 		printf("%d:%d\n", i, s[i]);
			// 	}
			// 	puts("");
			// 	printf("l=%d, r=%d\n", l, r);
			// 	printf("E:\n");
			// 	forn(i, sz(E)) {
			// 		printf("%d:%d\n", i, E[i]);
			// 	}
			// 	exit(0);
			// } else {
			// 	printf("OK %d == %d\n", my_ans, corr);
			// }
#else
			printf("%d\n", my_ans);
#endif
		} else {
			assert(0);
		}
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

// #if TEST
// 	while (read()) {
// 		solve();
// 	}
// #endif

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