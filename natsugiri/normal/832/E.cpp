#include<cassert>
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

const int SIZE = 511;
int N, M, Q;
char S[SIZE];
int A[SIZE][SIZE];
int R[SIZE][SIZE];
int Y[SIZE];

const int mul5[5][5] = {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 2, 3, 4 },
    { 0, 2, 4, 1, 3 },
    { 0, 3, 1, 4, 2 },
    { 0, 4, 3, 2, 1 },
};
const int div5[5][5] = {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 3, 2, 4 },
    { 0, 2, 1, 4, 3 }, 
    { 0, 3, 4, 1, 2 }, 
    { 0, 4, 2, 3, 1 }, 
};

int r, c;
void ge(int n, int m) {
    REP (i, n) R[i][i] = 1;
    for (r=c=0; r<n && c<m;) {
	int p = -1;
	for (int i=r; i<n; i++) if (A[i][c]) { p = i; break; }
	if (p == -1) { c++; continue; }
	if (r < p) {
	    for (int j=c; j<m; j++) swap(A[r][j], A[p][j]);
	    for (int j=0; j<n; j++) swap(R[r][j], R[p][j]);
	}
	if (A[r][c] > 1) {
	    int t = A[r][c];
	    for (int j=c; j<m; j++) A[r][j] = div5[A[r][j]][t];
	    for (int j=0; j<n; j++) R[r][j] = div5[R[r][j]][t];
	}
	for (int i=0; i<n; i++) if (i != r && A[i][c]) {
	    int t = A[i][c];
	    for (int j=c; j<m; j++) 
		if ((A[i][j] += 5 - mul5[A[r][j]][t]) >= 5) A[i][j] -= 5;
	    for (int j=0; j<n; j++) 
		if ((R[i][j] += 5 - mul5[R[r][j]][t]) >= 5) R[i][j] -= 5;
	}
	r++;
    }
}

void MAIN() {
    REP (a, 5) REP (b, 5) assert(mul5[a][b] == a * b % 5);
    REP (a, 5) for (int b=1; b<4; b++) assert(mul5[div5[a][b]][b] == a);

    scanf("%d%d", &N, &M);
    REP (i, N) {
	scanf("%s", S);
	REP (j, M) A[j][i] = S[j] - 'a';
    }

    ge(M, N);
    LL ans = 1;
    REP (i, N-r) ans = ans * 5 % 1000000007;;

    scanf("%d", &Q);
    REP ($, Q) {
	scanf("%s", S);
	REP (i, M) Y[i] = 0;
	REP (i, M) REP (j, M) if ((Y[i] += mul5[R[i][j]][S[j] - 'a']) >= 5) Y[i] -= 5;

	bool yes = true;
	for (int i=r; i<M; i++) if (Y[i]) yes = false;

	if (yes) printf("%d\n", (int)ans);
	else puts("0");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}