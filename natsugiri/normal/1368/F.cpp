#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N;
int dp[2011];
int prv[2011];

bool tar[1011];
bool cur[1011];

int calc(int a) {
    memset(dp, 0xc0, sizeof dp);
    dp[0] = 0;
    REP (i, N) {
	for (int j=1; j<a; j++) {
	    if (dp[i+j+1] < dp[i] + j) {
		dp[i+j+1] = dp[i] + j;
		prv[i+j+1] = i;
	    }
	}
    }

    return dp[N] - a + 1;
}

void query(VI v) {
    printf("%d", (int)v.size());
    REP (i, v.size()) printf(" %d", v[i]+1);
    printf("\n");
    fflush(stdout);

    EACH (e, v) cur[*e] = true;


    int x;
    scanf("%d", &x);
    x--;
    REP (i, v.size()) cur[(x+i)%N] = false;
}

void solve() {
    int ma = 0, a = 0;
    for (int b=1; b<N; b++) {
	int tmp = calc(b);
	if (ma < tmp) {
	    ma = tmp;
	    a = b;
	}
    }

    if (ma == 0) {
	puts("0");
	fflush(stdout);
    } else {
	calc(a);
	int x = N;
	memset(tar, 0, sizeof tar);
	memset(cur, 0, sizeof cur);
	while (x) {
	    for (int k=prv[x]; k<x-1; k++) tar[k] = true;
	    x = prv[x];
	}
	// eprintf("%d %d %d\n", N, ma, a);

	while (1) {
	    VI v;
	    REP (i, N) if (tar[i] && !cur[i]) {
		v.push_back(i);
	    }

	    if ((int)v.size() <= a) {
		REP (i, N) if (tar[i] && cur[i]) {
		    if ((int)v.size() == a) break;
		    v.push_back(i);
		}
		query(v);
		break;
	    } else {
		v.resize(a);
		query(v);
	    }
	}
	puts("0");
	fflush(stdout);
    }
}

void MAIN() {
    scanf("%d", &N);
    solve();
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}