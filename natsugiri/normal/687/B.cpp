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

LL gcd(LL x, LL y) {
    while (y) {
	LL t = x % y;
	x = y;
	y = t;
    }
    return x;
}
LL lcm(LL x, LL y) {
    return x / gcd(x, y) * y;
}

int N, K;

int main() {
    scanf("%d%d", &N, &K);
    LL g = 1;
    REP (i, N) {
	int p;
	scanf("%d", &p);
	g = gcd(K, lcm(g, p));
    }

    puts(g == K? "Yes": "No");

    return 0;
}