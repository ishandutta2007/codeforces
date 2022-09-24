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

int N;
int A[100111];

int main() {
    scanf("%d", &N);
    REP ($, N) {
	LL L, R;
	scanf("%lld%lld", &L, &R);
	if (R == 0) puts("0");
	else {
	    LL ans = R;
	    int bits = __builtin_popcountll(R);
	    for (LL s=1; s<=R; s<<=1) {
		if (R & s) {
		    LL g = (R & ~s) | (s - 1);
		    if (L <= g && g <= R) {
			int b = __builtin_popcountll(g);
			if (bits < b || (bits == b && ans > g)) {
			    bits = b;
			    ans = g;
			}
		    }
		}
	    }
	    printf("%lld\n", ans);
	}
    }

    return 0;
}