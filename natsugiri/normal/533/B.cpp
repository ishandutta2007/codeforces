#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

const LL INF = 1LL<<60;

int N, A[200011], P[200011];
LL dp[200011][2];
int main() {
    scanf("%d", &N);
    REP (i, N) {
	scanf("%d%d", P+i, A+i);
	P[i]--;
    }

    REP (i, N) dp[i][1] = -INF;
    for (int i=N; --i;) {
	int p = P[i];
	amax(dp[i][1], dp[i][0] + A[i]);
	LL nx[2] = {};
	
	REP (x, 2) REP (y, 2)
	    amax(nx[(x+y)&1], dp[p][x] + dp[i][y]);

	REP (x, 2) amax(dp[p][x], nx[x]);
	// eprintf("%d %lld %lld\n", i+1, dp[i][0], dp[i][1]);
    }

    LL ans = max(dp[0][0] + A[0], dp[0][1]);
    printf("%lld\n", ans);
    return 0;
}