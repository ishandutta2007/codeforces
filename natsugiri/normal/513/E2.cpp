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

const int INF = 1e9;

int N, K, A[30011];
int S[30011][201][2][2], C[30011][201][2][2];

int main() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", A+i);

    REP (i, N+1) REP (j, K+1) REP (c, 2) REP (d, 2) S[i][j][c][d] = C[i][j][c][d] = -INF;
    REP (c, 2) REP (d, 2) S[0][0][c][d] = 0;
    REP (i, N) REP (j, K) {
	REP (c, 2) REP (d, 2) REP (e, 2) {
	    int p;
	    if (j==0) p = (d==0? 1: -1);
	    else if (j==K-1) p = (c==0? -1: 1);
	    else p = (c==d? 0: (c==0? -2: 2));
	    
	    amax(S[i+1][j+1][d][e], p*A[i] + S[i][j][c][d]); // one
	    amax(S[i+1][j+1][d][e], p*A[i] + C[i][j][c][d]); // cut
	    amax(C[i+1][j][c][d], p*A[i] + S[i][j][c][d]); // new
	    amax(C[i+1][j][c][d], p*A[i] + C[i][j][c][d]); // seq 
	    amax(S[i+1][j][c][d], S[i][j][c][d]); // skip
	}
    }

    int ans = -INF;
    REP (i, N+1) REP (c, 2) REP (d, 2) {
	amax(ans, C[i][K][c][d]);
	amax(ans, S[i][K][c][d]);
    }

    printf("%d\n", ans);
    
    return 0;
}