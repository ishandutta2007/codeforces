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

using Double = long double;
Double V;

Double solve(int X) {
    Double ret = 0;
    Double prob = 1.0L;
    int cnt = 1;
    while (1) {
	ret += cnt * prob * (40000.0L - X) / 40000.0L;
	if (X == 0) break;
	cnt++;
	prob *= (Double)X / 40000.0L;
	X -= V;
	amax(X, 0);
    }
    return ret;
}

Double rec(int C, int M) {
    Double prob_c = (Double)C / 40000.0L;
    Double prob_m = (Double)M / 40000.0L;

    Double ret = 1;
    if (C) {
	if (C <= V) {
	    ret += prob_c * solve(M + C / 2);
	} else {
	    ret += prob_c * rec(C - V, M + V / 2);
	}
    }
    if (M) {
	if (M <= V) {
	    ret += prob_m * solve(C + M / 2);
	} else {
	    ret += prob_m * rec(C + V / 2, M - V);
	}
    }

    return ret;
}

Double C, M, P;

int read() {
    static char s[111];
    scanf("%s", s);
    int len = strlen(s);
    while (len < 6) {
	s[len++] = '0';
    }
    s[len] = 0;
    int x;
    sscanf(s+2, "%d", &x);
    // eprintf("%d\n", x);
    return x * 4;
}

void MAIN() {
    C = read();
    M = read();
    P = read();
    V = read();

    // Double ans = rec(C, M);
    Double ans = rec(C, M);
    printf("%.20f\n", (double)ans);

}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}