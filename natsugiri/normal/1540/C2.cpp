#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
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
int C[111];
int B[111];
int Q;
LL sums[111];
LL sums2[111];

Mint buf[2][10011];
Mint *cur = buf[0];
Mint *nxt = buf[1];


LL LOW, HIGH;
Mint mem[6000];
Mint solve(LL X) {
    if (HIGH < X) return 0;

    if (X < LOW) X = LOW;
    if (!mem[X + 5000].isnan()) return mem[X + 5000];

    memset(cur, 0, sizeof (Mint) * (101));
    for (LL a=max(0LL, X); a<=C[0]; a++) {
	cur[a] = 1;
    }
    for (int i=1; i<N; i++) {
	int len = i + 1;
	memset(nxt, 0, sizeof (Mint) * (100 * len + 1));

	REP (s, 100*i+1) if (cur[s].x) {
	    // X <= (a + s - sums2[len]) / len;
	    LL lo = max(0LL, X * len - s + sums2[len]);
	    if (lo <= C[i]) {
		nxt[s + lo] += cur[s];
		nxt[s + C[i] + 1] -= cur[s];
	    }
	}

	REP (s, 100*len+1) nxt[s+1] += nxt[s];
	swap(cur, nxt);
    }

    Mint ans = 0;
    REP (s, 100*N+1) ans += cur[s];
    return mem[X + 5000] = ans;
}

void MAIN() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    REP (i, N) cin >> C[i];
    REP (i, N-1) cin >> B[i];
    // scanf("%d", &N);
    // REP (i, N) scanf("%d", C+i);
    // REP (i, N-1) scanf("%d", B+i);

#ifdef LOCAL
    N = 100;
    REP (i, N) C[i] = 100;
    REP (i, N-1) B[i] = 100;
#endif

    REP (i, N-1) sums[i+1] = sums[i] + B[i];
    LL total = 0;
    REP (i, N) total += sums[i];
    REP (i, N) sums2[i+1] = sums2[i] + sums[i];

    {
	LL c_sum = 0;
	REP (i, N) {
	    int len = i + 1;
	    c_sum += C[i];
	    amin(LOW, -sums2[len] / len - 1);
	    amax(HIGH, (c_sum - sums2[len]) / len + 1);
	}
    }
    // eprintf("%lld %lld\n", LOW, HIGH);

    memset(mem, -1, sizeof mem);

    cin >> Q;
    REP ($, Q) {
        LL X;
	cin >> X;
	Mint ans = solve(X);
	cout << ans.geti() << '\n';
    }

    // scanf("%d", &Q);
    // REP ($, Q) {
    //     LL X;
    //     scanf("%lld", &X);
    //     Mint ans = solve(X);
    //     printf("%d\n", ans.geti());
    // }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}