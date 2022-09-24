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

int N, M;
LL sq(LL x) { return x * x ; }

int main() {
    scanf("%d%d", &N, &M);

    if (N == 0) {
	printf(
		"0 1\n"
		"0 %d\n"
		"0 0\n"
		"0 %d\n"
	      , M, M-1);
    } else if (M == 0) {
	printf(
		"1 0\n"
		"%d 0\n"
		"0 0\n"
		"%d 0\n"
	      , N, N-1);
    } else {
	LL best = 0;
	int p[8] = { 0, 0, N, M, };

	for (int i=1; i<=N; i++) for (int j=0; j<N; j++) {
	    LL tmp = sq(N) + sq(N - i) + sq(i - j) + 3 * sq(M);
	    if (tmp > best) {
		best = tmp;
		p[0] = 0; p[1] = 0;
		p[2] = N; p[3] = M;
		p[4] = i; p[5] = 0;
		p[6] = j; p[7] = M;
	    }

	    tmp = sq(N - i) + sq(N) + sq(j) + 3 * sq(M);
	    if (tmp > best) {
		best = tmp;
		p[0] = i; p[1] = 0;
		p[2] = N; p[3] = M;
		p[4] = 0; p[5] = 0;
		p[6] = j; p[7] = M;
	    }
	}

	for (int i=1; i<=M; i++) for (int j=0; j<M; j++) {
	    LL tmp = sq(M) + sq(M - i) + sq(i - j) + 3 * sq(N);
	    if (tmp > best) {
		best = tmp;
		p[0] = 0; p[1] = 0;
		p[2] = N; p[3] = M;
		p[4] = 0; p[5] = i;
		p[6] = N; p[7] = j;
	    }

	    tmp = sq(M - i) + sq(M) + sq(j) + 3 * sq(N);
	    if (tmp > best) {
		best = tmp;
		p[0] = 0; p[1] = i;
		p[2] = N; p[3] = M;
		p[4] = 0; p[5] = 0;
		p[6] = N; p[7] = j;
	    }
	}

	REP (i, 4) printf("%d %d\n", p[i+i], p[i+i+1]);
    }


    return 0;
}