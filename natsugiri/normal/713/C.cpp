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

int N, A[3011];
LL dp[2][3011];

int main() {

    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    memset(dp, 0x3f, sizeof dp);

    REP (i, N) dp[0][i] = 0;

    vector<pair<LL, int> > pos(N);

    REP (i, N) {
	int cur = i & 1, nxt = cur ^ 1;

	memset(dp[nxt], 0x3f, sizeof dp[nxt]);

	REP (j, N) {
	    LL pre = A[j] + i - 1 - j;
	    pos[j] = make_pair(pre, j);
	}
	sort(pos.begin(), pos.end());

	LL mi = 1LL<<60;
	EACH (e, pos) {
	    LL pos = e->first + 1;
	    amin(mi, dp[cur][e->second]);

	    amin(dp[nxt][e->second], mi + abs(pos - A[i]));
	}
    }

    LL ans = 1LL<<60;
    REP (i, N) amin(ans, dp[N&1][i]);

    printf("%lld\n", ans);
    return 0;
}