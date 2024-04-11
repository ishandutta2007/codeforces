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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

LL A[6];
int N;
LL B[100011];

struct Data {
    LL val;
    int i;

    Data(LL val_, int i_): val(val_), i(i_) {}


    bool operator<(const Data &y) const {
	return val > y.val;
    }
};

void MAIN() {
    REP (i, 6) scanf("%lld", A+i);
    scanf("%d", &N);
    REP (i, N) scanf("%lld", B+i);

    LL ans = 1LL<<60;

    if (N == 1) {
	ans = 0;
    } else {
	sort(A, A+6);
	sort(B, B+N);

	priority_queue<Data> Q;
	REP (j, N-1) Q.emplace(B[j] - A[5], 5); 
	Data high(B[N-1] - A[5], 5);
	amin(ans, high.val - Q.top().val);

	while (1) {
	    Data d = Q.top();
	    Q.pop();
	    if (d.i == 0) break;
	    d.val += A[d.i];
	    d.i--;
	    d.val -= A[d.i];
	    if (high.val < d.val) swap(high, d);
	    Q.push(d);
	    amin(ans, high.val - Q.top().val);
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