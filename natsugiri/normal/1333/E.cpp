#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<random>

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

mt19937 engine;

int N;

int A[511][511];
int B[511][511];
int mark;
vector<pair<int, int> > P;

void gen() {
    if ((int)P.size() != N*N) {
	P.clear();
	REP (i, N) REP (j, N) P.emplace_back(i, j);
    }
    shuffle(P.begin(), P.end(), engine);
    REP (i, P.size()) A[P[i].first][P[i].second] = i+1;
}

const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};

const int INF = 1<<29;

bool in(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

int solve(int D) {
    mark++;
    int y = P[0].first, x = P[0].second;
    int idx = 0;
    int step = 1;
    int ret = 0;
    B[y][x] = mark;
    while (step < N*N) {
	int ny = -1, nx = -1;
	int val = INF;
	REP (d, D) {
	    for (int k=1; ; k++) {
		int yy = y + dy[d] * k;
		int xx = x + dx[d] * k;
		if (!in(yy, xx)) break;

		if (B[yy][xx] != mark && A[yy][xx] < val) {
		    ny = yy;
		    nx = xx;
		    val = A[yy][xx];
		}
	    }
	}

//	REP (i, N) {
//	    REP (j, N) {
//		if (B[i][j] == mark) eprintf(".. ");
//		else eprintf("%2d ", A[i][j]);
//	    }
//	    eprintf("\n");
//	}
//	eprintf("\n");

	if (val == INF) {
	    while (B[P[idx].first][P[idx].second] == mark) idx++;
	    y = P[idx].first;
	    x = P[idx].second;
	    ret++;
	} else {
	    y = ny;
	    x = nx;
	}

	B[y][x] = mark;
	step++;
    }

    return ret;
}

void F() {
    while (1) {
	gen();
	if (solve(4) < solve(8)) return;
    }
}



void MAIN() {
    scanf("%d", &N);
    if (N <= 2) {
	puts("-1");
	return;
    } else if (N <= 10) {
	F();
    } else if (N % 2) {
	int bk = N;
	N = 3;
	F();
	N = bk;

	REP (i, 3) REP (j, 3) A[i][j] += N * N - 9;
	int val = N*N-9;
	int y = N-1, x = 3;
	while (y > 3) {
	    while (x >= 0) A[y][x--] = val--;
	    y--;
	    x = 0;
	    while (x <= 3) A[y][x++] = val--;
	    y--;
	    x = 3;
	}
	while (y >= 0) A[y--][x] = val--;
	y = 0;
	x++;
	while (1) {
	    if (y >= N) break;
	    while (x < N) A[y][x++] = val--;
	    y++;
	    x--;
	    if (y >= N) break;
	    while (x >= 4) A[y][x--] = val--;
	    y++;
	    x++;
	}
    } else {
	int bk = N;
	N = 4;
	F();
	N = bk;

	REP (i, 4) REP (j, 4) A[i][j] += N * N - 16;
	int val = N*N-16;
	int y = N-1, x = 4;
	while (y > 4) {
	    while (x >= 0) A[y][x--] = val--;
	    y--;
	    x = 0;
	    while (x <= 4) A[y][x++] = val--;
	    y--;
	    x = 4;
	}
	while (y >= 0) A[y--][x] = val--;
	y = 0;
	x++;
	while (1) {
	    if (y >= N) break;
	    while (x < N) A[y][x++] = val--;
	    y++;
	    x--;
	    if (y >= N) break;
	    while (x >= 5) A[y][x--] = val--;
	    y++;
	    x++;
	}
    }

    REP (i, N) rprintf("%d", A[i], A[i]+N);
    //eprintf("%d %d\n", solve(4), solve(8));
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}