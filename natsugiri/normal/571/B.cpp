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

int N, K;
LL A[300011];

LL dp[5011][5011];
LL INF ;
int main() {
    scanf("%d%d", &N, &K);

    REP (i, N) {
	int a;
	scanf("%d", &a);
	A[i] = a;
    }
    
// #ifdef LOCAL
//     N = 300000 - 2500;
//     K = 5000;
//     REP (i, N) A[i] = rand();
// #endif
    
    sort(A, A+N);
    
    int L[2] = { N/K, N/K+1 };
    int C[2] = { K-N%K, N%K };

    memset(&INF, 0x3f, sizeof (LL));
    memset(dp, 0x3f, sizeof dp);
    
    dp[0][0] = 0;


    REP (i, C[0]+1) REP (j, C[1]+1) {
	int l = L[0] * i + L[1] * j;
	if (i < C[0] && l + L[0] <= N) {
	    amin(dp[i+1][j], dp[i][j] + A[l + L[0] - 1] - A[l]);
	}
	if (j < C[1] && l + L[1] <= N) {
	    amin(dp[i][j+1], dp[i][j] + A[l + L[1] - 1] - A[l]);
	}
    }
    printf("%lld\n", dp[C[0]][C[1]]);
    return 0;
    
    return 0;
}