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

int N;
char S[100011];
int sums0[100011];
int sums1[100011];
int sumsX[100011];

LL X, Y;

LL solve() {
    REP (i, N) {
	sums0[i+1] = sums0[i];
	sums1[i+1] = sums1[i];
	sumsX[i+1] = sumsX[i];
	if (S[i] == '0') sums0[i+1]++;
	if (S[i] == '1') sums1[i+1]++;
	if (S[i] == '?') sumsX[i+1]++;
    }

    LL c0 = 0, c1 = 0;
    LL cur = 0;
    REP (i, N) {
	if (S[i] == '0') {
	    cur += Y * c1;
	    c0++;
	} else {
	    cur += X * c0;
	    c1++;
	}
    }

    LL ret = cur;

    REP (i, N) if (S[i] == '?') {
	// 01;
	LL a = sums0[i] + sumsX[i];
	cur -= X * a;
	// 10;
	a = sums0[N] - sums0[i+1];
	cur -= Y * a;

	// 10;
	a = sums1[i];
	cur += Y * a;
	// 01;
	a = (sums1[N] - sums1[i+1]) + (sumsX[N] - sumsX[i+1]);
	cur += X * a;

	amin(ret, cur);
    }
    return ret;
}

void MAIN() {
    scanf("%s", S);
    N = strlen(S);
    scanf("%lld%lld", &X, &Y);

    LL ans = solve();
    swap(X, Y);
    reverse(S, S+N);
    LL tmp = solve();
    amin(ans, tmp);
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}