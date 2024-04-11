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

LL N, M, K, X, Y;

LL ask(LL x, LL y) {
    if (N == 1) {
	return K / M + LL(K % M > y);
    }

    LL ret = 0;
    LL C = N * 2 - 2;
    if (0 <= x && x < N-1) ret += K / (C * M) + LL(K % (C * M) > x * M + y);
    if (1 <= x && x < N) ret += K / (C * M) + LL(K % (C * M) > (C - x) * M + y);
    return ret;
}

int main() {
    scanf("%lld%lld%lld%lld%lld", &N, &M, &K, &X, &Y);
    X--; Y--;

    LL ma = ask(0, 0);
    if (N > 1) {
	amax(ma, ask(1, 0));
	amax(ma, ask(N-2, 0));
    }

    LL mi = ask(N-1, M-1);
    amin(mi, ask(0, M-1));

    LL sergei = ask(X, Y);

    printf("%lld %lld %lld\n", ma, mi, sergei);


    return 0;
}