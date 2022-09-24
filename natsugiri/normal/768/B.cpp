#include<stack>
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

LL len(LL x) {
    if (x == 0) return 1;
    if (x == 1) return 1;
    int g = __lg(x);
    return (2LL<<g) - 1;
}

LL calc(LL x) {
    LL ret = 0;
    LL s = 1;
    while (x) {
	ret += s * (x & 1);
	x >>= 1;
	s <<= 1;
    }
    return ret;
}

LL N, L, R;
LL F(LL K) {
    stack<LL> S;
    S.push(N);
    LL ret = 0;

    while (K) {
	LL x = S.top(); S.pop();
	LL t = len(x);
	if (t <= K) {
	    K -= t;
	    ret += calc(x);
	} else {
	    S.push(x/2);
	    S.push(x&1);
	    S.push(x/2);
	}
    }

    return ret;
}

int main() {
    scanf("%lld%lld%lld", &N, &L, &R);
    printf("%lld\n", F(R) - F(L-1));

    return 0;
}