#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<cmath>

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

void SORT(VI &x) {
    sort(x.begin(), x.end(), [](int a, int b) {
	    return abs(a) < abs(b);
	    });
}
VI X, Y;

long double sq(long double x) {
    return x * x;
}

void MAIN() {
    scanf("%d", &N);
    X.clear();
    Y.clear();
    REP (i, N*2) {
	int x, y;
	scanf("%d%d", &x, &y);
	if (x == 0) {
	    Y.push_back(y);
	} else {
	    X.push_back(x);
	}
    }

    SORT(X);
    SORT(Y);

    long double ans = 0;
    REP (i, N) {
	ans += sqrt(sq(X[i]) + sq(Y[i]));
    }

    printf("%.20f\n", (double)ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}