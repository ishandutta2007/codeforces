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

void MAIN() {
    int N;
    scanf("%d", &N);
    if (N <= 2) {
	puts("1");
	puts("1 1");
    } else {
	int k = N / 3;
	vector<pair<int, int> > ans;
	if (N % 3 == 0) {
	    REP (i, k) {
		ans.emplace_back(k-i-1, i);
	    }
	    REP (i, k) {
		ans.emplace_back(k+k-2-i, i+k);
	    }
	} else {
	    REP (i, k) {
		// [k-1 .. 0] x [0 .. k-1];
		ans.emplace_back(k-i-1, i);
	    }
	    REP (i, k+1) {
		// [k+k .. k] x [k .. k+k]
		ans.emplace_back(k+k-i, i+k);
	    }
	}

	printf("%d\n", (int)ans.size());
	EACH (e, ans) printf("%d %d\n", e->first+1, e->second+1);

#ifdef LOCAL
	static char F[111][111];
	memset(F, '?', sizeof F);
	EACH (e, ans) F[e->first][e->second] = 'Q';

	REP (i, N) REP (j, N) if (F[i][j] == 'Q') {
	    REP (k, N) {
		if (F[i][k] == '?') F[i][k] = '.';
		if (F[k][j] == '?') F[k][j] = '.';
		int a = k-i+j;
		if (0 <= a && a < N && F[k][a] == '?') F[k][a] = '.';
	    }
	}

	int q = 0;
	REP (i, N) REP (j, N) if (F[i][j] == '?') q++;

	if (q == 0) {
	    REP (i, N) {
		F[i][N] = 0;
		puts(F[i]);
	    }
	    puts("");
	}
	REP (i, N) REP (j, N) {
	    bool ok = false;
	    EACH (e, ans) {
		if (e->first == i) { ok = true; break; }
		if (e->second == j) { ok = true; break; }
		if (e->first - e->second == i - j) { ok = true; break; }
	    }
	    assert(ok);
	}
#endif
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}