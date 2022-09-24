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

int H, W;
char F[511][511];
bool in(int y, int x) {
    return 0 <= y && y < H && 0 <= x && x < W;
}

bool solve() {
    REP (i, H) REP (j, W) if (F[i][j] == '*' && F[i+1][j] == '*' && F[i][j+1] == '*') {
	int sum = 1;
	REP (d, 4) {
	    int cnt = 0;
	    int y = i + dy[d];
	    int x = j + dx[d];
	    while (in(y, x) && F[y][x] == '*') {
		cnt++;
		y += dy[d];
		x += dx[d];
	    }
	    if (cnt == 0) return false;
	    sum += cnt;
	}
	REP (k, H) sum -= count(F[k], F[k]+W, '*');
	return sum == 0;
    }
    return false;
}

void MAIN() {
    scanf("%d%d", &H, &W);
    REP (i, H) scanf("%s", F[i]);
    puts(solve()? "YES": "NO");

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}