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

LL X, Y, L, R;

LL safe_mul(LL x, LL y) {
    if (double(x) * double(y) >= 1.1e18) return R + 1;
    return x * y;
}

void MAIN() {
    scanf("%lld%lld%lld%lld", &X, &Y, &L, &R);

    vector<LL> v;
    for (LL x=1; x<=R; x=safe_mul(x, X)) {
	for (LL y=1; x+y<=R; y=safe_mul(y, Y)) {
	    if (L <= x + y)
		v.push_back(x+y);
	}
    }
    v.push_back(L-1);
    v.push_back(R+1);
    sort(v.begin(), v.end());
    LL ans = 0;
    REP (i, v.size()-1) {
	amax(ans, v[i+1] - v[i] - 1);
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}