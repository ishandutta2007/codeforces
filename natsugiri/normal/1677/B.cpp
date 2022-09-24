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
char S[1000011];
int X[1000011];
int ans[1000011];

void MAIN() {
    scanf("%d%d", &N, &M);
    scanf("%s", S);

#ifdef LOCAL
    N = 1000;
    M = 1000;
    REP (i, N*M) S[i] = '0' + rand() + 1;
#endif

    memset(X, 0, sizeof (int) * M);
    memset(ans, 0, sizeof (int) * (N*M));
    int cnt = 0;
    REP (i, N) {
	REP (j, M) {
	    if (S[i*M+j] == '1') {
		if (X[j] == 0) cnt++;
		X[j]++;
	    }
	    ans[i*M+j] += cnt;
	}
    }

    memset(X, 0, sizeof (int) * N * M);
    cnt = 0;
    REP (i, N*M) {
	if (S[i] == '1') {
	    cnt++;
	}
	if (i >= M && S[i-M] == '1') {
	    cnt--;
	}

	if (cnt) X[i]++;
	if (X[i]) {
	    ans[i] += X[i];
	    if (i+M < N*M) X[i+M] += X[i];
	}
    }
    rprintf("%d", ans, ans+N*M);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}