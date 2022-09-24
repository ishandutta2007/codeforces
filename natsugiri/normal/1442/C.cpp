#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>

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

VI G[400011];

LL D[19][400011];


pair<int, int> DG[400011];

struct Data {
    LL cst;
    int t;
    int v;
    Data() {}
    Data(LL cst_, int t_, int v_): cst(cst_), t(t_), v(v_) {}

    bool operator<(const Data &o) const {
	return cst > o.cst;
    }
};

void MAIN() {
    scanf("%d%d", &N, &M);

    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y+N].push_back(x+N);
    }

    memset(D, 0x3f, sizeof D);
    const LL INF = D[0][0];

    D[0][0] = 0;
    priority_queue<Data> Q;
    Q.emplace(0, 0, 0);

    while (!Q.empty()) {
	Data d = Q.top();
	Q.pop();
	LL cst = d.cst;
	int t = d.t;
	int v = d.v;
	if (D[t][v] != cst) continue;

	EACH (e, G[v]) {
	    if (D[t][*e] > cst + 1) {
		D[t][*e] = cst + 1;
		Q.emplace(cst + 1, t, *e);
	    }
	}

	int w;
	if (v < N) w = v + N;
	else w = v - N;
	LL tmp = cst + (1LL<<t);

	if (t < 18 && D[t+1][w] > tmp) {
	    D[t+1][w] = tmp;
	    Q.emplace(tmp, t+1, w);
	}
    }


    REP (v, N*2) {
	DG[v] = make_pair(1<<29, 1<<29);
    }

    DG[N-1] = DG[2*N-1] = make_pair(0, 0);
    VI q0, q1, q2;
    q0.push_back(N-1);
    q0.push_back(2*N-1);

    while (!q0.empty()) {
	while (!q0.empty()) {
	    while (!q0.empty()) {
		int v = q0.back();
		q0.pop_back();

		int t = DG[v].first;
		int cst = DG[v].second;

		EACH (e, G[v]) {
		    pair<int, int> nxt(t, cst+1);
		    if (DG[*e] > nxt) {
			DG[*e] = nxt;
			q1.push_back(*e);
		    }
		}

		int w;
		if (v < N) w = v + N;
		else w = v - N;

		pair<int, int> nxt(t+1, cst);
		if (DG[w] > nxt) {
		    DG[w] = nxt;
		    q2.push_back(w);
		}
	    }

	    swap(q0, q1);
	}

	swap(q0, q2);
    }


    LL ans = INF;
    REP (t, 19) {
	amin(ans, D[t][N-1]);
	amin(ans, D[t][2*N-1]);
    }

    if (ans == INF) {
	pair<LL, LL> best(1LL<<60, 1LL<<60);
	REP (v, N) if (D[18][v] < INF) {
	    auto p = DG[v+N];
	    pair<LL, LL> tmp(p.first, D[18][v] + p.second);
	    amin(best, tmp);
	}

	// eprintf("%lld %lld\n", best.first, best.second);
	Mint mans = best.second;
	Mint p = Mint(2).pow(18);
	REP (i, best.first) {
	    mans += p;
	    p += p;
	}
	ans = mans.geti();
    } else {
	ans %= MOD;
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}