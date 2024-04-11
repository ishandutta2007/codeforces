#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
const LL MOD = 1000000007 ;


int N, K;
LL dp[2010][2010];

vector<int>D[2010];


int main() {
    scanf("%d%d", &N, &K);
    dp[0][1] = 1;
    for (int i=1; i<=2000; i++) 
	for (int j=i; j<=2000; j+=i) D[i].push_back(j);
    
    for (int i=0; i<K; i++) {
	for (int j=1; j<=N; j++) {

	    if (dp[i][j] == 0) continue;
	    
	    for (int k=0; k<(int)D[j].size() && D[j][k] <= N; k++) {
		dp[i+1][D[j][k]] += dp[i][j];
		if (dp[i+1][D[j][k]] >= MOD) dp[i+1][D[j][k]] -= MOD;
	    }
	}
    }

    LL ans = 0;
    for (int i=1; i<=N; i++) ans = (ans + dp[K][i]) % MOD;
    ans = (ans + MOD) % MOD;
    cout << ans << endl;
    return 0;
}