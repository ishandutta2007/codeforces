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

typedef unsigned long long ULL;

ULL gcd(ULL x, ULL y) {
    while (1) {
	if (x) y %= x; else return y;
	if (y) x %= y; else return x;
    }
}

int N;
LL DX1, DY1, DX2, DY2;
vector<pair<int, int> > ans;

int ccw(LL x1, LL y1, LL x2, LL y2) {
    LL tmp = x1 * y2 - x2 * y1;
    if (tmp > 0) return 1;
    if (tmp < 0) return -1;
    return 0;
}
int ccw(LL x0, LL y0, LL x1, LL y1, LL x2, LL y2) {
    return ccw(x1-x0, y1-y0, x2-x0, y2-y0);
}

void MAIN() {
    scanf("%d%lld%lld%lld%lld", &N, &DX1, &DY1, &DX2, &DY2);
    if (DY1 < 0) {
	DX1 = -DX1;
	DY1 = -DY1;
    }
    if (DY2 < 0) {
	DX2 = -DX2;
	DY2 = -DY2;
    }
    if (ccw(DX2, DY2, DX1, DY1) == 1) {
	swap(DX1, DX2);
	swap(DY1, DY2);
    }

    bool yes = true;
    LL area = abs(DX1 * DY2 - DX2 * DY1);
    //eprintf("%lld %d\n", area, N);

    if (yes && area != N) {
	yes = false;
    }

    if (yes) {
	ans.clear();
	LL prv_x = 0;
	for (LL y=0; y<=DY1+DY2; y++) {
	    LL x = prv_x;
	    while (1) {
		int c1 = ccw(DX2, DY2, x, y);
		int c2 = ccw(DX2, DY2, DX2+DX1, DY2+DY1, x, y);
		if (c1 != 1 && c2 != 1) break;
		x++;
	    }
	    while (1) {
		int c1 = ccw(DX2, DY2, x, y);
		int c2 = ccw(DX2, DY2, DX2+DX1, DY2+DY1, x, y);
		//eprintf("%lld %lld, %d %d\n", x, y, c1, c2);
		if (c1 == 1) break;
		if (c2 == 1) break;
		x--;
	    }
	    prv_x = x;

	    while (1) {
		int c1 = ccw(DX2, DY2, x, y);
		int c2 = ccw(DX2, DY2, DX2+DX1, DY2+DY1, x, y);
		int c3 = ccw(DX1, DY1, x, y);
		int c4 = ccw(DX1, DY1, DX2+DX1, DY2+DY1, x, y);
		//eprintf("%lld %lld, %d %d %d %d\n", x, y, c1, c2, c3, c4);

		if (c3 == -1) break;
		if (c4 == -1) break;

		if (x == 0 && y == 0) {
		    ans.emplace_back(0, 0);
		} else if (c2 == 0) {
		} else if (c4 == 0) {
		} else if (c1 != 1 && c2 != 1) {
		    ans.emplace_back(x, y);
		}
		x++;
	    }
	}
    }

    if (yes) {
	puts("YES");
	REP (i, ans.size()) printf("%d %d\n", ans[i].first, ans[i].second);
    } else {
	puts("NO");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}