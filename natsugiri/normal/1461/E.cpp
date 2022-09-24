#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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

LL K, L, R, T, X, Y;

void MAIN() {
    scanf("%lld%lld%lld%lld%lld%lld", &K, &L, &R, &T, &X, &Y);

    bool yes = false;

    if (X == Y) {
	if (K + Y <= R || K - X >= L) {
	    yes = true;
	} else {
	    yes = false;
	}
    } else if (X > Y) {
	LL d = X - Y;
	if (K + Y <= R) {
	    // K-d, K-2d,
	    LL x = (K - L) / d;
	    yes = (x >= T);
	} else {
	    // K-X, K-X-d, K-X-2d,
	    if (K-X < L) {
		yes = false;
	    } else {
		LL x = (K-X-L) / d + 1;
		yes = (x >= T);
	    }
	}
    } else {
	LL day = 0;
	if (K + Y <= R) K += Y;

	LL cnt = 0;
	yes = true;
	while (cnt <= X && day < T) {
	    if (K > R-Y) {
		LL x = (K - (R-Y) + X - 1) / X;
		amin(x, T - day);
		day += x;
		K -= x * X;
		if (K < L) {
		    yes = false;
		    break;
		}
		if (day >= T) {
		    yes = true;
		    break;
		}
		K += Y;
		cnt++;
	    } else {
		K -= X;
		day++;
		if (K < L) {
		    yes = false;
		    break;
		}
		if (day >= T) {
		    yes = true;
		    break;
		}
		K += Y;
		cnt++;
	    }
	}
    }

    puts(yes? "Yes": "No");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}