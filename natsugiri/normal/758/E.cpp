#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

const int MAXN = 200111;
const LL INF = 1LL<<60;

int N;
VI G[MAXN];
LL P[MAXN], W[MAXN], sumW[MAXN];
int par[MAXN];
LL low[MAXN], high[MAXN];
LL ans[MAXN];
LL dp[MAXN];

LL C[MAXN];

VI ord;

int main() {
    scanf("%d", &N);
    REP (i, N-1) {
	int x, y, w, p;
	scanf("%d%d%d%d", &x, &y, &w, &p);
	x--; y--;
	G[x].push_back(y);
	par[y] = x;

	P[y] = p;
	W[y] = w;
	C[i] = y;
    }

    P[0] = INF;
    W[0] = 0;


    ord.reserve(N);
    ord.push_back(0);
    REP (i, N) {
	int v = ord[i];
	EACH (e, G[v]) ord.push_back(*e);
    }

    bool yes = true;
    REP (i_, N) {
	int v = ord[N-1-i_];
	low[v] = high[v] = 0;
	EACH (e, G[v]) {
	    LL de = min(P[*e] - low[*e], W[*e] - 1);
	    low[v] += low[*e] + W[*e] - de;
	    high[v] += high[*e] + W[*e];

	    sumW[v] += sumW[*e] + W[*e];
	}

	amin(high[v], P[v]);

	if (high[v] < low[v]) {
	    yes = false;
	    break;
	}
	if (P[v] < low[v]) {
	    yes = false;
	    break;
	}
    }

    if (!yes) {
	puts("-1");
	return 0;
    }


    dp[0] = high[0];
    REP (i_, N) {
	int v = ord[i_];

	LL re = dp[v];

	if (v) {
	    LL de = min(P[v] - low[v], W[v] - 1);
	    amin(de, (P[v] - re + W[v]) / 2);
	    ans[v] += W[v] - de;
	    re -= W[v] - de;
	}

	EACH (e, G[v]) {
	    LL de = min(P[*e] - low[*e], W[*e] - 1);
	    LL tmp = low[*e] + W[*e] - de;
	    dp[*e] += tmp;
	    re -= tmp;
	}
	EACH (e, G[v]) {
	    LL de = min(P[*e] - low[*e], W[*e] - 1);
	    LL tmp_low = low[*e] + W[*e] - de;
	    LL tmp_high = high[*e] + W[*e];
	    LL tmp = tmp_high - tmp_low;
	    amin(tmp, re);
	    dp[*e] += tmp;
	    re -= tmp;
	}

	ans[v] += re;
    }


    printf("%d\n", N);
    REP (i, N-1) {
	int v = C[i];
	printf("%d %d %lld %lld\n", par[v]+1, v+1, ans[v], P[v] - (W[v] - ans[v]));
    }

    return 0;
}