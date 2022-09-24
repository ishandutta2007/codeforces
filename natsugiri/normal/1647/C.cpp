#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<tuple>

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

int N, M;
char F[111][111];
char C[111][111];

using Tuple = tuple<int, int, int, int>;
vector<Tuple> ans;

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%s", F[i]);

    if (F[0][0] == '1') {
	puts("-1");
    } else {
	ans.clear();
	REP (i, N) REP (j, M) C[i][j] = '0';

	for (int i=N; i--; ) for (int j=M; j--;) if (F[i][j] != C[i][j]) {
	    if (F[i][j] == '0') {
		ans.emplace_back(i, j, i, j);
		C[i][j] = '0';
	    } else if (j) {
		ans.emplace_back(i, j-1, i, j);
		C[i][j] = '1';
		C[i][j-1] = '0';
	    } else {
		assert(i);
		ans.emplace_back(i-1, j, i, j);
		C[i][j] = '1';
		C[i-1][j] = '0';
	    }
	}

	printf("%d\n", (int)ans.size());
	EACH (e, ans) {
	    int a, b, c, d;
	    tie(a, b, c, d) = *e;
	    printf("%d %d %d %d\n", a+1, b+1, c+1, d+1);
	}
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}