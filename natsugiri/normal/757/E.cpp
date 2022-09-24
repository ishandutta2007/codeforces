#include<map>
#include<set>
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
    unsigned x;
    void undef() { x = (unsigned)-1; }
    bool isnan() const { return x == (unsigned)-1; }
    inline int getInt() const { return (int)x; }
    template<class T> T get() const { return (T)x; }
    ModInt(int y=0) { if (y<0 || (int)MOD<=y) y %= (int)MOD; if (y<0) y += MOD; x=y; }
    ModInt(long long y) { if (y<0 || MOD<=y) y %= MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned long long y) { if (MOD<=y) x = y % MOD; else x = y; }
    ModInt &operator+=(const ModInt &y) { if ((x += y.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(const ModInt &y) { if ((x -= y.x) & (1u<<31)) x += MOD; return *this; }
    ModInt &operator*=(const ModInt &y) { x = (unsigned long long)x * y.x % MOD; return *this; }
    ModInt &operator/=(const ModInt &y) { x = (unsigned long long)x * y.inv().x % MOD; return *this; }
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
Mint operator+(Mint x, const Mint &y) { if ((x.x += y.x) >= (unsigned)MOD) x.x -= (unsigned)MOD; return x; }
Mint operator-(Mint x, const Mint &y) { if ((x.x -= y.x) & (1u<<31)) x.x += (unsigned)MOD; return x; }
Mint operator*(Mint x, const Mint &y) { x.x = (unsigned long long)x.x * y.x % (unsigned long long)MOD; return x; }
Mint operator/(Mint x, const Mint &y) { x.x = (unsigned long long)x.x * y.inv().x % (unsigned long long)MOD; return x; }
bool operator<(const Mint &x, const Mint &y) { return x.x < y.x; }
bool operator==(const Mint &x, const Mint &y) { return x.x == y.x; }
bool operator!=(const Mint &x, const Mint &y) { return x.x != y.x; }

//const LL MOD = 1000000007;
const int MAX = 3000100;
LL inv[MAX+1], fact[MAX+1], fact_inv[MAX+1];

void init() {
    inv[1] = 1;
    for (int i=2; i<=MAX; i++) inv[i] = inv[MOD%i] * (MOD-MOD/i) % MOD;

    fact[0] = fact_inv[0] = 1;
    for (int i=1; i<=MAX; i++) {
	fact[i] = fact[i-1] * i % MOD;
	fact_inv[i] = fact_inv[i-1] * inv[i] % MOD;
    }
}

LL nCk(int n, int k) {
    return fact[n] * fact_inv[k] % MOD * fact_inv[n-k] % MOD;
}

// const int MAX = 10000000;
int min_factor[MAX+1];
vector<int>prime;
void make_prime() {
    for (int i=2; i<=MAX; i+=2) min_factor[i] = 2;
    for (int i=3; i<=MAX; i+=3) if (!min_factor[i]) min_factor[i] = 3;
    for (int i=5, d=2; i*i<=MAX; ) {
	if (!min_factor[i]) {
	    min_factor[i] = i;
	    for (int j=i*i; j<=MAX; j+=i)
		if (!min_factor[j]) min_factor[j] = i;
	}
	i += d; d = 6 - d;
    }
    for (int i=2; i<=MAX; i++) {
	if (min_factor[i]==0) min_factor[i] = i;
	if (min_factor[i]==i) prime.push_back(i);
    }
}

vector<pair<LL, int> > fast_prime_factor(int n) { // n<=MAX
    vector<pair<LL, int> >r;
    while (n > 1) {
	int t = min_factor[n], cnt = 0;
	while (n%t == 0) { n /= t, cnt++; }
	r.push_back(make_pair(t, cnt));
    }
    return r;
}



int main() {
    init();
    make_prime();

    int Q;
    scanf("%d", &Q);
//    Q = 1000000;
    REP ($, Q) {
	int R, N;
	scanf("%d%d", &R, &N);
//	N = 720720;
//	R = 1000000;

	vector<pair<LL, int> > p = fast_prime_factor(N);
	Mint ans = 1;
	EACH (e, p) {
	    int k = e->second;
	    Mint tmp = nCk(R + k - 1, k - 1) * 2 +
		nCk(R + k - 1, k);
	    ans *= tmp;
	}

	printf("%d\n", ans.getInt());
    }


    return 0;

    return 0;
}