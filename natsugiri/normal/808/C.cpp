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

int N, W;
int A[111];
pair<int, int> P[111];
int ans[111];

void MAIN() {
    scanf("%d%d", &N, &W);
    REP (i, N) scanf("%d", A+i);

    REP (i, N) P[i] = make_pair(A[i], i);
    sort(P, P+N);
    REP (i, N) {
	int g = (A[i] + 1) / 2;
	ans[i] = g;
	W -= g;
    }

    int cur = N-1;
    while (W > 0) {
	while (0 <= cur && P[cur].first <= ans[P[cur].second]) cur--;
	if (cur < 0) break;
	int g = min(W, P[cur].first - ans[P[cur].second]);
	ans[P[cur].second] += g;
	W -= g;
    }

    if (W != 0) puts("-1");
    else rprintf("%d", ans, ans + N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}