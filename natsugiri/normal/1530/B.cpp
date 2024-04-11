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

const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};

int H, W;
bool in(int y, int x) {
    return 0 <= y && y < H && 0 <= x && x < W;
}

char S[33][33];

void put(int y, int x) {
    REP (d, 8) {
	int yy = y + dy[d];
	int xx = x + dx[d];
	if (in(yy, xx) && S[yy][xx] == '1') return;
    }

    S[y][x] = '1';
}

void MAIN() {
    scanf("%d%d", &H, &W);
    memset(S, '0', sizeof S);

    REP (y, H-1) put(y, 0);
    REP (x, W-1) put(H-1, x);
    for (int y=H-1; y>=1; y--) put(y, W-1);
    for (int x=W-1; x>=1; x--) put(0, x);

    REP (i, H) {
	S[i][W] = 0;
	puts(S[i]);
    }
    puts("");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}