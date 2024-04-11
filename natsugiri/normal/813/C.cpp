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

int N, X;
VI G[200111];

void bfs(int s, int *len) {
    memset(len, 0x3f, sizeof (int) * N);
    VI ord;
    ord.reserve(N);
    ord.push_back(s);
    len[s] = 0;
    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) {
	    if (len[*e] > len[v] + 1) {
		len[*e] = len[v] + 1;
		ord.push_back(*e);
	    }
	}
    }
}

int len0[200111];
int lenX[200111];

void MAIN() {
    scanf("%d%d", &N, &X);
    X--;
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    bfs(0, len0);
    bfs(X, lenX);

    int ans = 0;
    REP (i, N) {
	if (lenX[i] < len0[i]) {
	    amax(ans, 2 * len0[i]);
	}
    }

    printf("%d\n", ans);
}


int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}