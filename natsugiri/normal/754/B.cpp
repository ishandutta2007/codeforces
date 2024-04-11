#include<assert.h>
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

int N;
char F[9][9];

bool check(char a, char b, char c, char me) {
    char s[] = {a, b, c};
    int m = 0, h = 0;
    REP (i, 3) {
	if (s[i] == '.') h++;
	if (s[i] == me) m++;
    }
    return m == 2 && h == 1;
}

void solve(char me) {
    bool yes = false;
    REP (i, 4) {
	yes |= check(F[i][0], F[i][1], F[i][2], me);
	yes |= check(F[i][1], F[i][2], F[i][3], me);
	yes |= check(F[0][i], F[1][i], F[2][i], me);
	yes |= check(F[1][i], F[2][i], F[3][i], me);
    }
    REP (i, 2) REP (j, 2) {
	yes |= check(F[i][j], F[i+1][j+1], F[i+2][j+2], me);
	yes |= check(F[i][3-j], F[i+1][2-j], F[i+2][1-j], me);
    }

    puts(yes? "YES" : "NO");
}

int main() {
    REP (i, 4) scanf("%s", F[i]);

    int o = 0, x = 0;
    REP (i, 4) REP (j, 4) {
	if (F[i][j] == 'o') o++;
	if (F[i][j] == 'x') x++;
    }

    if (o == x) solve('x');
    else if (o + 1 == x) solve('o');
    else assert(false);

    return 0;
}