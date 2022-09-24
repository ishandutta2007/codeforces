#include<set>
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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

template<unsigned MOD_> struct ModInt {
    static const unsigned MOD = MOD_;
    unsigned x;
    void undef() { x = (unsigned)-1; }
    bool isnan() const { return x == (unsigned)-1; }
    inline int geti() const { return (int)x; }
    ModInt() { x = 0; }
    ModInt(const ModInt &y) { x = y.x; }
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

    ModInt extgcd() const {
	unsigned a = MOD, b = x; int u = 0, v = 1;
	while (b) {
	    int t = a / b;
	    a -= t * b; swap(a, b);
	    u -= t * v; swap(u, v);
	}
	if (u < 0) u += MOD;
	return ModInt(u);
    }

    friend ModInt operator+(ModInt x, const ModInt y) { return x += y; }
    friend ModInt operator-(ModInt x, const ModInt y) { return x -= y; }
    friend ModInt operator*(ModInt x, const ModInt y) { return x *= y; }
    friend ModInt operator/(ModInt x, const ModInt y) { return x *= y.inv(); }
    friend bool operator<(const ModInt x, const ModInt y) { return x.x < y.x; }
    friend bool operator==(const ModInt x, const ModInt y) { return x.x == y.x; }
    friend bool operator!=(const ModInt x, const ModInt y) { return x.x != y.x; }
};

const LL MOD = 998244353;
typedef ModInt<MOD> Mint;
int N, M;
int C[1000011];
int Ma[1011];
Mint dp[1011][1011];
Mint dx[511];
VI G[511];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) scanf("%d", C+i);


    int last = 0;
    for (int i=1; i<M; i++) {
	if (C[i] != C[last]) {
	    C[++last] = C[i];
	}
    }
    M = last+1;

    if (M >= 1011) {
	puts("0");
	return;
    }
    //eprintf("M %d\n", M);

    REP (i, M) G[C[i]].push_back(i);
    set<int> se;
    for (int i=1; i<=N; i++) {
	int mi = G[i].front();
	int ma = G[i].back();
	auto it = se.lower_bound(mi);
	if (it != se.end() && *it < ma) {
	    puts("0");
	    return;
	}
	EACH (e, G[i]) se.insert(*e);
	for (int j=G[i].front(); j<G[i].back(); j++) Ma[j] = i;
    }

    //rprintf("%d", C, C+M);
    //rprintf("%d", Ma, Ma+M);

    REP (i, M+1) dp[i][i] = 1;
    for (int i=M-1; i>=0; i--) {
	int pivot = i;
	int color = C[pivot];
	if (G[color].front() == pivot) {
	    dx[color] = 1;
	    REP (j, (int)G[color].size()-1) {
		int a = G[color][j];
		int b = G[color][j+1];
		dx[color] *= dp[a+1][b];
	    }
	}

	for (int j=i+1; j<=M; j++) {
	    if (C[pivot] > C[j-1]) pivot = j-1;
	    color = C[pivot];

	    int bak = G[color].back();
	    if (pivot == G[color].front() && bak < j) {
		Mint L = 0, R = 0;
		for (int k=i; k<=pivot; k++) {
		    if (k && Ma[k-1] > color) continue;
		    L += dp[i][k] * dp[k][pivot];
		}
		for (int k=bak+1; k<=j; k++) {
		    if (k && Ma[k-1] > color) continue;
		    R += dp[bak+1][k] * dp[k][j];
		}
		dp[i][j] = L * R * dx[color];
		//eprintf("%d %d (%d): %d\n", i, j, C[i], dp[i][j].geti());
	    }
	}
    }
    printf("%d\n", dp[0][M].geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}