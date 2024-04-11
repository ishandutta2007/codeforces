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
const int MAXN = 200011;
VI G[MAXN];
LL dp[MAXN][5][2];
LL dwn[MAXN][5][2];
LL buf[5][2];
VI ord;

int main() {
    scanf("%d%d", &N, &K);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    ord.reserve(N);
    ord.push_back(0);
    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) {
	    ord.push_back(*e);
	    G[*e].erase(remove(G[*e].begin(), G[*e].end(), v), G[*e].end());
	}
    }

    REP (i_, N) {
	int v = ord[N-1-i_];
	EACH (e, G[v]) {
	    dp[v][1%K][0] += dp[*e][0][0];
	    dp[v][1%K][1] += dp[*e][0][0] + dp[*e][0][1];
	    for (int j=1; j<K; j++) {
		dp[v][(j+1)%K][0] += dp[*e][j][0];
		dp[v][(j+1)%K][1] += dp[*e][j][1];
	    }
	}

	dp[v][0][0]++;
    }

    LL ans = 0;
    REP (i_, N) {
	int v = ord[i_];
	REP (j, K) {
	    dwn[v][j][0] += dp[v][j][0];
	    dwn[v][j][1] += dp[v][j][1];
	    ans += dwn[v][j][1];
	}

	EACH (e, G[v]) {
	    buf[1%K][0] = dwn[v][1%K][0] - dp[*e][0][0];
	    buf[1%K][1] = dwn[v][1%K][1] - dp[*e][0][0] - dp[*e][0][1];
	    for (int j=1; j<K; j++) {
		buf[(j+1)%K][0] = dwn[v][(j+1)%K][0] - dp[*e][j][0];
		buf[(j+1)%K][1] = dwn[v][(j+1)%K][1] - dp[*e][j][1];
	    }

	    dwn[*e][1%K][0] += buf[0][0];
	    dwn[*e][1%K][1] += buf[0][0] + buf[0][1];
	    for (int j=1; j<K; j++) {
		dwn[*e][(j+1)%K][0] += buf[j][0];
		dwn[*e][(j+1)%K][1] += buf[j][1];
	    }
	}
    }

    printf("%lld\n", ans / 2);
//    eprintf("%lld\n", ans);
    return 0;
}