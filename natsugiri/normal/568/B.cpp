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
    void undef() { x = -1; }
    bool isnan() { return x == -1; }
    template<class T> T get() const {return (T)x; }
    int mod() const { return MOD; }
    ModInt(int y=0) { if (y<0 || MOD<=y) y %= MOD; if (y<0) y += MOD; x=y; }
    ModInt(long long y) { if (y<0 || MOD<=y) y %= MOD; if (y<0) y += MOD; x=y; }
    ModInt &operator+=(ModInt y) { if((x += y.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(ModInt y) { if((x += MOD - y.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(ModInt y) { x = (unsigned long long)x * y.x % MOD; return *this; }
    ModInt operator+(ModInt y) const { return ModInt(*this) += y; }
    ModInt operator-(ModInt y) const { return ModInt(*this) -= y; }
    ModInt operator*(ModInt y) const { return ModInt(*this) *= y; }
    ModInt operator-() const { return (x > 0u? MOD-(int)x: 0); }
    bool operator<(ModInt y) const { return x < y.x; }
    bool operator==(ModInt y) const { return x == y.x; }
    bool operator!=(ModInt y) const { return x != y.x; }
    ModInt inv() const {
	int a = x, b = MOD, u = 1, v = 0;
	while(b) {
	    int t = a / b;
	    a -= t * b; swap(a, b);
	    u -= t * v; swap(u, v);
	}
	if(u < 0) u += MOD;
	return ModInt(u);
    }
    ModInt pow(long long y) const {
	ModInt x = *this;
	if (y < 0) { x = x.inv(); y = -y; }
	ModInt r = 1;
	for (; y; y>>=1) {
	    if (y&1) r *= x;
	    x *= x;
	}
	return r;
    }
};
typedef ModInt<(int)(1e9+7)> Mint;

Mint dpX[4011][4011];
Mint dp1[4011][4011];

int main() {
    int N;
    scanf("%d", &N);

    dpX[0][0] = 1;
    REP (i, N) {
	REP (j, i+2) {
	    dpX[i+1][j] += dpX[i][j] * j;
	    dpX[i+1][j+1] += dpX[i][j];
	    dp1[i+1][j] += dpX[i][j] + dp1[i][j] * (j+1);
	    dp1[i+1][j+1] += dp1[i][j];
	}
    }

    Mint ans = 0;
    REP (i, N+1) ans += dp1[N][i];
    printf("%d\n", ans.get<int>());

    return 0;
}