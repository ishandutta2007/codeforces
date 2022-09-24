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

template<class T> inline void amin(T &a, T b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, T b) { if (a<b) a=b; }

int N, T;
double P;
double dp[2011][2011];
int main() {
    scanf("%d%lf%d", &N, &P, &T);

    dp[0][0] = 1.0;
    REP (i, T) {
	REP (k, N) {
	    dp[i+1][k+1] += P * dp[i][k];
	    dp[i+1][k] += (1.0 - P) * dp[i][k];
	}
	dp[i+1][N] += dp[i][N];
    }

    double ans = 0;
    REP (i, N+1) ans += dp[T][i] * i;
    printf("%.9f\n", ans);
    return 0;
}