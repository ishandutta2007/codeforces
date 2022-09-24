#include<deque>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

const LL INF = 1LL<<61;



int N, M, D;
LL A[400], B[400], T[400];
LL dp[2][150010];

int main() {
    scanf("%d%d%d", &N, &M, &D);
    for (int i=0; i<M; i++) {
	int a, b, t;
	scanf("%d%d%d", &a, &b, &t);
	A[i] = a-1; B[i] = b; T[i] = t;
    }
    
    for (int i=0; i<M; i++) {
	LL W = D * (i ? T[i] - T[i-1] : T[i]);
	deque<LL>qu;

	for (LL j=0; j<=W && j<N; j++) {
	    while (!qu.empty() && qu.back() < dp[i&1][j]) qu.pop_back();
	    qu.push_back(dp[i&1][j]);
	}

	for (LL j=0; j<N; j++) {
	    LL happy = qu.front() + B[i] - abs(A[i]-j);
	    dp[~i&1][j] = happy;

	    if (j-W >= 0 && dp[i&1][j-W] == qu.front()) qu.pop_front();
	    if (j+W+1 < N) {
		while (!qu.empty() && qu.back() < dp[i&1][j+W+1]) qu.pop_back();
		qu.push_back(dp[i&1][j+W+1]);
	    }
	}
    }

    LL ans = dp[M&1][0];
    for (int i=0; i<N; i++) ans = max(ans, dp[M&1][i]);

    cout << ans << endl;
    

    return 0;
}