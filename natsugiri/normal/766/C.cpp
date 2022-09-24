#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

template<unsigned MOD> struct ModInt {
    static const unsigned static_MOD = MOD;
    unsigned x;
    void undef() { x = (unsigned)-1; }
    bool isnan() const { return x == (unsigned)-1; }
    inline int getInt() const { return (int)x; }
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

    ModInt inv() const {
	unsigned a = MOD, b = x; int u = 0, v = 1;
	while (b) {
	    int t = a / b;
	    a -= t * b; swap(a, b);
	    u -= t * v; swap(u, v);
	}
	if (u < 0) u += MOD;
	return ModInt(u);
    }
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

    static ModInt buffered_inv(const ModInt y) {
	static ModInt *inv_tbl = NULL;
	if (inv_tbl == NULL) {
	    const int n = 2000001;
	    inv_tbl = new ModInt[n];
	    inv_tbl[0] = 0; inv_tbl[1] = 1;
	    for (int i=2; i<n; i++) inv_tbl[i] = ModInt((unsigned long long)inv_tbl[MOD%i].x * (MOD-MOD/i));
	}
	return inv_tbl[y.x];
    }
};

const LL MOD = 1000000007;
typedef ModInt<MOD> Mint;

int N;
char S[1111];
int A[33];
int cnt[33];

Mint dp[1111];
int task1() {
    dp[0] = 1;
    REP (i, N) if (dp[i].x) {
	memset(cnt, 0, sizeof cnt);
	int limit = N + N;
	for (int j=i; j<N; j++) {
	    cnt[S[j]-'a']++;
	    amin(limit, A[S[j]-'a']);
	    if (j-i+1 <= limit) dp[j+1] += dp[i];
	    else break;
	}
    }
    return dp[N].getInt();
}
int task2() {
    memset(cnt, 0, sizeof cnt);
    int last = 0;
    int ans = 0;
    REP (i, N) {
	cnt[S[i]-'a']++;
	int limit = N + N;
	while (1) {
	    REP (c, 26) if (cnt[c]) {
		amin(limit, A[c]);
	    }
	    if (i - last + 1 > limit) {
		cnt[S[last]-'a']--;
		last++;
	    } else {
		break;
	    }
	}
	amax(ans, i - last + 1);
    }
    return ans;
}

int task3() {
    memset(cnt, 0, sizeof cnt);
    int last = 0;
    int ans = 0;
    REP (i, N) {
	cnt[S[i]-'a']++;
	int limit = N + N;
	REP (c, 26) if (cnt[c]) {
	    amin(limit, A[c]);
	}
	if (i - last + 1 > limit) {
	    ans++;
	    while (last < i) {
		cnt[S[last]-'a']--;
		last++;
	    }
	}
    }
    ans++;
    return ans;
}

int main() {
    scanf("%d%s", &N, S);
    REP (i, 26) scanf("%d", A+i);

    printf("%d\n", task1());
    printf("%d\n", task2());
    printf("%d\n", task3());

    return 0;
}