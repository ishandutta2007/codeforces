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

const LL MOD = 1000000007;
typedef ModInt<MOD> Mint;

int N, M;
char F[2011][2011];

Mint R[2011][2011];
Mint D[2011][2011];

int B[2011][2011];
int box(int y0, int x0, int y1, int x1) {
    assert(y0 <= y1);
    assert(x0 <= x1);
    return B[y0][x0] - B[y0][x1] - B[y1][x0] + B[y1][x1];
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%s", F[i]);

    Mint ans = 0;
    if (N == 1 && M == 1) {
	if (F[0][0] == '.') ans = 1;
    } else {
	REP (i, N) REP (j, M) {
	    B[i+1][j+1] = B[i][j+1] + B[i+1][j] - B[i][j] + (F[i][j] == 'R');
	}


	{
	    int b = box(0, 1, 1, M);
	    R[0][0] += 1;
	    R[0][M-1-b] -= 1;
	}
	{
	    int b = box(1, 0, N, 1);
	    D[0][0] += 1;
	    D[N-1-b][0] -= 1;
	}

	REP (i, N) REP (j, M) {
	    if (i+1 < N && D[i][j].x) {
		D[i+1][j] += D[i][j];
		int b = box(i+1, j+1, i+2, M);
		R[i+1][j] += D[i][j];
		R[i+1][M-1-b] -= D[i][j];
	    }
	    if (j+1 < M && R[i][j].x) {
		R[i][j+1] += R[i][j];
		int b = box(i+1, j+1, N, j+2);
		D[i][j+1] += R[i][j];
		D[N-1-b][j+1] -= R[i][j];
	    }
	}

	if (N >= 2) ans += D[N-2][M-1];
	if (M >= 2) ans += R[N-1][M-2];
    }

    printf("%d\n", ans.geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}