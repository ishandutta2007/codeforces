#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

LL calc(const VI &X, const VI &Y) {
    LL ret = 0;
    EACH (e, X) ret += *e;
    EACH (e, Y) ret += *e;

    REP (i, min((int)Y.size(), (int)X.size()-1)) {
	ret += X.rbegin()[i];
    }
    REP (i, min((int)Y.size(), (int)X.size())) {
	ret += Y.rbegin()[i];
    }
    return ret;
}

int N;
int A[100011];
VI X, Y;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    X.clear();
    Y.clear();

    REP (i, N) {
	int x;
	scanf("%d", &x);
	if (A[i] == 0) X.push_back(x);
	else Y.push_back(x);
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    LL ans = max(calc(X, Y), calc(Y, X));
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}