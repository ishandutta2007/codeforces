#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<unordered_map>
#include<random>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)
struct UnionFind {
    int n, cc, *u;
    UnionFind() : n(0), cc(0), u(NULL) {}
    UnionFind(int n_) : n(n_), cc(n_) {
	u = new int[n_];
	memset(u, -1, sizeof (int) * n);
    }
    UnionFind(const UnionFind &y) : n(y.n), cc(y.cc) {
	u = new int[y.n];
	memcpy(u, y.u, sizeof (int) * n);
    }
    ~UnionFind() {
	delete[] u; u = NULL;
	n = cc = 0;
    }
    friend void swap(UnionFind &x, UnionFind &y) {
	swap(x.n, y.n); swap(x.cc, y.cc); swap(x.u, y.u);
    }
    UnionFind& operator=(UnionFind y) { 
	swap(*this, y);
	return *this;
    }
    int root(int x) {
	int y = x, t;
	while (u[y] >= 0) y = u[y];
	while (x != y) { t = u[x]; u[x] = y; x = t; }
	return y;
    }
    bool link(int x, int y) {
	x = root(x); y = root(y);
	if (x == y) return false;
	if (u[y] < u[x]) swap(x, y);
	u[x] += u[y]; u[y] = x; cc--;
	return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int count_node(int x) { return -u[root(x)]; }
    int count_tree() { return cc; }
};

mt19937_64 engine(110);
using ULL = unsigned long long;
ULL Z[200011];

int N;
int X[200011];
int Y[200011];
VI G[200011];
bool ban[200011];

VI que;
int par[200011];
int par_id[200011];
int sz[200011];

bool is_fib[200011];
int bound[200011];

unordered_map<ULL, bool> mp;

LL cnt = 0;
LL sum = 0;
const int LIMIT = 100000;

bool rec(int s, int n) {
    cnt++;
    sum += n;
    if (n <= 3) return true;

    par[s] = -1;
    par_id[s] = -1;
    que.clear();
    que.push_back(s);

    int ma = 0;
    for (int i=0; i<(int)que.size(); i++) {
	int v = que[i];
	amax(ma, (int)G[v].size());
	if ((int)G[v].size() > bound[n]) {
	    return false;
	}

	EACH (e, G[v]) if (!ban[*e]) {
	    int w = v ^ X[*e] ^ Y[*e];
	    if (w != par[v]) {
		par[w] = v;
		par_id[w] = *e;
		que.push_back(w);
	    }
	}
    }

    if (n == 5) return true;
    if (ma <= 2) return true;

    ULL h = 0;
    if (n <= LIMIT) {
	REP (i, n) h ^= Z[que[i]];
	auto it = mp.find(h);
	if (it != mp.end()) return it->second;
    }
    assert(n == (int)que.size());

    int guess0 = -1, guess1 = -1;
    int a0, a1;
    int b0, b1;
    int sz0, sz1;

    REP (i, n) {
	int v = que[n-i-1];
	sz[v] = 1;
	EACH (e, G[v]) if (!ban[*e]) {
	    int w = v ^ X[*e] ^ Y[*e];
	    if (w != par[v]) {
		sz[v] += sz[w];
	    }
	}

	if (v != s && is_fib[sz[v]] && is_fib[n-sz[v]]) {
	    assert(sz[v] != n-sz[v]);
	    assert(2*min(sz[v],n-sz[v]) >= max(sz[v], n-sz[v])); 

	    if (guess0 == -1) {
		guess0 = par_id[v];
		a0 = v;
		b0 = par[v];
		sz0 = sz[v];
	    } else if (guess1 == -1) {
		guess1 = par_id[v];
		a1 = v;
		b1 = par[v];
		sz1 = sz[v];
	    } else {
		assert(false);
	    }
	}
    }
    assert(sz[s] == n);

    bool ret = false;

    if (!ret && guess0 != -1) {
	assert(!ban[guess0]);
	ban[guess0] = true;
	if (sz0 > n-sz0) {
	    swap(a0, b0);
	    sz0 = n-sz0;
	}

	ret = true;
	if (ret) {
	    int a_idx;
	    EACH (e, G[a0]) if (*e == guess0) {
		a_idx = e - G[a0].begin();
		break;
	    }
	    G[a0][a_idx] = G[a0].back();
	    G[a0].pop_back();

	    ret = rec(a0, sz0);

	    G[a0].push_back(guess0);
	    swap(G[a0].back(), G[a0][a_idx]);
	}
	if (ret) {
	    int b_idx;
	    EACH (e, G[b0]) if (*e == guess0) {
		b_idx = e - G[b0].begin();
		break;
	    }
	    G[b0][b_idx] = G[b0].back();
	    G[b0].pop_back();

	    ret = rec(b0, n - sz0);

	    G[b0].push_back(guess0);
	    swap(G[b0].back(), G[b0][b_idx]);
	}
	
	assert(ban[guess0]);
	ban[guess0] = false;
    }

    if (n <= LIMIT) {
	mp[h] = ret;
    }
    return ret;
}

void MAIN() {

#ifndef LOCAL
    scanf("%d", &N);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	X[i] = x;
	Y[i] = y;
	G[x].push_back(i);
	G[y].push_back(i);
    }
#endif


#ifdef LOCAL
    N = 196418;
    REP (i, N-1) {
	X[i] = i;
	Y[i] = i+1;
	if (i >= N-2712) {
	    rand();
	    rand();
	    rand();
	    rand();
	    rand();
	    X[i] = rand() % (i+1);
	}
	G[X[i]].push_back(i);
	G[Y[i]].push_back(i);
    }
    UnionFind U(N);
    REP (i, N-1) {
	assert(!U.same(X[i], Y[i]));
	U.link(X[i], Y[i]);
    }
    assert(U.count_tree() == 1);
#endif

    REP (i, N) Z[i] = engine();

    int a = 1;
    int b = 1;
    REP (t, 50) {
	if (a > N) break;
	// eprintf("%d %d\n", t, a);
	is_fib[a] = true;
	bound[a] = t-1;
	a += b;
	swap(a, b);
    }

    bool yes = is_fib[N];
    if (yes) yes = rec(0, N);

    puts(yes? "YES": "NO");
    eprintf("%lld %lld %d\n", cnt, sum, (int)mp.size());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}