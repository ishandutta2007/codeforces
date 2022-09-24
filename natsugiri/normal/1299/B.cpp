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

int N;
LL X[100011], Y[100011];

bool judge() {
    if (N % 2) return false;

    int j = 1, a = N/2, b = N/2+1;
    REP (i, N) {
	LL dx = X[j] - X[i];
	LL dy = Y[j] - Y[i];
	LL ex = X[b] - X[a];
	LL ey = Y[b] - Y[a];

	if (dx != -ex) return false;
	if (dy != -ey) return false;
	j++;
	a++;
	b++;
	if (j >= N) j -= N;
	if (a >= N) a -= N;
	if (b >= N) b -= N;
    }
    return true;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld%lld", X+i, Y+i);

    puts(judge()? "YES": "NO");

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}