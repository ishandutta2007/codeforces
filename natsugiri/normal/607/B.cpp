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


int N;
int C[501];
int dp[503][503][2];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", C+i);

    memset(dp, 0x3f, sizeof dp);
    
    REP (i, N+1) {
	dp[i][i][0] = 0;
	dp[i][i][1] = 1;
	dp[i][i+1][0] = 1;
	dp[i][i+1][1] = 1;
    }
    
    for (int len=2; len<=N; len++) {
	for (int i=N-len+1; i--;) { // [i, i+len)
	    
	    if (C[i] == C[i+len-1]) {
		amin(dp[i][i+len][0], dp[i+1][i+len-1][1]);
		amin(dp[i][i+len][1], dp[i+1][i+len-1][0] + 1);
		amin(dp[i][i+len][1], dp[i+1][i+len-1][1]);
	    }
	    
	    for (int j=i+1; j<i+len; j++) {
		amin(dp[i][i+len][0], dp[i][j][0] + dp[j][i+len][0]);
		
		amin(dp[i][i+len][1], dp[i][j][1] + dp[j][i+len][0]);
		amin(dp[i][i+len][1], dp[i][j][0] + dp[j][i+len][1]);
	    }

	    amin(dp[i][i+len][0], dp[i][i+len][1]);
	    amin(dp[i][i+len][1], dp[i][i+len][0] + 1);
	}
    }

    int ans = min(dp[0][N][0], dp[0][N][1]);
    printf("%d\n", ans);
				    
    return 0;
}