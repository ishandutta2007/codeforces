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

int N, K;
bool dp[501][501];
int A[501];

int main() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", A+i);

    dp[0][0] = true;
    REP (i, N) {
	for (int y=K; y>=0; y--) for (int x=K; x>=0; x--) if (dp[y][x]) {
	    if (y + A[i] <= K) dp[y+A[i]][x] = true;
	    if (x + A[i] <= K) dp[y][x+A[i]] = true;
	}
    }

    VI ans;
    REP (i, K+1) if (dp[i][K-i]) ans.push_back(i);
    sort(ans.begin(), ans.end());

    printf("%d\n", (int)ans.size());
    rprintf("%d", ans.begin(), ans.end());


    return 0;
}