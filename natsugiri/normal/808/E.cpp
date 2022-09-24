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

int N, M;
VI G[4];
vector<LL> sums[4];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) {
	int w, c;
	scanf("%d%d", &w, &c);
	G[w].push_back(c);
    }
    REP (i, 4) {
	sort(G[i].rbegin(), G[i].rend());
	sums[i].resize(G[i].size() + 1, 0);
	REP (j, G[i].size()) sums[i][j+1] = sums[i][j] + G[i][j];
    }

    LL ans = 0;
    REP (c, sums[3].size()) {
	if (3 * c > M) break;
	int lo = -1, hi = G[2].size();
	while (hi - lo > 1) {
	    int mid = (hi + lo) / 2;
	    if (3 * c + 2 * (mid + 1) > M) {
		hi = mid;
	    } else {
		int tok = min((int)G[1].size(), M - 3 * c - 2 * (mid + 1));
		if (G[2][mid] <
			(LL)(tok < (int)G[1].size()? G[1][tok]: 0LL) +
			(LL)(tok+1 < (int)G[1].size()? G[1][tok+1]: 0LL)) {
		    hi = mid;
		} else {
		    lo = mid;
		}
	    }
	}

	{
	    int tok = min((int)G[1].size(), M - 3 * c - 2 * hi);
	    LL tmp = sums[3][c] + sums[2][hi] + sums[1][tok];
	    amax(ans, tmp);
	}
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}