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

int N;
LL S[100011];
LL sums[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", S+i);

    sort(S, S+N);
    N = unique(S, S+N) - S;
    vector<LL> d;
    REP (i, N-1) {
	d.push_back(S[i+1] - S[i]);
    }
    sort(d.begin(), d.end());
    REP (i, d.size()) sums[i+1] = sums[i] + d[i];

    int Q;
    scanf("%d", &Q);
    REP ($, Q) {
	LL l, r;
	scanf("%lld%lld", &l, &r);
	LL len = r - l + 1;
	int k = lower_bound(d.begin(), d.end(), len) - d.begin();
	LL ans = len + sums[k] + ((LL)d.size() - k) * len;
	printf("%lld%c", ans, " \n"[$+1==Q]);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}