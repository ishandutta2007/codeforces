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


int N, K;
LL M;
inline void add(LL &a, LL b) {
    a += b;
    if (a>=M) a-=M;
}

LL dp[1111][111];

int main() {
    scanf("%d%d%lld", &N, &K, &M);

    dp[1][0]++;
    for (int d=1; d<=9; d++) {
	if (d % K == 0) dp[1][K]++;
	else dp[1][d%K]++;
    }

    LL ten = 10 % K;
    for (int i=1; i<N; i++, ten = ten*10%K) {
	REP (j, K) {
	    REP (d, 10) {
		int nK = (d*ten+j) % K;
		if (nK == 0 && d) { // find y
		    add(dp[i+1][K], dp[i][j]);
		} else {
		    add(dp[i+1][nK], dp[i][j]);
		}
	    }
	}
	add(dp[i+1][K+1], dp[i][K]); // cat 0
	add(dp[i+1][K+1], dp[i][K+1]); // cat 0
	add(dp[i+1][K], 9*dp[i][K]%M); // cat non-0
	add(dp[i+1][K], 9*dp[i][K+1]%M); // cat non-0
    }

    printf("%lld\n", (dp[N][K]%M+M)%M);
    return 0;
}