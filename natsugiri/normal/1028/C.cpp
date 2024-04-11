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
struct Rect {
    int x1, x2;
    int y1, y2;
    void get() {
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    }

    bool has() const {
	return x1 <= x2 && y1 <= y2;
    }
} A[150111], L[150111], R[150111];

Rect intersect(const Rect &a, const Rect &b) {
    Rect c;
    c.x1 = max(a.x1, b.x1);
    c.y1 = max(a.y1, b.y1);
    c.x2 = min(a.x2, b.x2);
    c.y2 = min(a.y2, b.y2);
    return c;
}

const int INF = 1<<30;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) A[i].get();

    L[0] = A[0];
    for (int i=1; i<N; i++) {
	L[i] = intersect(A[i], L[i-1]);
    }
    R[N-1] = A[N-1];
    for (int i=N-2; i>=0; i--) {
	R[i] = intersect(A[i], R[i+1]);
    }

    REP (i, N) {
	Rect t;
	if (i == 0) t = R[i+1];
	else if (i == N-1) t = L[i-1];
	else t = intersect(L[i-1], R[i+1]);
	if (t.has()) {
//	    eprintf("%d: %d %d %d %d\n", i, t.x1, t.y1, t.x2, t.y2);
	    printf("%d %d\n", t.x1, t.y1);
	    return;
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}