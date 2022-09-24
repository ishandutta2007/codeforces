#include<map>
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

const int MAX = 30010;
const int INF = 1<<29;
int N, D, Z[MAX+100];

int dp[MAX][600];
int solve() {
    memset(dp, -1, sizeof dp);
    int L = max(1, D-300), H = min(L+600, D+300);
    dp[D][D-L] = Z[D];
    
    for (int i=D; i<=MAX; i++) {
	// cerr << i << endl;
	for (int len=L; len<H; len++) {
	    int j = len-L;
	    if (dp[i][j] < 0) continue;
	    int v = dp[i][j];

	    if (i+len+1 <= MAX) {
		amax(dp[i+len+1][j+1], v+Z[i+len+1]);
	    }
	    if (i+len <= MAX) {
		amax(dp[i+len][j], v+Z[i+len]);
	    }
	    if(len>1 && i+len-1 <= MAX) {
		amax(dp[i+len-1][j-1], v+Z[i+len-1]);
	    }
	}
    }
    int ans = 0;
    REP (i, MAX+1) REP (j, 600)  amax(ans, dp[i][j]);
    return ans;
}

int main() {
    scanf("%d%d", &N, &D);
    REP (i, N) {
	int x;
	scanf("%d", &x);
	Z[x]++;
    }

    int ans = 0;
    ans = solve();

    printf("%d\n", ans);
    return 0;
}