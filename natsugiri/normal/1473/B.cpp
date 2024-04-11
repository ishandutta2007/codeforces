#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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

LL gcd(LL x_, LL y_) {
    typedef unsigned long long ULL;
    ULL x = abs(x_);
    ULL y = abs(y_);
    while (1) {
	if (x) y %= x; else return y;
	if (y) x %= y; else return x;
    }
}
LL lcm(LL x, LL y) {
    assert(x >= 1);
    assert(y >= 1);
    return x/gcd(x, y)*y;
}

string S, T;
char buf[411];

void MAIN() {
    scanf("%s", buf);
    S = buf;
    scanf("%s", buf);
    T = buf;
    int len = lcm(S.size(), T.size());


    bool yes = true;
    REP (i, len) if (S[i % S.size()] != T[i % T.size()]) yes = false;

    if (yes) {
	REP (i, len) putchar(S[i % S.size()]);
	putchar('\n');
    } else {
	puts("-1");
    }
}


int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}