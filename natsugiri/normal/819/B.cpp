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
const int SIZE = 1000111;
int A[1000111];
int cnt[SIZE * 4];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i), A[i]--;

//    N = 1000000;
//    REP (i, N) A[i] = i;
//    random_shuffle(A, A+N);
//    random_shuffle(A, A+N);

    REP (i, N) A[i] -= i;

    LL cur = 0;
    int p = 0, np = 0;
    REP (i, N) {
	if (A[i] > 0) {
	    p++;
	    cur += A[i];
	} else {
	    np++;
	    cur -= A[i];
	}

	cnt[SIZE + A[i]]++;
    }

    int sh = 0;
    LL ans = cur;

    for (int i=N, t=1; i--; t++) {
	cur += np - p;
//	eprintf("%d %d %lld\n", p, np, cur);

	p -= cnt[SIZE + t];
	np += cnt[SIZE + t];

	if (A[i]-t > 0) { p--; cur -= A[i]-t; }
	else { np--; cur += A[i]-t; }
	cnt[SIZE + A[i]]--;

	if (A[i]-t+N > 0) { p++; cur += A[i]-t+N; }
	else { np++; cur -= A[i]-t+N; }
	cnt[SIZE + A[i]+N]++;

	if (ans > cur) {
	    ans = cur;
	    sh = t;
	}
    }

    printf("%lld %d\n", ans, sh);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}