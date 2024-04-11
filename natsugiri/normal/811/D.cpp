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
char F[111][111];
bool swapLR, swapUD;
void query(char dir, int &feedbackY, int &feedbackX) {
    if (swapLR && dir == 'L') dir = 'R';
    else if (swapLR && dir == 'R') dir = 'L';
    else if (swapUD && dir == 'D') dir = 'U';
    else if (swapUD && dir == 'U') dir = 'D';

    putchar(dir);
    putchar('\n');

    fflush(stdout);
    scanf("%d%d", &feedbackY, &feedbackX);
    feedbackY--;
    feedbackX--;
}


int L[111][111];
char J[111][111];
inline bool in(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
const char Dir[] = "LURD";

void bfs() {
    VI Y, X;
    memset(L, 0x3f, sizeof L);
    REP (i, N) REP (j, M) if (F[i][j] == 'F') {
	Y.push_back(i);
	X.push_back(j);
	L[i][j] = 0;
	break;
    }

    for (int i=0; i < (int)Y.size(); i++) {
	int y = Y[i], x = X[i];
	REP (d, 4) {
	    int yy = y + dy[d], xx = x + dx[d];
	    if (in(yy, xx) && F[yy][xx] != '*' && L[yy][xx] > L[y][x] + 1) {
		L[yy][xx] = L[y][x] +1;
		J[yy][xx] = Dir[d];
		Y.push_back(yy);
		X.push_back(xx);
	    }
	}
    }
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%s", F[i]);

    bfs();
//    REP (i, N) rprintf("%d", L[i], L[i] + M);
    int y = 0, x = 0;
    while (F[y][x] != 'F') {
//	eprintf("%d %d\n", y, x);
	if (y == 0 && J[y][x] == 'D') {
	    query('D', y, x);
	    if (y == 0) swapUD = true;
	} else if (x == 0 && J[y][x] == 'R') {
	    query('R', y, x);
	    if (x == 0) swapLR = true;
	} else {
	    query(J[y][x], y, x);
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}