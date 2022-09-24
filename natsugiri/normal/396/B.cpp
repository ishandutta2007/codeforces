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

typedef unsigned long long ULL;

inline ULL mulMod(ULL x, ULL y, ULL m) {
    if (x >= m) x %= m;
    if (y >= m) y %= m;
    if (x < (1ULL<<31) && y < (1ULL<<31)) return x * y % m;
    ULL r = 0;
    for (; y; y>>=1) {
	if (y&1) { if ((r += x) >= m) r -= m; }
	if ((x += x) >= m) x -= m;
    }
    return r;
}
ULL powMod(ULL x, ULL y, ULL m) {
    if (x >= m) x %= m;
    ULL r = 1;
    for (; y; y>>=1) {
	if (y&1) r = mulMod(r, x, m);
	x = mulMod(x, x, m);
    }
    return r;
}
bool suspect(ULL a, unsigned s, ULL d, ULL n) {
    ULL x = powMod(a, d, n);
    if (x == 1) return true;
    for (unsigned r = 0; r < s; ++r) {
	if (x == n - 1) return true;
	x = mulMod(x, x, n);
    }
    return false;
}
// {2,7,61,-1}                 is for n < 4759123141 (= 2^32)
// {2,3,5,7,11,13,17,19,23,-1} is for n < 10^16 (at least)
bool is_prime(ULL n) {
    if (n <= 1 || (n > 2 && n % 2 == 0)) return false;
    int test[] = {2,3,5,7,11,13,17,19,23,-1};
    ULL d = n - 1, s = 0;
    while (~d & 1) { ++s; d>>=1; }
    for (int i = 0; (ULL)test[i] < n && test[i] != -1; ++i)
	if (!suspect(test[i], s, d, n)) return false;
    return true;
}

ULL gcd(ULL x, ULL y) {
    while (y) {
	ULL t = x % y;
	x = y;
	y = t;
    }
    return x;
}

int N;
int A[100111];

int main() {
    scanf("%d", &N);
    REP ($, N) {
	int x;
	scanf("%d", &x);
	ULL u = x + 1, v = x;
	while (!is_prime(u)) u++;
	while (!is_prime(v)) v--;
	ULL nu = v * u - 2 * u + 2 * x - 2 * v + 2;
	ULL de = 2 * v * u;
	ULL g = gcd(nu, de);
	nu /= g;
	de /= g;
	printf("%llu/%llu\n", nu, de);
    }
    return 0;
}