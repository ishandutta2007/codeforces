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

int N;

LL C;

LL atk[1000011];

void MAIN() {
    scanf("%d%lld", &N, &C);
    memset(atk, 0xc0, sizeof atk);

    REP (i, N) {
	LL c, d, h;
	scanf("%lld%lld%lld", &c, &d, &h);
	amax(atk[c], d * h);
    }

    for (int c=1000010; c>=1; c--) if (atk[c] >= 0) {
	int x = c * 2;
	LL a = atk[c] * 2;
	for (; x<1000011; x+=c, a += atk[c]) {
	    amax(atk[x], a);
	}
    }
    for (int c=1; c<1000011; c++) {
	amax(atk[c], atk[c-1]);
    }

    int M;
    scanf("%d", &M);
    REP ($, M) {
	LL D, H;
	scanf("%lld%lld", &D, &H);
	LL DH = D * H;
	int ans = 0;
	if (atk[C] <= DH) {
	    ans = -1;
	} else {
	    ans = upper_bound(atk, atk+C, DH) - atk;
	}
	printf("%d%c", ans, " \n"[$==M-1]);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}