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

unsigned uMod;

struct Mint {
    unsigned x;

    Mint() : x(0) {}
    Mint(const Mint &y) : x(y.x) {}
    Mint(unsigned y) { if (uMod <= y) y %= uMod; x = y; }
    Mint(int y) { if (y < 0 || (int)uMod <= y) y %= uMod; if (y < 0) y += uMod; x = y; }
    Mint(unsigned long long y) { if (uMod <= y) y %= uMod; x = y; }
    Mint(long long y) { if (y < 0 || uMod <= y) y %= uMod; if (y < 0) y += uMod; x = y; }

    Mint& operator+=(const Mint &y) { if ((x += y.x) >= uMod) x -= uMod; return *this; }
    Mint& operator-=(const Mint &y) { if ((x += uMod - y.x) >= uMod) x -= uMod; return *this; }
    Mint& operator*=(const Mint &y) { x = (unsigned long long)x * y.x % uMod; return *this; }
    Mint& operator/=(const Mint &y) { x = (unsigned long long)x * y.inv().x % uMod; return *this; }
    Mint operator-() const { return x? uMod - x: 0; }

    Mint inv() const {
	unsigned a = uMod, b = x; int u = 0, v = 1;
	while (b) {
	    int t = a / b;
	    a -= t * b; swap(a, b);
	    u -= t * v; swap(u, v);
	}
	if (u < 0) u += uMod;
	return Mint(u);
    }

    Mint pow(long long y) const {
	Mint b = *this, r = 1;
	if (y < 0) { b = b.inv(); y = -y; }
	for (; y; y>>=1) {
	    if (y&1) r *= b;
	    b *= b;
	}
	return r;
    }

    friend Mint operator+(Mint x, const Mint &y) { return x += y; }
    friend Mint operator-(Mint x, const Mint &y) { return x -= y; }
    friend Mint operator*(Mint x, const Mint &y) { return x *= y; }
    friend Mint operator/(Mint x, const Mint &y) { return x /= y; }
    friend bool operator<(const Mint x, const Mint y) { return x.x < y.x; }
    friend bool operator==(const Mint x, const Mint y) { return x.x == y.x; }
    friend bool operator!=(const Mint x, const Mint y) { return x.x != y.x; }
};

const int MAX = 1000010;

LL A, B, MOD, X;
//Mint dp[MAX];
Mint dp1[MAX];
LL mp[MAX];


LL CYCLE;


void MAIN() {
    scanf("%lld%lld%lld%lld", &A, &B, &MOD, &X);
    uMod = MOD;

    if (B == 0) {
	printf("%lld\n", X/MOD);
	return;
    }

    Mint YA = 1;
    for (int i=1; i<MOD; i++) {
	mp[(YA * i).x]++;
//	dp[i] = YA * i * A;
	YA *= A;
    }

    LL sum = 0;
    LL ans = 0;
    // 1, P+1, 2P+1, ...
    Mint ZA = Mint(A).pow(MOD);
    YA = A;
    for (int i=0; ; i++) {
	dp1[i] = Mint(i * MOD + 1) * YA;
	if (i && dp1[i] == dp1[0]) {
	    CYCLE = i;
	    break;
	} else {
	    sum += mp[(Mint(B) / dp1[i]).x];
	}
	YA *= ZA;
    }

    LL R1 = X / (MOD * CYCLE);
    X %= (MOD * CYCLE);
    ans += sum * R1;

    int tail = X / MOD;
    REP (i, tail) {
	ans += mp[(Mint(B) / dp1[i]).x];
    }
    int tail_tail = X % MOD;
    YA = dp1[tail];
    for (int i=1; i<=tail_tail; i++) {
	if (YA * i == B) ans++;
	YA *= A;
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}