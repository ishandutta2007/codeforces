#include<cmath>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0,i##_len=(n); i<i##_len; i++)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

int N, M;
int P_[5111], T[5111];
double P[5111];

double dp[5111][5111];

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) {
	scanf("%d%d", P_+i, T+i);
	P[i] = P_[i] * 0.01;
    }

    dp[0][0] = 1;
    REP (i, N) {
	double sum = 0;
	REP (j, M) {
	    sum = sum * (1 - P[i]) + dp[i][j];
	    if (j+1 >= T[i]) {
		sum -= pow(1-P[i], T[i]-1) * dp[i][j+1-T[i]];
		dp[i+1][j+1] += pow(1-P[i], T[i]-1) * dp[i][j+1-T[i]];
	    }
	    dp[i+1][j+1] += P[i] * sum;
	}
	dp[i][M] += (1-P[i]) * sum;

	// REP (j, M+1)
	//     printf("%.3f ", dp[i+1][j]);
	// puts("");
    }

    double ans = 0;
    REP (i, N) 
	ans += i * dp[i][M];
    REP (j, M+1)
	ans += N * dp[N][j];
    
    printf("%.9f\n", ans);

    return 0;
}