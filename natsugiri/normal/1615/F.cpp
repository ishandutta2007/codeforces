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

constexpr LL MOD = 1000000007;
using Mint = ModInt<MOD>;

int N;
char A[2011];
char B[2011];

#ifdef LOCAL
const int BASE = 20;
#else
const int BASE = 2011;
#endif

Mint buf[4][BASE * 2 + 5];
Mint *cur = buf[0];
Mint *nxt = buf[1];
Mint *cur_sum = buf[2];
Mint *nxt_sum = buf[3];


bool check0(char c) {
    return c == '0' || c == '?';
}
bool check1(char c) {
    return c == '1' || c == '?';
}

void MAIN() {
    scanf("%d%s%s", &N, A, B);

    memset(cur, 0, sizeof buf[0]);
    memset(cur_sum, 0, sizeof buf[0]);
    cur[BASE] = 1;

    REP (i, N) {
	memset(nxt, 0, sizeof buf[0]);
	memset(nxt_sum, 0, sizeof buf[0]);

	for (int k=1; k<BASE*2-1; k++) if (cur[k].x) {
	    if (check0(A[i]) && check0(B[i])) {
		nxt[k] += cur[k];
		nxt_sum[k] += cur_sum[k];
	    }

	    if (check1(A[i]) && check1(B[i])) {
		nxt[k] += cur[k];
		nxt_sum[k] += cur_sum[k];
	    }

	    if ((i % 2 == 0 && check0(A[i]) && check1(B[i])) ||
		    (i % 2 == 1 && check1(A[i]) && check0(B[i]))) {
		nxt[k-1] += cur[k];
		if (k-BASE > 0) {
		    nxt_sum[k-1] += cur_sum[k] + cur[k] * i;
		} else {
		    nxt_sum[k-1] += cur_sum[k] - cur[k] * i;
		}
	    }

	    if ((i % 2 == 0 && check1(A[i]) && check0(B[i])) ||
		    (i % 2 == 1 && check0(A[i]) && check1(B[i]))) {
		nxt[k+1] += cur[k];

		if (k-BASE < 0) {
		    nxt_sum[k+1] += cur_sum[k] + cur[k] * i;
		} else {
		    nxt_sum[k+1] += cur_sum[k] - cur[k] * i;
		}
	    }
	}
	swap(cur, nxt);
	swap(cur_sum, nxt_sum);

    }

    Mint ans = cur_sum[BASE];
    printf("%d\n", ans.geti());
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}