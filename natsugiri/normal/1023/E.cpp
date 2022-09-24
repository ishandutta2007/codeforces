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

int N;
char ans[2011];

bool query(int r1, int c1, int r2, int c2) {
    assert((r2 - r1) + (c2 - c1) >= N-1);
    char buf[11];
    printf("? %d %d %d %d\n", r1, c1, r2, c2);
    fflush(stdout);
    scanf("%s", buf);
    return buf[0] == 'Y';
}
void answer() {
    printf("! %s\n", ans);
    exit(0);
}

void MAIN() {
    scanf("%d", &N);

    int pos = 0;
    int curR = 1, curC = 1;
    while (curR + curC < N+1) {
	bool ok = query(curR+1, curC, N, N);
	if (ok) {
	    ans[pos++] = 'D';
	    curR++;
	} else {
	    ans[pos++] = 'R';
	    curC++;
	}
    }

    pos = 2*N-2;
    curR = N; curC = N;
    while (curR + curC > N+1) {
	bool ok = query(1, 1, curR, curC-1);
	if (ok) {
	    ans[--pos] = 'R';
	    curC--;
	} else {
	    ans[--pos] = 'D';
	    curR--;
	}
    }

    answer();
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}