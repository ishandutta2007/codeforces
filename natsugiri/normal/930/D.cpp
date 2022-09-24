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

int Y_high[1000111], Y_low[1000111];

LL solve(vector<pair<int, int> > ps) {
    if ((int) ps.size() < 4) return 0;

    sort(ps.begin(), ps.end());
    int left = ps[0].first, right = ps.back().first;

    int cur = 0;
    const int INF = 1<<29;
    int y_high = -INF, y_low = INF;
    for (int x=left+1; x<right; x+=2) {
	while (cur < (int)ps.size() && ps[cur].first < x) {
	    amax(y_high, ps[cur].second);
	    amin(y_low, ps[cur].second);
	    cur++;
	}

	Y_high[x-left] = y_high;
	Y_low[x-left] = y_low;
    }

    LL ret = 0;
    cur = ps.size() - 1;
    y_high = -INF; y_low = INF;
    for (int x=right-1; x>left; x-=2) {
	while (cur && x < ps[cur].first) {
	    amax(y_high, ps[cur].second);
	    amin(y_low, ps[cur].second);
	    cur--;
	}
	
	int hi = min(Y_high[x-left], y_high);
	int lo = max(Y_low[x-left], y_low);
	if (hi > lo) ret += (hi - lo) / 2;
    }
    return ret;
}

int N;

void MAIN() {
    scanf("%d", &N);
    vector<pair<int, int> > odd, even;
    REP (i, N) {
	int x, y;
	scanf("%d%d", &x, &y);
	int xx = x + y, yy = x - y;
	if (xx & 1) {
	    odd.emplace_back(xx+1, yy+1);
	} else {
	    even.emplace_back(xx, yy);
	}
    }

    LL ans = solve(odd) + solve(even);
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}