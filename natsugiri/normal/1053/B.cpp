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
int B[300111];

int C[64];
int D0, D1;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	LL x;
	scanf("%lld", &x);
	B[i] = __builtin_popcountll(x);
    }

    LL ans = 0;

    REP (i, N) {
	if (B[i] % 2) {
	    ans += D1;
	    swap(D0, D1);
	} else {
	    ans += D0;
	}

	for (int b=63; b>=0; b--) {
	    if (C[b] > 0) {
		int t = max(C[b], B[i]);
		int s = b + C[b] + B[i];
		if (s % 2 == 0 && t*2 <= s) {
		    ans++;
		}

		if (s-t >= 64) {
		    if (s % 2) D1++;
		    else D0++;
		} else {
		    C[s-t] = t;
		}
		C[b] = -1;
	    }
	}
	C[0] = B[i];
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}