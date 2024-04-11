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
char T[1011][1011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%s", F[i]);
    memset(T, '.', sizeof T);

    REP (i, N-2) REP (j, M-2) {
	int cnt = 0;
	REP (y, 3) REP (x, 3) {
	    if (y == 1 && x == 1) continue;
	    if (F[i+y][j+x] == '#') cnt++;
	}
	if (cnt == 8) {
	    REP (y, 3) REP (x, 3) {
		if (y == 1 && x == 1) continue;
		T[i+y][j+x] = '#';
	    }
	}
    }

    bool yes = true;
    REP (i, N) REP (j, M) {
	if (F[i][j] != T[i][j]) yes = false;
    }
    puts(yes? "YES": "NO");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}