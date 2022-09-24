#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N, K;
vector<pair<int, int> > G[500011];
int par[500011];

LL dp[500011][2];

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) G[i].clear();
    REP (i, N-1) {
	int x, y, c;
	scanf("%d%d%d", &x, &y, &c);
	x--; y--;
	G[x].emplace_back(y, c);
	G[y].emplace_back(x, c);
    }

    VI ord;
    ord.reserve(N);
    ord.push_back(0);
    par[0] = 0;
    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) if (e->first != par[v]) {
	    par[e->first] = v;
	    ord.push_back(e->first);
	}
    }

    vector<LL> diff;
    REP (i_, N) {
	int v = ord[N-1-i_];
	diff.clear();
	LL sum = 0;
	EACH (e, G[v]) if (e->first != par[v]) {
	    int w = e->first;
	    sum += dp[w][0];
	    diff.push_back(max(0LL, dp[w][1] + e->second - dp[w][0]));
	}

	sort(diff.begin(), diff.end());
	reverse(diff.begin(), diff.end());
	int len = min((int)diff.size(), K);

	dp[v][0] = sum;
	REP (i, len) dp[v][0] += diff[i];

	len = min((int)diff.size(), K-1);
	dp[v][1] = sum;
	REP (i, len) dp[v][1] += diff[i];
    }

    LL ans = max(dp[0][0], dp[0][1]);
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}