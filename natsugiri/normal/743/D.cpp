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
int A[200111];
VI G[200111];
LL dp_sum[200111];
LL dp_max[200111];
const LL INF = 1LL<<60;

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

    LL ans = -INF;
    REP (i_, N) {
	int v = ord[N-1-i_];
	dp_sum[v] = A[v];
	LL tmp[3] = { -INF, -INF, -INF };
	EACH (e, G[v]) {
	    dp_sum[v] += dp_sum[*e];
	    tmp[0] = max(dp_max[*e], dp_sum[*e]);
	    sort(tmp, tmp+3);
	}

	if (tmp[1] > -INF) {
	    amax(ans, tmp[1] + tmp[2]);
	}
	dp_max[v] = tmp[2];
    }

    if (ans == -INF) puts("Impossible");
    else printf("%lld\n", ans);

    return 0;
}