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

int K;
LL calc(pair<LL, LL> *xy, LL N, LL M, LL mid) {
    vector<LL> ys;
    ys.push_back(0);
    REP (i, K) {
	LL y = xy[i].second - mid - 1;
	if (0 <= y && y < M) ys.push_back(y);
	y = xy[i].second + mid + 1;
	if (0 <= y && y < M) ys.push_back(y);
    }

    LL ma = -1;
    LL mi = N;
    EACH (e, ys) {
	LL y = *e;
	LL last = -1;
	REP (i, K) {
	    LL y0 = xy[i].second - mid - 1;
	    LL y1 = xy[i].second + mid + 1;
	    if (y <= y0 || y1 <= y) continue;
	    LL x0 = xy[i].first - mid;
	    LL x1 = xy[i].first + mid;
	    if (last+1 < x0) {
		amin(mi, last+1);
		amax(ma, x0-1);
	    }
	    amax(last, x1);
	}
	amin(mi, last + 1);
	if (last < N-1) amax(ma, N-1);
    }

    if (ma < 0 || N <= mi || ma < mi) return 0;
    else return ma - mi + 1;
}

LL N, M;
LL X[511], Y[511];
pair<LL, LL> xy[511], yx[511];

void MAIN() {
    scanf("%lld%lld", &N, &M);
    scanf("%d", &K);
    REP (i, K) {
	scanf("%lld%lld", X+i, Y+i);
	X[i]--;
	Y[i]--;
	xy[i] = make_pair(X[i], Y[i]);
	yx[i] = make_pair(Y[i], X[i]);
    }

    sort(xy, xy+K);
    sort(yx, yx+K);
    LL lo = -1, hi = 1<<30;
    while (hi - lo > 1) {
	LL mid = (hi + lo) / 2;

	LL r = calc(xy, N, M, mid);
	amax(r, calc(yx, M, N, mid));

	if (r <= mid * 2 + 1) hi = mid;
	else lo = mid;
    }

    printf("%lld\n", hi);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}