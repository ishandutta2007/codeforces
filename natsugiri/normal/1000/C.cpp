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
vector<pair<LL, LL > > E;
LL ans[200011];

void MAIN() {
    scanf("%d", &N);
    E.reserve(N+N);

    REP (i, N) {
	LL l, r;
	scanf("%lld%lld", &l, &r);
	E.emplace_back(l, -1);
	E.emplace_back(r, 1);
    }

    sort(E.begin(), E.end());
    int cnt = 0;
    LL prv = E[0].first-1;
    for (int i=0; i<(int)E.size();) {

	// (prv, cur);
	ans[cnt] += E[i].first - prv - 1;

	int stop = i;
	while (stop < (int)E.size() && E[stop].first == E[i].first && E[stop].second == -1) {
	    cnt++;
	    stop++;
	}

	// cur;
	ans[cnt]++;
	prv = E[i].first;

	while (stop < (int)E.size() && E[stop].first == E[i].first && E[stop].second == 1) {
	    cnt--;
	    stop++;
	}

	i = stop;
    }

    rprintf("%lld", ans+1, ans+N+1);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}