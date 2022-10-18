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

const int MAXN = 3e5 + 10;

int n, m;
int a[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return 0;
	}
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	return 1;
}

bool bit(int mask, int i) {
	return (mask >> i) & 1;
}

struct Node;
using NodePtr = Node*;

struct Node {
	NodePtr next[2];
	int sz;

	Node() {
		memset (next, 0, sizeof next);
		sz = 0;
	}

	void* operator new(size_t);
};

const int B = 21;
const int SIZE = B * MAXN;

Node pool[SIZE];
int ptr_pool;

void* Node::operator new(size_t) {
	pool[ptr_pool] = Node();
	return pool + ptr_pool++;
} 

void append(NodePtr& t, int x) {
	NodePtr v = t;
	ford(i, B) {
		assert(v);
		++v->sz;
		const int c = bit(x, i);
		if  (!v->next[c]) {
			v->next[c] = new Node();
		}
		v = v->next[c];
		assert(v);
	}
	++v->sz;
}

int to_xor;

int get_mex(NodePtr t) {	
	assert(t);
	NodePtr v = t;
	int ans = 0;
	// eprintf("to_xor = %d\n", to_xor);
	ford(i, B) {
		assert(v);
		assert(v->next[0] || v->next[1]);

		int want = bit(to_xor, i);
		assert(want == 0 || want == 1);

		// eprintf("i = %d, want = %d, sz(want) = %d\n", i, want, v->next[want] ? v->next[want]->sz : 0);

		if  (v->next[want] && v->next[want]->sz == (1 << i) && !v->next[want ^ 1]) {
			ans ^= 1 << i;
			break;
		}

		if  (!v->next[want]) {
			break;
		}

		int go = -1;
		if  (v->next[want] && v->next[want]->sz < (1 << i)) {
			go = want;
		} else {
			go = want ^ 1;
		}
		// eprintf("i = %d, go = %d\n", i, go);
		if  (go != want) {
			ans ^= 1 << i;
		}
		v = v->next[go];
		assert(v);
	}
	return ans;
}

void solve() {
	to_xor = 0;
	ptr_pool = 0;

	NodePtr t = new Node();
	set<int> was;
	forn(i, n) {
		if  (!was.count(a[i])) {
			append(t, a[i]);
			was.insert(a[i]);
		}
	}

	forn(i, m) {
		int x;
		scanf("%d", &x);
		to_xor ^= x;
		// eprintf("x = %d\n", x);
		int ans = get_mex(t);
		printf("%d\n", ans);
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