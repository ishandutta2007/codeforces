#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }
template<int MOD>
struct ModInt {
    unsigned x;
    void undef() { x = (unsigned)-1; }
    bool isnan() const { return x == (unsigned)-1; }
    inline int getInt() const { return (int)x; }
    template<class T> T get() const { return (T)x; }
    inline int mod() const { return MOD; }
    ModInt(int y=0) { if (y<0 || MOD<=y) y %= MOD; if (y<0) y += MOD; x=y; }
    ModInt(long long y) { if (y<0 || MOD<=y) y %= MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned long long y) { if (MOD<=y) x = y % (unsigned long long)MOD; else x = y; }
    ModInt &operator+=(const ModInt &y) { if ((x += y.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(const ModInt &y) { if ((x += MOD - y.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(const ModInt &y) { x = (unsigned long long)x * y.x % (unsigned long long)MOD; return *this; }
    ModInt &operator/=(const ModInt &y) { x = (unsigned long long)x * y.inv().x % (unsigned long long)MOD; return *this; }
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
};
const LL MOD = 1000000007;
typedef ModInt<MOD> Mint;
Mint operator+(Mint x, const Mint &y) { if ((x.x += y.x) >= (unsigned)x.mod()) x.x -= x.mod(); return x; }
Mint operator-(Mint x, const Mint &y) { if ((x.x += x.mod() - y.x) >= (unsigned)x.mod()) x.x -= x.mod(); return x; }
Mint operator*(Mint x, const Mint &y) { x.x = (unsigned long long)x.x * y.x % (unsigned long long)x.mod(); return x; }
Mint operator/(Mint x, const Mint &y) { x.x = (unsigned long long)x.x * y.inv().x % (unsigned long long)x.mod(); return x; }
bool operator<(const Mint &x, const Mint &y) { return x.x < y.x; }
bool operator==(const Mint &x, const Mint &y) { return x.x == y.x; }
bool operator!=(const Mint &x, const Mint &y) { return x.x != y.x; }

int N, M;
char S[100111];
const int MAX = 2222;
Mint dp[MAX+11][MAX+11];

int main() {
    scanf("%d%d%s", &N, &M, S);
    if (N & 1) {
	puts("0");
	return 0;
    }

    int lo = 0, hi = 0, al = 0;
    REP (i, M) {
	if (S[i] == '(') al++;
	else al--;
	amin(lo, al);
    }
    al = 0;
    for (int i=M; i--; ) {
	if (S[i] == '(') al++;
	else al--;
	amax(hi, al);
    }

    dp[0][0] = 1;
    REP (i, MAX) {
	REP (j, i+1) {
	    // (
	    dp[i+1][j+1] += dp[i][j];

	    // )
	    if (j) dp[i+1][j-1] += dp[i][j];
	}
    }

    Mint ans = 0;
    REP (i, N-M+1) {
	int ii = N-M-i;
	for (int j=-lo; j<MAX; j++) {
	    int jj = j+lo+hi;
	    if (0 <= jj && jj < MAX) {
		// int tmp = (dp[i][j] * dp[ii][jj]).getInt();
		// if (tmp)eprintf("%d %d %d %d : %d\n", i, j, ii, jj, tmp);
		ans += dp[i][j] * dp[ii][jj];
	    }
	}
    }

    printf("%d\n", ans.getInt());
    
    return 0;
}