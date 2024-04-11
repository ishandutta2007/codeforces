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
char F[1011][1011];
bool D[4][1011][1011];
bool buf[1011][1011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%s", F[i]);

    REP (i, N) REP (j, M) if (F[i][j] == 'S') D[0][i][j] = true;
    REP (t, 3) {
	// right
	memset(buf, 0, sizeof buf);
	REP (i, N) REP (j, M) if (D[t][i][j] && !buf[i][j]) {
	    for (int k=j; k<M; k++) {
		if (F[i][k] == '*') break;
		buf[i][k] = true;
	    }
	}
	REP (i, N) REP (j, M) D[t+1][i][j] |= buf[i][j];

	// left 
	memset(buf, 0, sizeof buf);
	REP (i, N) for (int j=M; j--;) if (D[t][i][j] && !buf[i][j]) {
	    for (int k=j; k>=0; k--) {
		if (F[i][k] == '*') break;
		buf[i][k] = true;
	    }
	}

	REP (i, N) REP (j, M) D[t+1][i][j] |= buf[i][j];

	// down 
	memset(buf, 0, sizeof buf);
	REP (i, N) REP (j, M) if (D[t][i][j] && !buf[i][j]) {
	    for (int k=i; k<N; k++) {
		if (F[k][j] == '*') break;
		buf[k][j] = true;
	    }
	}
	REP (i, N) REP (j, M) D[t+1][i][j] |= buf[i][j];

	// up
	memset(buf, 0, sizeof buf);
	for (int i=N; i--;) REP (j, M) if (D[t][i][j] && !buf[i][j]) {
	    for (int k=i; k>=0; k--) {
		if (F[k][j] == '*') break;
		buf[k][j] = true;
	    }
	}
	REP (i, N) REP (j, M) D[t+1][i][j] |= buf[i][j];
    }

    bool yes = false;
    REP (i, N) REP (j, M) if (F[i][j] == 'T') {
	if (D[3][i][j]) yes = true;
    }
    puts(yes? "YES": "NO");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}