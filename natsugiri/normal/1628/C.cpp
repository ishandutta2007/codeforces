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


const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};

int N;
int F[1011][1011];
int A[1011][1011];

bool in(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) REP (j, N) scanf("%d", &F[i][j]);

    REP (i, N) REP (j, N) A[i][j] = 0;

    REP (i, N-1) {
	REP (j, N) {
	    int tmp = F[i][j];
	    REP (d, 3) {
		int y = i + dy[d];
		int x = j + dx[d];
		if (in(y, x)) tmp ^= A[y][x];
	    }
	    A[i+1][j] = tmp;
	}
    }


    int ans = 0;
    REP (i, N) REP (j, N) ans ^= A[i][j];
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}