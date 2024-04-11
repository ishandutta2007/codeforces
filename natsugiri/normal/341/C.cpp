#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

const LL MOD = 1000000007;
LL dp[2010][2010]; 

int N, A[2010];
bool use[2010], num[2010];

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
	scanf("%d", A+i);
	if (A[i] != -1) A[i]--;
    }
    
    dp[0][0]=1;
    for (int i=1; i<=N; i++) {
	dp[0][i] = dp[0][i-1] * i % MOD;
	dp[1][i] = i*dp[0][i]%MOD;
    }
    
    for (int a=2; a<=N; a++) {
	dp[a][0] = (a-1)*dp[a-2][1]%MOD;
	
	for (int b=1; b<=N; b++) {
	    dp[a][b] = (a-1)*dp[a-2][b+1];
	    dp[a][b] += b*dp[a-1][b];
	    dp[a][b] %= MOD;
	}
    }

    int same = 0, diff = 0;
    for (int i=0; i<N; i++) {
	if (A[i] != -1) {
	    use[i] = true;
	    num[A[i]] = true;
	}
    }
    for (int i=0; i<N; i++) {
	if (!num[i]) {
	    if (!use[i]) same++;
	    else diff++;
	}
    }

    //cout << same << ' ' << diff << endl;
    cout << dp[same][diff] << endl;
    return 0;
}