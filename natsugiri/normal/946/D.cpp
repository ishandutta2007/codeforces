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

int N, M, K;
char F[511][511];

int dp[511][511];

void MAIN() {
    scanf("%d%d%d", &N, &M, &K);
    REP (i, N) scanf("%s", F[i]);

    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;

    VI v;
    REP (i, N) {
	v.clear();
	REP (j, M) if (F[i][j] == '1') v.push_back(j);

	int cost;
	// 0; 
	cost = v.size();
	REP (c, K+1-cost) amin(dp[i+1][c+cost], dp[i][c]);

	// 1; 
	if (!v.empty()) {
	    cost = (int)v.size() - 1;
	    REP (c, K+1-cost) amin(dp[i+1][c+cost], dp[i][c]+1);
	}

	for (int len=2; len<=(int)v.size(); len++) {
	    cost = (int)v.size() - len;

	    int tm = v[len-1]-v[0]+1;
	    for (int w=1; w+len-1 < (int)v.size(); w++)
		amin(tm, v[w+len-1]-v[w]+1);

	    REP (c, K+1-cost) amin(dp[i+1][c+cost], dp[i][c]+tm);
	}
    }

    int ans = dp[N][0];
    REP (c, K+1) amin(ans, dp[N][c]);
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}