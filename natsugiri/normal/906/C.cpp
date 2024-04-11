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
int A[22];
int dp[1<<22];
int prv[1<<22];
int call[1<<22];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	A[x] |= 1<<y;
	A[y] |= 1<<x;
    }

    if (M*2 == N*(N-1)) {
	puts("0");
	puts("");
	return;
    }

    memset(dp, 0x3f, sizeof dp);
    const int INF = dp[0];
    REP (i, N) {
	dp[A[i] | (1<<i)] = 1;
	call[A[i] | (1<<i)] = i;
    }

    REP (s, 1<<N) if (dp[s] < INF) {
	REP (v, N) if (s>>v&1) {
	    int ns = s | A[v];
	    if (dp[ns] > dp[s] + 1) {
		dp[ns] = dp[s] + 1;
		prv[ns] = s;
		call[ns] = v;
	    }
	}
    }

    int s = (1<<N)-1;
    printf("%d\n", dp[s]);
    VI v;
    while (s) {
	v.push_back(call[s]+1);
	s = prv[s];
    }
    reverse(v.begin(), v.end());
    rprintf("%d", v.begin(), v.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}