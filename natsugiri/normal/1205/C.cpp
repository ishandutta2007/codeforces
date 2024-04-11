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

int N;
int A[55][55];

int query(int y0, int x0, int y1, int x1) {
    printf("? %d %d %d %d\n", y0+1, x0+1, y1+1, x1+1);
    fflush(stdout);
    scanf("%d", &x0);
    return x0;
}

void sub(int y0, int x0, int y1, int x1) {
    if (0 <= y0 && y1 < N && 0 <= x0 && x1 < N) {
	if (A[y0][x0] != -1 && A[y1][x1] == -1) {
	    int t = query(y0, x0, y1, x1);
	    A[y1][x1] = A[y0][x0] ^ !t;
	}
	if (A[y0][x0] == -1 && A[y1][x1] != -1) {
	    int t = query(y0, x0, y1, x1);
	    A[y0][x0] = A[y1][x1] ^ !t;
	}
    }
}

void MAIN() {
    scanf("%d", &N);
    memset(A, -1, sizeof A);
    A[0][0] = 1;
    A[N-1][N-1] = 0;
    REP (i, N) REP (j, N) {
	sub(i, j, i+2, j);
	sub(i, j, i, j+2);
	sub(i, j, i+1, j+1);
    }

    VI Y, X;
    for (int i=0; i<N; i+=2) {
	Y.push_back(i);
	X.push_back(0);
    }
    for (int j=2; j<N; j+=2) {
	Y.push_back(N-1);
	X.push_back(j);
    }
    for (int k=1; k<(int)X.size()-1; k++) {
	int y0 = Y[k-1];
	int x0 = X[k-1];
	int y2 = Y[k];
	int x2 = X[k];
	int y4 = Y[k+1];
	int x4 = X[k+1];

	int y1 = (y0+y2)/2, x1 = (x0+x2)/2;
	int y3 = (y2+y4)/2, x3 = (x2+x4)/2;
	if (A[y0][x0] != A[y4][x4]) {
	    int t = query(y1, x1, y3, x3);
	    if (A[y0][x0] == A[y2][x2]) {
		if (t == 1) {
		    int u = query(y0, x0, y3, x3);
		    A[y1][x1] = A[y3][x3] = A[y2][x2] ^ !u;
		} else {
		    int u = query(y1, x1, y4, x4);
		    A[y1][x1] = A[y4][x4] ^ !u;
		    A[y3][x3] = A[y2][x2] ^ !u;
		}
	    } else {
		if (t == 1) {
		    int u = query(y1, x1, y4, x4);
		    A[y1][x1] = A[y3][x3] = A[y2][x2] ^ !u;
		} else {
		    int u = query(y0, x0, y3, x3);
		    A[y1][x1] = A[y2][x2] ^ !u;
		    A[y3][x3] = A[y0][x0] ^ !u;
		}
	    }

	    break;
	}
    }

    REP (i, N) REP (j, N) {
	sub(i, j, i+2, j);
	sub(i, j, i, j+2);
	sub(i, j, i+1, j+1);
    }
    for (int i=N; i--;) for (int j=N; j--;) {
	sub(i, j, i+2, j);
	sub(i, j, i, j+2);
	sub(i, j, i+1, j+1);
    }

    puts("!");
    REP (i, N) {
	REP (j, N) printf("%c", A[i][j]+'0');
	puts("");
    }
    fflush(stdout);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}