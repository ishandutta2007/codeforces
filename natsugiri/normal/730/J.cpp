#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

int N;
int A[111], B[111];
int dp[101][10011];

int main() {

    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) scanf("%d", B+i);
    int a_sum = 0, b_sum = 0;
    REP (i, N) {
	a_sum += A[i];
	b_sum += B[i];
    }

    memset(dp, 0xc0, sizeof dp);
    int INVALID = dp[0][0];

    dp[0][0] = 0;
    REP (i, N) {
	for (int j=i; j>=0; j--) {
	    REP (k, b_sum+1-B[i]) if (dp[j][k] != INVALID) {
		amax(dp[j+1][k+B[i]], dp[j][k] + A[i]);
	    }
	}
    }

    int cnt = -1, cost = 1<<29;
    REP (i, N+1) {
	if (cnt == -1) {
	    REP (k, b_sum+1) if (dp[i][k] != INVALID) {
		if (k >= a_sum) {
		    cnt = i;
		    if (a_sum - dp[i][k] < cost) cost = a_sum - dp[i][k];
		}
	    }
	}
    }

    printf("%d %d\n", cnt, cost);



    return 0;
}