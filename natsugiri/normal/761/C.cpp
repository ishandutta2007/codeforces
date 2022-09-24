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

int N, M;
char S[55];
int dp[55][8];

int main() {
    scanf("%d%d", &N, &M);

    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    REP (i, N) {
	scanf("%s", S);

	REP (j, M) {
	    int c = min(j, M-j);
	    int mask;
	    if (isdigit(S[j])) mask = 1;
	    else if (islower(S[j])) mask = 2;
	    else mask = 4;

	    REP (k, 8) amin(dp[i+1][k | mask], dp[i][k] + c);
	}
    }

    printf("%d\n", dp[N][7]);

    return 0;
}