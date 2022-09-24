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

LL gcd(LL x_, LL y_) {
    typedef unsigned long long ULL;
    ULL x = abs(x_);
    ULL y = abs(y_);
    while (1) {
	if (x) y %= x; else return y;
	if (y) x %= y; else return x;
    }
}

int N;
LL X[6011];
LL Y[6011];

int C[2][2];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld%lld", X+i, Y+i);


    REP (i, N) {
	bool bx = (X[i] % 4 != 0);
	bool by = (Y[i] % 4 != 0);
	C[by][bx]++;
    }

//    int ans2 = 0;
//    REP (i, N) REP (j, i) REP (k, j) {
//	LL g = gcd(X[i]-X[j], Y[i]-Y[j]) +
//	    gcd(X[i]-X[k], Y[i]-Y[k]) +
//	    gcd(X[k]-X[j], Y[k]-Y[j]);
//	if (g % 4 == 0) {
//	    ans2++;
//	}
//    }
//    eprintf("%d\n", ans2);
    
    LL ans = 0;

    REP (a, 4) if (C[a/2][a%2]) {
	LL wa = C[a/2][a%2];
	C[a/2][a%2]--;
	REP (b, a+1) if (C[b/2][b%2]) {
	    LL wb = C[b/2][b%2];
	    C[b/2][b%2]--;
	    REP (c, b+1) if (C[c/2][c%2]) {
		LL wc = C[c/2][c%2];
		int cnt = 0;
		if (a != b) cnt++;
		if (b != c) cnt++;
		if (c != a) cnt++;

		if (cnt % 2 == 0) {
		    LL tmp = wa * wb * wc;

		    if (a == b && b == c) {
			tmp /= 6;
		    } else if (a == b || b == c) {
			tmp /= 2;
		    }

		    ans += tmp;
		}
	    }
	    C[b/2][b%2]++;
	}
	C[a/2][a%2]++;
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}