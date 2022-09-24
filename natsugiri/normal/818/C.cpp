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
/*
   ..........
   ..........
   ..........
   ..........
   ..........
   ....22....
   ....33....
   ..........
   1.........
   1.........
   */

int N;
int X0[100111], Y0[100111];
int X1[100111], Y1[100111];
int lX[100111], tY[100111];
int rX[100111], bY[100111];
int L, R, T, B;

void MAIN() {
    scanf("%d%*d%*d", &N);
    REP (i, N) scanf("%d%d%d%d", X0+i, Y0+i, X1+i, Y1+i);

    scanf("%d%d%d%d", &L, &R, &T, &B);

    REP (i, N) {
	if (X0[i] > X1[i]) swap(X0[i], X1[i]);
	if (Y0[i] > Y1[i]) swap(Y0[i], Y1[i]);

	lX[i] = X0[i];
	rX[i] = X1[i];
	tY[i] = Y0[i];
	bY[i] = Y1[i];
    }

    sort(lX, lX+N);
    sort(rX, rX+N);
    sort(tY, tY+N);
    sort(bY, bY+N);

    REP (i, N) {
	int l = lower_bound(lX, lX+N, X1[i]) - lX;
	int r = rX+N - upper_bound(rX, rX+N, X0[i]);
	int t = lower_bound(tY, tY+N, Y1[i]) - tY;
	int b = bY+N - upper_bound(bY, bY+N, Y0[i]);
	if (X0[i] < X1[i]) l--, r--;
	if (Y0[i] < Y1[i]) t--, b--;

	if (L == l && R == r && T == t && B == b) {
	    printf("%d\n", i+1);
	    return;
	}
    }
    puts("-1");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}