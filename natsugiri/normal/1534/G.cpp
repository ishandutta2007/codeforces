#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>

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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N;
LL X[800011];
LL Y[800011];
int idx[800011];

struct CMP {
    bool operator()(int i, int j) {
	if (X[i] + Y[i] != X[j] + Y[j]) return X[i] + Y[i] < X[j] + Y[j];
	return X[i] < X[j];
    }
} cmp;


void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld%lld", X+i, Y+i);

    REP (i, N) idx[i] = i;
    sort(idx, idx+N, cmp);

    priority_queue<LL, vector<LL>, greater<LL> > R;
    priority_queue<LL> L;

    L.push(0);
    R.push(0);

    LL R_ADD = 0;
    LL ans = 0;

    LL prv = 0;

    for (int i=0; i<N; i++) {
	LL x = X[idx[i]];
	LL y = Y[idx[i]];
	LL cur = x + y;
	R_ADD += cur - prv;

	L.push(x);
	R.push(x - R_ADD);

	while (R.top() + R_ADD < L.top()) {
	    LL rt = R.top() + R_ADD; R.pop();
	    LL lt = L.top(); L.pop();
	    ans += lt - rt;
	    L.push(rt);
	    R.push(lt - R_ADD);
	}

	prv = cur;
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}