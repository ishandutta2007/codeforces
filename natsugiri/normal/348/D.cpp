#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
const LL MOD = 1000000007;

int N, M;
char F[3010][3010];
int dp[3010][3010];

int calc(int xs, int ys, int xt, int yt, bool check) {
    memset(dp, 0, sizeof dp);
    if (F[xs][ys] == '.') dp[xs][ys] = 1;
    for (int i=xs+1; i<=xt; i++) {
	if (F[i][ys] == '.') dp[i][ys] = dp[i-1][ys];
    }
    for (int j=ys+1; j<=yt; j++) {
	if (F[xs][j] == '.') dp[xs][j] = dp[xs][j-1];
    }
	
    for (int i=xs+1; i<=xt; i++) {
	for (int j=ys+1; j<=yt; j++) {
	    if (check) {
		if (F[i][j] == '.') dp[i][j] = dp[i-1][j] | dp[i][j-1];
	    } else {
		if (F[i][j] == '.') dp[i][j] = (LL(dp[i-1][j]) + dp[i][j-1]) % MOD;
	    }
	}
    }
    return dp[xt][yt];
}


int main() {
    scanf("%d%d", &N, &M);
    for (int i=0; i<N; i++) scanf("%s", F[i]);

    if (calc(0, 1, N-2, M-1, true) == 0 ||
	calc(1, 0, N-1, M-2, true) == 0) {
	puts("0");
	return 0;
    }
    LL A = calc(0, 1, N-2, M-1, false);
    LL B = calc(1, 0, N-1, M-2, false);
    LL C = calc(0, 1, N-1, M-2, false);
    LL D = calc(1, 0, N-2, M-1, false);

    cout << ((A*B - C*D) % MOD + MOD ) % MOD << endl;
	

    return 0;
}