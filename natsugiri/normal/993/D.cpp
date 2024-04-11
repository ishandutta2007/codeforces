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

pair<LL, LL> P[55];

LL buf_[2][55];
LL *cur = buf_[0];
LL *nxt = buf_[1];
LL sums[55];

const int BASE = 1000;

bool ok(LL W) {
    // 1000*pow[i] - W*proc[i];

    memset(cur, 0x3f, sizeof buf_[0]);
    cur[0] = 0;

    for (int i=0; i<N; ) {
	memset(nxt, 0x3f, sizeof buf_[0]);

	int j = i;
	int len = 0;
	while (j < N && P[i].first == P[j].first) {
	    sums[len+1] = sums[len] + BASE*P[j].first - W*P[j].second;
	    len++;
	    j++;
	}


	REP (k, i+1) {
	    REP (b, min(k+1, len+1)) {
		int a = len - b;
		amin(nxt[k+a-b], cur[k] + sums[a]);
	    }
	}
	swap(cur, nxt);
	i = j;
    }

//    eprintf("%lld ", *min_element(cur, cur+N+1));
//    printf("(%lld) : ", W);
//    rprintf("%lld", cur, cur+N+1);
    return *min_element(cur, cur+N+1) <= 0;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", &P[i].first);
    REP (i, N) scanf("%lld", &P[i].second);
    sort(P, P+N);
    reverse(P, P+N);

    LL lo = 0, hi = 1;
    while (!ok(hi)) {
	lo = hi;
	hi += hi;
    }
    while (hi - lo > 1) {
	LL mid = (lo + hi) / 2;
	(ok(mid)? hi: lo) = mid;
    }


    printf("%lld\n", hi);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}