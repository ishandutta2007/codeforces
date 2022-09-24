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
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N;
int A[100111];
int C[100111];
LL dp[100111][2];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) C[A[i]]++;
    const int MAX = 100001;
    for (int i=1; i<=MAX; i++) {
	dp[i+1][0] = max(dp[i][0], dp[i][1]);
	if (i > 1) dp[i+1][1] = max(dp[i-1][0], dp[i-1][1]) + (LL)C[i] * i;
	else dp[i+1][1] = C[i];
    }

    LL ans = max(dp[MAX+1][0], dp[MAX+1][1]);
    printf("%lld\n", ans);
    


    return 0;
}