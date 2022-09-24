#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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

int N;
char S[5011];
int ans_x, ans_y;

void check(int oy, int ox) {
    int y = 0, x = 0;
    REP (i, N) {
	int ny = y, nx = x;
	if (S[i] == 'L') nx--;
	if (S[i] == 'R') nx++;
	if (S[i] == 'D') ny--;
	if (S[i] == 'U') ny++;
	if (ny != oy || nx != ox) {
	    y = ny;
	    x = nx;
	}
    }

    if (y == 0 && x == 0) {
	ans_x = ox;
	ans_y = oy;
    }
}

void MAIN() {
    scanf("%s", S);
    N = strlen(S);

    ans_x = 0;
    ans_y = 0;

    int y = 0, x = 0;
    REP (i, N) {
	if (S[i] == 'L') x--;
	if (S[i] == 'R') x++;
	if (S[i] == 'D') y--;
	if (S[i] == 'U') y++;
	if (x != 0 || y != 0) {
	    check(y, x);
	}
    }

    printf("%d %d\n", ans_x, ans_y);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}