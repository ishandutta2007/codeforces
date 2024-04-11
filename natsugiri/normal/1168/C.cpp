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

const int MAXN = 300011;
const int LOGN = 20;

int N, Q;
int A[MAXN];
int nxt[MAXN][LOGN];
int R[LOGN];

void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, N) scanf("%d", A+i);

    memset(nxt, 0x3f, sizeof nxt);
    memset(R, 0x3f, sizeof R);
    for (int i=N; i--;) {
	REP (t, LOGN) if (A[i]>>t&1) {
	    amin(nxt[i][t], i);
	    if (R[t] < N) {
		REP (u, LOGN) {
		    amin(nxt[i][u], nxt[R[t]][u]);
		}
	    }
	    R[t] = i;
	}
    }

    REP ($, Q) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	bool yes = false;
	REP (t, LOGN) if ((A[y]>>t&1) && nxt[x][t] <= y) {
	    yes = true;
	    break;
	}
	puts(yes? "Shi": "Fou");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}