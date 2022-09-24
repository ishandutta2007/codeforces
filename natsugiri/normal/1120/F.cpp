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

int N, C, D;
int T[100011];
char P[100011];

LL A[100011];
LL sums[100011];


void MAIN() {
    scanf("%d%d%d", &N, &C, &D);
    REP (i, N) scanf("%d%s", T+i, P+i);
    scanf("%d", T+N);

    LL cur = 0;

    for (int i=0; i<N; ) {
	int j = i;
	while (j < N && P[i] == P[j]) j++;

	LL tm = T[j];
	LL cst = 0;
	LL nxt = 1LL<<60;

	if (i) {
	    cst += (tm - T[i]) * C;
	    i++;
	}

	int len = j-i;
	REP (k, len) A[k] = T[i+k];
	REP (k, len) sums[k+1] = sums[k] + A[k];

	REP (k, len+1) {
	    LL tmp = (LL)D*k + ((len - k) * tm - (sums[len] - sums[k])) * C;
	    amin(nxt, cur + cst + tmp);

	    tmp = (LL)D*(i+k) + ((len - k) * tm - (sums[len] - sums[k])) * C;
	    amin(nxt, tmp);
	}


	cur = nxt;
	i = j;
    }

    LL ans = min((LL)N * D, cur);

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}