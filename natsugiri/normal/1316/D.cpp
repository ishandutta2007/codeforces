#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
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

const int dy[] = {0,1,0,-1};
const int dx[] = {1,0,-1,0};
const char D[] = "LURD";

int N;
pair<int, int> P[1011][1011];
char F[1011][1011];

bool in(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) REP (j, N) {
	int r, c;
	scanf("%d%d", &r, &c);
	if (r >= 0) {
	    r--; 
	    c--;
	}
	P[i][j] = make_pair(r, c);
    }

    REP (i, N) REP (j, N) if (P[i][j] == make_pair(i, j)) {
	F[i][j] = 'X';
	vector<pair<int, int> > stk;
	stk.emplace_back(i, j);
	while (stk.size()) {
	    int r = stk.back().first;
	    int c = stk.back().second;
	    stk.pop_back();
	    REP (d, 4) {
		int y = r + dy[d];
		int x = c + dx[d];
		if (in(y, x) && !F[y][x] && P[y][x] == make_pair(i, j)) {
		    F[y][x] = D[d];
		    stk.emplace_back(y, x);
		}
	    }
	}
    }

    bool yes = true;

    REP (i, N) REP (j, N) {
	if (!F[i][j] && P[i][j].first >= 0) {
	    yes = false;
	}

	if (P[i][j].first < 0) {
	    REP (d, 4) {
		int y = i + dy[d];
		int x = j + dx[d];
		if (in(y, x) && P[y][x].first < 0) {
		    F[i][j] = D[d^2];
		    break;
		}
	    }
	}
    }

    if (yes) {
	REP (i, N) REP (j, N) if (!F[i][j]) yes = false;
    }
    if (yes) {
	puts("VALID");
	REP (i, N) puts(F[i]);
    } else {
	puts("INVALID");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}