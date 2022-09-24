#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0; i<int(n); i++)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

int N, M;
LL MOD;
int C[511];
int Z[3];
LL dp[511][511];

inline void add(LL &x, LL y) {
    x = (x+y) % MOD;
}

int main() {
    scanf("%d%d%lld", &N, &M, &MOD);

    REP ($, M) {
	string S;
	cin >> S;
	REP (i, N) C[i] += S[i] - '0';
    }
    REP (i, N) Z[C[i]]++;

    dp[Z[0]][Z[1]] = 1;
    for (int z = N; z>=0; z--) {
	for (int o = N; o>=0; o--) {
	    // 00
	    if (z>=2 && o<=N-2) {
		add(dp[z-2][o+2], dp[z][o] * z * (z-1) / 2);
	    }
	    
	    // 01
	    if (z>=1 && 1<=o && o<=N-1) {
		add(dp[z-1][o], dp[z][o] * z * o);
	    }

	    // 11
	    if (2<=o) {
		add(dp[z][o-2], dp[z][o] * o * (o-1) / 2);
	    }
	}
    }

    printf("%d\n", (int)dp[0][0]);
    return 0;
}