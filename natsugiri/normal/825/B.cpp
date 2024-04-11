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

const int N = 10;
char F[21][21];

bool game() {
    REP (i, N) {
	int cnt = 0;
	REP (j, N) {
	    if (F[i][j] == 'X') cnt++;
	    else cnt = 0;
	    if (cnt == 5) return true;
	}
    }
    REP (j, N) {
	int cnt = 0;
	REP (i, N) {
	    if (F[i][j] == 'X') cnt++;
	    else cnt = 0;
	    if (cnt == 5) return true;
	}
    }
    REP (i, 6) REP (j, 6) {
	int cnt = 0;
	for (int k=0; k<5; k++) {
	    if (F[i+k][j+k] == 'X') cnt++;
	    else break;
	}
	if (cnt == 5) return true;

	cnt = 0;
	for (int k=0; k<5; k++) {
	    if (F[i+k][j+4-k] == 'X') cnt++;
	    else break;
	}
	if (cnt == 5) return true;
    }

    return false;
}

void MAIN() {
    REP (i, N) scanf("%s", F[i]);

    bool yes = false;
    REP (i, N) REP (j, N) if (F[i][j] == '.') {
	F[i][j] = 'X';
	if (game()) yes = true;
	F[i][j] = '.';
    }

    puts(yes? "YES": "NO");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}