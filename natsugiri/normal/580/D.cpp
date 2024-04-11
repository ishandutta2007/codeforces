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

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

int N, M, K;
int A[18], D[18][18];
LL MINF;
LL dp[1<<18][18];

int main() {
    scanf("%d%d%d", &N, &M, &K);
    REP (i, N) scanf("%d", A+i);
    REP (i, K) {
	int x, y, c;
	scanf("%d%d%d", &x, &y, &c);
	x--; y--;
	D[x][y] = c;
    }

    memset(&MINF, 0xc0, sizeof MINF);
    memset(dp, 0xc0, sizeof dp);
    
    REP (i, N) dp[1<<i][i] = A[i];
    REP (S, 1<<N) REP (i, N) if (dp[S][i] > MINF) {
	REP (j, N) if (i != j && ~S & (1<<j)) {
	    amax(dp[S|(1<<j)][j], dp[S][i] + A[j] + D[i][j]); 
	}
    }

    LL ans = MINF;
    REP (S, 1<<N) if (__builtin_popcount(S) == M)
	REP (i, N) amax(ans, dp[S][i]);

    printf("%lld\n", ans);
    return 0;
}