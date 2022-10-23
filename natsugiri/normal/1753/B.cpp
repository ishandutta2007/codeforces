#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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
LL X;
LL A[500011];
priority_queue<LL, vector<LL>, greater<LL> > Q;

bool solve() {
    while (!Q.empty()) {
	LL a = Q.top();
	Q.pop();

	if ((LL)Q.size() < a) return false;

	REP (i, a) {
	    if (Q.top() != a) return false;
	    Q.pop();
	}

	if (a + 1 < X) {
	    Q.push(a+1);
	}
    }
    return true;
}

void MAIN() {
    scanf("%d%lld", &N, &X);
    REP (i, N) {
	LL a;
	scanf("%lld", &a);
	if (a < X) Q.push(a);
    }

    bool yes = solve();
    puts(yes?"Yes":"No");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}