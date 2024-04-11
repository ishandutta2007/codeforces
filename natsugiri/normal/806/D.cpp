#include<queue>
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

const LL INF = 1LL<<60;
int N;
LL A[2011][2011];
//LL Z[2011][2011];
bool C[2011];

LL len[2011];
LL small[2011];

void test() {
    N = 2000;
    REP (i, N) REP (j, N) {
	A[i][j] = A[j][i] = rand() % 1000000000;
    }
    REP (i, N) A[i][i] = INF;
}

void MAIN() {
    scanf("%d", &N);

    REP (i, N) {
	REP (j, N-i-1) {
	    int x;
	    scanf("%d", &x);
	    A[i][i+j+1] = A[i+j+1][i] = x;
	}
	A[i][i] = INF;
    }

//    test();

    LL mi = INF;
    REP (i, N) REP (j, N) amin(mi, A[i][j]);

//    REP (i, N) rprintf("%d", A[i], A[i] + N);

    REP (i, N) REP (j, N) if (A[i][j] == mi) {
	C[i] = true;
	C[j] = true;
    }

    const LL BASE = (LL)(N-1) * mi;

    REP (i, N) small[i] = INF;
    REP (i, N) REP (j, N) amin(small[i], A[i][j]);


    priority_queue<pair<LL, int> > Q;
    REP (i, N) len[i] = INF;
    REP (i, N) if (C[i]) {
	Q.emplace(0, i);
	len[i] = 0;
    }

    while (!Q.empty()) {
	pair<LL, int> p = Q.top(); Q.pop();
	LL cost = -p.first;
	int v = p.second;

	if (cost > len[v]) continue;

	REP (i, N) if (i != v) {
	    LL tmp = cost + A[i][v] - mi;
	    amin(tmp, cost + (small[i] - mi) * 2);
	    if (tmp < len[i]) {
		len[i] = tmp;
		Q.emplace(-tmp, i);
	    }
	}
    }

    REP (i, N) printf("%lld\n", len[i] + BASE);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}