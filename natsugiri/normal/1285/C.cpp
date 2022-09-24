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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

LL X;


LL ansA, ansB;
vector<LL> H;
void rec(int I, LL a, LL b) {
    if (I == (int)H.size()) {
	if (max(ansA, ansB) > max(a, b)) {
	    ansA = a;
	    ansB = b;
	}
    } else {
	rec(I+1, a * H[I], b);
	if (I) rec(I+1, a, b * H[I]);
    }
}

void MAIN() {
    scanf("%lld", &X);

    LL m = X;
    for (LL i=2; i*i<=m; i++) {
	LL k = 1;
	while (m % i == 0) {
	    m /= i;
	    k *= i;
	}
	if (k > 1) H.push_back(k);
    }
    if (m > 1) H.push_back(m);

    ansA = ansB = X;
    rec(0, 1, 1);
    printf("%lld %lld\n", ansA, ansB);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}