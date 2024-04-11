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
    while (1) {
	if (x) y %= x; else return y;
	if (y) x %= y; else return x;
    }
}

LL La, Da, Ta;
LL Lb, Db, Tb;

void MAIN() {
    scanf("%lld%lld%lld %lld %lld %lld", &La, &Da, &Ta, &Lb, &Db, &Tb);
    Da = Da - La + 1;
    Db = Db - Lb + 1;

    Lb -= La;
    if (Lb < 0) {
	LL d = (-Lb / Tb + 1) * Tb;
	Lb += d;
    } 
    {
	LL d = (Lb / Tb) * Tb;
	Lb -= d;
    }
    La = 0;

    LL ans = 0;
    LL g = gcd(Ta, Tb);
    LL pos = Lb - (Lb / g) * g;

    //eprintf("[%lld %lld]\n", pos, pos+Db-1);
    amax(ans, min(Da, pos + Db) - max(0LL, pos));
    pos -= g;
    //eprintf("[%lld %lld]\n", pos, pos+Db-1);
    amax(ans, min(Da, pos + Db) - max(0LL, pos));

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}