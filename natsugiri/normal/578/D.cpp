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

int N, M;
char S[100111];
LL dp[100111][8];

// dp[0]:
// null
// dp[0] := { -2, 0, 0 }

// T[0..i)
// dp[i] := { i-2 i-1, i-1 i, i-1 i }

// T[i] x S[i-1], S[i], S[i+1];
// dp[i+1] := { i-1 i, i i+1, i i+1 }


int main() {
    scanf("%d%d", &N, &M);
    scanf("%s", S);


    dp[0][7] = 1;
    
    REP (i, N) {
	REP (k, 8) if (dp[i][k]) {
	    REP (c_, M) {
		int nk = 0;
		char c = c_ + 'a';

		if (i && S[i-1] == c) nk |= k&1;
		if (S[i] == c) nk |= k&2;
		if (S[i+1] == c) nk |= k&4;
		
		if (k&2) nk |= 1;
		if (nk&2) nk |= 4;
		if (~k&4 && ~nk&1 && S[i] != c) continue;

		dp[i+1][nk] += dp[i][k];
		// eprintf("%c : %d -> %d\n", c, k, nk);
	    }
	}
    }

    LL ans = 0;
    REP (k, 8) if (~k&2) ans += dp[N][k];
    printf("%lld\n", ans);
    return 0;
}