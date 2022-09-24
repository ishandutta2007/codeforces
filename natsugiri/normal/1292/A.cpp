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

int N, Q;
bool F[2][100011];

int X(int r, int c) {
    if (F[r][c]) {
	return (int)F[r^1][c-1] + (int)F[r^1][c] + (int)F[r^1][c+1];
    } else {
	return 0;
    }
}

void MAIN() {
    scanf("%d%d", &N, &Q);
    int cnt = 0;
    REP (i, Q) {
	int r, c;
	scanf("%d%d", &r, &c);
	r--;

	cnt -= X(r, c);
	F[r][c] = !F[r][c];
	cnt += X(r, c);
	
	puts(cnt? "No": "Yes");
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}