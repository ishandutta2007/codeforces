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

VI G[100111];
LL dp[100111][2];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    VI ord; ord.reserve(N);
    ord.push_back(0);
    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) {
	    ord.push_back(*e);
	    G[*e].erase(remove(G[*e].begin(), G[*e].end(), v), G[*e].end());
	}
    }

    LL ans = 0;

    REP (t, 20) {
	LL part = 0;
	REP (i_, N) {
	    int v = ord[N-1-i_];
	    dp[v][0] = 0;
	    dp[v][1] = 0;
	    dp[v][A[v]&1] = 1;
	    part += A[v] & 1;

	    EACH (e, G[v]) {
		part += dp[v][0] * dp[*e][1];
		part += dp[v][1] * dp[*e][0];
		if (A[v] & 1) {
		    dp[v][0] += dp[*e][1];
		    dp[v][1] += dp[*e][0];
		} else {
		    dp[v][0] += dp[*e][0];
		    dp[v][1] += dp[*e][1];
		}
	    }
	}

	ans += part << t;
	REP (i, N) A[i] >>= 1;
    }

    printf("%lld\n", ans);

    return 0;
}