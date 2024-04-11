#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
const LL MOD = 1000000007    ;

int N, K, A[2048];
LL dp[2][(1<<10)+10];

int main() {
    scanf("%d%d", &N, &K);
    K--;
    for (int i=0; i<N; i++) {
	scanf("%d", A+i);
	A[i] /= 2;
    }

    dp[0][0] = 1;
    LL ans = 0;
    for (int i=0, t=0; i<N; i++, t=1-t) {
	for (int j=0; j<=(1<<K); j++) dp[1-t][j] = 0;

	if (A[i] == 0) ans = 2*ans % MOD;
	if (A[i] == 0 || A[i] == 1) {
	    for (int j=0; j<(1<<K); j++) {
		dp[1-t][j+1] += dp[t][j];
		if (dp[1-t][j+1] >= MOD) dp[1-t][j+1] -= MOD;
	    }
	}
	if (A[i] == 0 || A[i] == 2) {
	    for (int j=0; j<(1<<K); j+=2) {
		dp[1-t][j+2] += dp[t][j];
		if (dp[1-t][j+2] >= MOD) dp[1-t][j+2] -= MOD;
	    }
	    for (int j=1; j<(1<<K); j+=2) {
		dp[1-t][2] += dp[t][j];
		if (dp[1-t][2] >= MOD) dp[1-t][2] -= MOD;
	    }
	}

	ans = (ans + dp[1-t][1<<K]) % MOD;
	// for (int j=0; j<=(1<<K); j++) printf("(%d %lld) ", j, dp[1-t][j]);
	// puts("");
    }

    cout << ans << endl;
    
    return 0;
}