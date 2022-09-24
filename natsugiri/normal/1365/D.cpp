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

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int N, M;
char F[55][55];
bool D[55][55];

bool in(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%s", F[i]);

    REP (i, N) REP (j, M) if (F[i][j] == 'B') {
	REP (d, 4) {
	    int y = i + dy[d];
	    int x = j + dx[d];
	    if (in(y, x) && F[y][x] == '.') F[y][x] = '#';
	}
    }

    memset(D, 0, sizeof D);
    VI Y, X;
    if (F[N-1][M-1] != '#') {
	Y.push_back(N-1);
	X.push_back(M-1);
	D[N-1][M-1] = true;
    }
    while (!Y.empty()) {
	int y = Y.back(); Y.pop_back();
	int x = X.back(); X.pop_back();
	REP (d, 4) {
	    int yy = y + dy[d];
	    int xx = x + dx[d];
	    if (in(yy, xx) && F[yy][xx] != '#' && !D[yy][xx]) {
		D[yy][xx] = true;
		Y.push_back(yy);
		X.push_back(xx);
	    }
	}
    }

    bool yes = true;
    REP (i, N) REP (j, M) {
	if (F[i][j] == 'G' && !D[i][j]) yes = false;
	if (F[i][j] == 'B' && D[i][j]) yes = false;
    }

    puts(yes? "Yes": "No");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}