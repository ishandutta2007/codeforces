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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

int N, K;
int A[4011][4011];
int dp[811][4011];
int cost[4011][4011];

void rec(int t, int x, int y, int l, int r) { // calc dp[t][i] where i in [x .. y)
    if (l+1 == r) {
	for (int i=x; i<y; i++) amin(dp[t][i], dp[t-1][l] + cost[l][i]);
	return ;
    }

    int m = (x + y) / 2;
    int k = l;
    for (int i=l; i<r && i<m; i++) {
	if (dp[t][m] > dp[t-1][i] + cost[i][m]) {
	    dp[t][m] = dp[t-1][i] + cost[i][m];
	    k = i;
	}
    }

    if (x + 1 >= y) return ;

    rec(t, x, m, l, k+1);
    rec(t, m+1, y, k, r);
}

char buf[1000000];

int main() {
    scanf("%d%d", &N, &K);
    scanf(" ");
    REP (i, N) {
	fgets(buf, 1000000, stdin);
	REP (j, N) A[i][j+1] = buf[j*2] - '0'; // scanf("%hd", A[i]+j+1);
    }
    REP (i, N) REP (j, N+2) A[i][j+1] += A[i][j];

    REP (i, N) for (int j=i+1; j<=N+1; j++) {
	cost[i][j] = cost[i][j-1] + A[j-1][j] - A[j-1][i];
    }

    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int t=1; t<=K; t++) rec(t, 1, N+1, 0, N);

    printf("%d\n", dp[K][N]);

    return 0;
}