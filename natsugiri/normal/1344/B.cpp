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

int N, M;
char F[1011][1011];
bool use[1011][1011];

bool split() {
    REP (i, N) {
	int j = 0;
	while (j < M && F[i][j] == '.') j++;
	if (j == M) continue;
	while (j < M && F[i][j] == '#') j++;
	if (j == M) continue;
	while (j < M && F[i][j] == '.') j++;
	if (j == M) continue;
	return true;
    }

    REP (j, M) {
	int i = 0;
	while (i < N && F[i][j] == '.') i++;
	if (i == N) continue;
	while (i < N && F[i][j] == '#') i++;
	if (i == N) continue;
	while (i < N && F[i][j] == '.') i++;
	if (i == N) continue;
	return true;
    }

    return false;
}

bool white_row() {
    REP (i, N) {
	if (count(F[i], F[i]+M, '#') == 0) return true;
    }
    return false;
}
bool white_col() {
    REP (j, M) {
	int cnt = 0;
	REP (i, N) if (F[i][j] == '#') cnt++;
	if (cnt == 0) return true;
    }
    return false;
}

bool in(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%s", F[i]);

    int ans = 0;
    if (split()) {
	ans = -1;
    } else if ((white_row()? 1: 0) + (white_col()? 1: 0) == 1) {
	ans = -1;
    } else {
	REP (i, N) REP (j, M) if (F[i][j] == '#' && !use[i][j]) {
	    ans++;
	    vector<pair<int, int> > stk;
	    use[i][j] = true;
	    stk.emplace_back(i, j);
	    while (!stk.empty()) {
		int y = stk.back().first;
		int x = stk.back().second;
		stk.pop_back();
		REP (d, 4) {
		    int yy = y + dy[d];
		    int xx = x + dx[d];
		    if (in(yy, xx) && F[yy][xx] == '#' && !use[yy][xx]) {
			use[yy][xx] = true;
			stk.emplace_back(yy, xx);
		    }
		}
	    }
	}
    }


    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}