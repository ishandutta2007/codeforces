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
int M;
int Rb, Cb, Rd, Cd;

void MAIN() {
    scanf("%d%d%d%d%d%d", &N, &M, &Rb, &Cb, &Rd, &Cd);

    Rb--;
    Cb--;
    Rd--;
    Cd--;

    int ans = 0;
    int dr = 1, dc = 1;
    REP (t, 10000) {
	if (Rb == Rd || Cb == Cd) {
	    ans = t;
	    break;
	}

	int rr = Rb + dr;
	if (rr < 0 || N <= rr) dr = -dr;
	int cc = Cb + dc;
	if (cc < 0 || M <= cc) dc = -dc;
	Rb = Rb + dr;
	Cb = Cb + dc;
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}