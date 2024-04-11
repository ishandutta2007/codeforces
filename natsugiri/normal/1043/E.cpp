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
int X[300111], Y[300111];
pair<int, int> P[300111];
LL ans[300111];

void MAIN() {
    scanf("%d%d", &N, &M);

    REP (i, N) scanf("%d%d", X+i, Y+i);

    REP (i, N) P[i] = make_pair(X[i] - Y[i], i);
    sort(P, P+N);

    LL sumX = 0, sumY = 0;
    REP (i, N) sumY += Y[i];
    REP (i, N) {
	int id = P[i].second;
	sumY -= Y[id];
	ans[id] = (LL)i*Y[id] + (LL)(N-i-1)*X[id] + sumX + sumY;
	sumX += X[id];
    }

    REP (i, M) {
	int a, b;
	scanf("%d%d", &a, &b);
	a--; b--;
	LL c = min(X[a] + Y[b], X[b] + Y[a]);
	ans[a] -= c;
	ans[b] -= c;
    }

    rprintf("%lld", ans, ans+N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}