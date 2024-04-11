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
LL X, Y;
int A[500111];

const int MAX = 2000111;
LL C[MAX];
LL sumC[MAX+11];
LL sumD[MAX+11];

void MAIN() {
    scanf("%d%lld%lld", &N, &X, &Y);
    REP (i, N) {
	int x;
	scanf("%d", &x);
	C[x]++;
    }

    REP (i, MAX) {
	sumC[i+1] = sumC[i] + C[i];
	sumD[i+1] = sumD[i] - C[i] * i;
    }

    LL ans = min(N * X, N * Y);

    for (LL z=2; z<MAX; z++) {
	LL lo = 0, hi = z;
	while (hi - lo > 1) {
	    LL mid = (lo + hi) / 2;
	    if ((z - mid) * Y < X) hi = mid;
	    else lo = mid;
	}

	LL p = hi;

	LL tmp = 0;
	for (int i=0; i+z<MAX; i+=z) {
	    tmp += (sumC[i+p] - sumC[i+1]) * X;
	    LL mv = (sumD[i+z] - sumD[i+p]) + (sumC[i+z] - sumC[i+p]) * (i+z);
	    if (mv > ans / Y + 1 + Y) {
		tmp = ans;
		break;
	    }
	    tmp += mv * Y;
	    if (tmp >= ans) break;
	}

	amin(ans, tmp);
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}