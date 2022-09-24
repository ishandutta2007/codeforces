#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

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
template<unsigned MOD_> struct ModInt {
    static constexpr unsigned MOD = MOD_;
    unsigned x;
    void undef() { x = (unsigned)-1; }
    bool isnan() const { return x == (unsigned)-1; }
    inline int geti() const { return (int)x; }
    ModInt() { x = 0; }
    ModInt(int y) { if (y<0 || (int)MOD<=y) y %= (int)MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned y) { if (MOD<=y) x = y % MOD; else x = y; }
    ModInt(long long y) { if (y<0 || MOD<=y) y %= MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned long long y) { if (MOD<=y) x = y % MOD; else x = y; }
    ModInt &operator+=(const ModInt y) { if ((x += y.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(const ModInt y) { if ((x -= y.x) & (1u<<31)) x += MOD; return *this; }
    ModInt &operator*=(const ModInt y) { x = (unsigned long long)x * y.x % MOD; return *this; }
    ModInt &operator/=(const ModInt y) { x = (unsigned long long)x * y.inv().x % MOD; return *this; }
    ModInt operator-() const { return (x ? MOD-x: 0); }

    ModInt inv() const { return pow(MOD-2); }
    ModInt pow(long long y) const {
	ModInt b = *this, r = 1;
	if (y < 0) { b = b.inv(); y = -y; }
	for (; y; y>>=1) {
	    if (y&1) r *= b;
	    b *= b;
	}
	return r;
    }

    friend ModInt operator+(ModInt x, const ModInt y) { return x += y; }
    friend ModInt operator-(ModInt x, const ModInt y) { return x -= y; }
    friend ModInt operator*(ModInt x, const ModInt y) { return x *= y; }
    friend ModInt operator/(ModInt x, const ModInt y) { return x *= y.inv(); }
    friend bool operator<(const ModInt x, const ModInt y) { return x.x < y.x; }
    friend bool operator==(const ModInt x, const ModInt y) { return x.x == y.x; }
    friend bool operator!=(const ModInt x, const ModInt y) { return x.x != y.x; }
};

constexpr LL MOD = 998244353;
using Mint = ModInt<MOD>;

int N, M;
LL A[1011];
VI G[1011];
int deg[1011];

VI que;

vector<pair<LL, LL> > X[1011];
vector<pair<LL, LL> > aux;

void MAIN() {
    scanf("%d%d", &N, &M);

    REP (i, N) G[i].clear();
    memset(deg, 0, sizeof (int) * N);

    REP (i, N) scanf("%lld", A+i);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	deg[y]++;
    }

    REP (i, N) X[i].clear();

    que.clear();
    REP (i, N) if (deg[i] == 0) {
	que.push_back(i);
    }

    REP (i_, N) {
	int v = que[i_];
	if (A[v]) {
	    X[v].emplace_back(0, A[v]);
	}
	if (X[v].size() >= 2u) {
	    sort(X[v].begin(), X[v].end());
	    aux.clear();
	    REP (j, X[v].size()) {
		if (aux.empty() || aux.back().second < X[v][j].first) {
		    aux.push_back(X[v][j]);
		} else {
		    aux.back().second += X[v][j].second - X[v][j].first;
		}
	    }
	    swap(X[v], aux);
	}

	EACH (e, X[v]) {
	    if (e->second >= 100 * MOD) {
		e->second = (e->second - 100 * MOD) % MOD + 100 * MOD;
	    }
	}

//	eprintf("v = %d, (%d %d)\n", v+1, (int)X[v].size(), (int)aux.size());
//	EACH (e, X[v]) eprintf("[%lld %lld) ", e->first, e->second);
//	eprintf("\n");

	EACH (e, G[v]) {
	    EACH (f, X[v]) {
		X[*e].emplace_back(f->first+1, f->second+1);
	    }

	    deg[*e]--;
	    if (deg[*e] == 0) {
		que.push_back(*e);
	    }
	}
    }

    // rprintf("%d", que.begin(), que.end());

    LL ans = 0;
    if (X[que.back()].empty()) {
	ans = 0;
    } else {
	ans = X[que.back()].back().second;
    }
    printf("%lld\n", ans % MOD);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}