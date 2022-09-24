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

int N, M;
int A[1011][1011];
bool in(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

struct Data {
    int sy, sx, dy, dx;
    LL dp[1011][1011];
    void build() {
	dp[sy][sx] = A[sy][sx];
	for (int y=sy; 0<=y && y<N; y+=dy) {
	    for (int x=sx; 0 <= x && x < M; x+=dx) {
		int yy, xx;
		yy = y - dy;
		xx = x;
		if (in(yy, xx)) amax(dp[y][x], dp[yy][xx] + A[y][x]);
		yy = y;
		xx = x - dx;
		if (in(yy, xx)) amax(dp[y][x], dp[yy][xx] + A[y][x]);
	    }
	}
    }
} D[4];

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) REP (j, M) scanf("%d", A[i]+j);

    D[0].sy = 0; D[0].sx = 0; D[0].dy = 1; D[0].dx = 1;
    D[1].sy = N-1; D[1].sx = M-1; D[1].dy = -1; D[1].dx = -1;
    D[2].sy = 0; D[2].sx = M-1; D[2].dy = 1; D[2].dx = -1;
    D[3].sy = N-1; D[3].sx = 0; D[3].dy = -1; D[3].dx = 1;

    REP (t, 4) D[t].build();

    LL ans = 0;
    for (int i=1; i<N-1; i++) for (int j=1; j<M-1; j++) {
	LL tmp;
	tmp = D[0].dp[i-1][j] + D[1].dp[i+1][j] + D[2].dp[i][j+1] + D[3].dp[i][j-1];
	amax(ans, tmp);
	tmp = D[0].dp[i][j-1] + D[1].dp[i][j+1] + D[2].dp[i-1][j] + D[3].dp[i+1][j];
	amax(ans, tmp);
    }

    printf("%lld\n", ans);
    return 0;
}