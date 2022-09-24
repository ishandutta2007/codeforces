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

LL AD[64];
void Shift(LL X, LL K) {
    int dep = 0;
    REP (i, 62) if (X >> i & 1) dep = i;
    AD[dep] += K;
    AD[dep] &= (1LL<<dep) - 1;
}

void Output(LL X) {
    int dep = 0;
    REP (i, 62) if (X >> i & 1) dep = i;

    LL base = 1LL<<dep;
    vector<LL> ans;
    while (1) {
	ans.push_back(X);
	if (X == 1) break;

	X -= base;
	X = (X + AD[dep]) & (base-1);
	X += base;
	dep--;
	X >>= 1;
	base >>= 1;
    }

    rprintf("%lld", ans.begin(), ans.end());
}

void MAIN() {
    int Q;
    scanf("%d", &Q);
    REP ($, Q) {
	int T;
	LL X, K;
	scanf("%d", &T);
	if (T == 1) {
	    scanf("%lld%lld", &X, &K);
	    if (K != 0 && X != 1) {
		Shift(X, K);
		Shift(X*2, -K*2);
	    }
	} else if (T == 2) {
	    scanf("%lld%lld", &X, &K);
	    if (K != 0 && X != 1) {
		Shift(X, K);
	    }
	} else if (T == 3) {
	    scanf("%lld", &X);
	    Output(X);
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}