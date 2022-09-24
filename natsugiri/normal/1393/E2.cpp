#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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
    static constexpr unsigned MOD = MOD_;
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
string W[100011];
char buf[1000011];

char get_char(const vector<char> &s, int i) {
    assert(i >= 0);
    if ((int)s.size() <= i) return '$';
    return s[i];
}

Mint dpL[1000011][2][2];
Mint dpR[1000011][2][2];

vector<char> S, T;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	scanf("%s", buf);
	W[i] = buf;
    }

    vector<Mint> cur, nxt;
    cur.assign(W[0].size()+1, 1);

    REP (t, N-1) {

	int len = max(W[t].size(), W[t+1].size()) + 1u;

	S.assign(len, '$');
	REP (i, W[t].size()) S[i] = W[t][i];
	T.assign(len, '$');
	REP (i, W[t+1].size()) T[i] = W[t+1][i];


	// 0 : E
	// 1 : G
	memset(dpL, 0, (sizeof dpL[0]) * (len + 1));
	dpL[0][0][0] = 1;
	REP (i, len) REP (s, 2) REP (u, 2) if (dpL[i][s][u].x) {
	    for (int ds=0; ds+s<2; ds++) {
		if (i >= (int)W[t].size()+1 && ds) continue;
		char a = get_char(S, i+s+ds);
		char b = get_char(T, i);

		if (u == 0 && a > b) continue;

		int nu = u;
		if (a < b) nu = 1;

		Mint rate = 1;
		if (ds) {
		    rate = cur[i];
		}

		dpL[i+1][s+ds][nu] += dpL[i][s][u] * rate;

	    }
	}

	reverse(S.begin(), S.end());
	reverse(T.begin(), T.end());

	// 0 : EG;
	// 1 : L;
	memset(dpR, 0, (sizeof dpR[0]) * (len + 1));
	dpR[0][0][0] = 1;
	REP (i, len) REP (s, 2) REP (u, 2) if (dpR[i][s][u].x) {
	    for (int ds=0; ds+s<2; ds++) {

		int ii = len - i - 1;
		if (ii >= (int)W[t].size()+1 && ds) continue;

		char a = get_char(S, i+s+ds);
		char b = get_char(T, i);

		int nu;
		if (a == b) nu = u;
		else if (a < b) nu = 0;
		else nu = 1;

		Mint rate = 1;
		if (ds) {
		    rate = cur[ii];
		}

		dpR[i+1][s+ds][nu] += dpR[i][s][u] * rate;

	    }
	}

	nxt.assign(W[t+1].size()+1u, 0);

	REP (i, W[t+1].size()+1u) {
	    int j = len - i - 1;
	    REP (a, 2) REP (b, 2) if (a + b <= 1) {
		if (a == 0 && b == 0 && (int)W[t].size() < i) continue;
		Mint rate = 1;
		if (a == 0 && b == 0) {
		    rate = cur[i];
		}

		REP (x, 2) REP (y, 2) {
		    if ((x == 0 && y == 0) || (x == 1)) {
			nxt[i] += dpL[i][a][x] * dpR[j][b][y] * rate;
		    }
		}
	    }
	}

	swap(cur, nxt);
    }

    Mint ans = 0;
    EACH (e, cur) ans += *e;
    printf("%d\n", ans.geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}