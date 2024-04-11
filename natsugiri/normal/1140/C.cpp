#include<queue>
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
pair<LL, LL> BT[300011];

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) {
	int t, b;
	scanf("%d%d", &t, &b);
	BT[i] = make_pair(b, t);
    }

    LL ans = 0;
    sort(BT, BT+N);
    priority_queue<LL> Q;
    LL sum = 0;
    for (int i=N; i--;) {
	Q.push(-BT[i].second);
	sum += BT[i].second;
	if ((int)Q.size() > K) {
	    sum += Q.top();
	    Q.pop();
	}
	amax(ans, sum * BT[i].first);
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}