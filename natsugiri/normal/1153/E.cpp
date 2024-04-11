#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
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
int N;

int cnt;

int query(int y, int x, int y1, int x1) {
    cnt++;
    printf("? %d %d %d %d\n", x+1, y+1, x1, y1);
    fflush(stdout);
    int r;
    scanf("%d", &r);
    return r&1;
}

void answer(int y1, int x1, int y2, int x2) {
    printf("! %d %d %d %d\n", x1+1, y1+1, x2+1, y2+1);
}

int Xs[1011], Ys[1011];

void MAIN() {
    scanf("%d", &N);

    for (int x=1; x<N; x++) {
	Xs[x] = query(0, 0, N, x)&1;
    }
    for (int y=1; y<N; y++) {
	Ys[y] = query(0, 0, y, N)&1;
    }

    if (count(Xs, Xs+N, 0) == N) {
	assert(count(Ys, Ys+N, 1));
	int y1 = 0, y2 = 0;
	REP (i, N) {
	    if (Ys[i] == 0 && Ys[i+1] == 1) y1 = i;
	    if (Ys[i] == 1 && Ys[i+1] == 0) y2 = i;
	}
	// (x, y1), (x, y2);
	int lo = 0, hi = N;
	while (hi - lo > 1) {
	    int mid = (lo + hi) / 2;
	    int r = query(0, 0, y1+1, mid);
	    if (r & 1) hi = mid;
	    else lo = mid;
	}
	answer(y1, lo, y2, lo);
    } else if (count(Ys, Ys+N, 0) == N) {
	assert(count(Xs, Xs+N, 1));
	int x1 = 0, x2 = 0;
	REP (i, N) {
	    if (Xs[i] == 0 && Xs[i+1] == 1) x1 = i;
	    if (Xs[i] == 1 && Xs[i+1] == 0) x2 = i;
	}
	int lo = 0, hi = N;
	while (hi - lo > 1) {
	    int mid = (lo + hi) / 2;
	    int r = query(0, 0, mid, x1+1);
	    if (r & 1) hi = mid;
	    else lo = mid;
	}
	answer(lo, x1, lo, x2);
    } else {
	int y1, x1, y2, x2;
	REP (i, N) {
	    if (Ys[i] == 0 && Ys[i+1] == 1) y1 = i;
	    if (Ys[i] == 1 && Ys[i+1] == 0) y2 = i;
	    if (Xs[i] == 0 && Xs[i+1] == 1) x1 = i;
	    if (Xs[i] == 1 && Xs[i+1] == 0) x2 = i;
	}

	if (query(0, 0, y1+1, x1+1) & 1) {
	    answer(y1, x1, y2, x2);
	} else {
	    answer(y1, x2, y2, x1);
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}