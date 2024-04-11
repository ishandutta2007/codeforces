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

LL X[100011], Y[100011];
bool use[100011];
VI idx;

bool check(int a, int b) {
    LL vx = X[b] - X[a];
    LL vy = Y[b] - Y[a];

    REP (i, N) {
	if (i == a || i == b) {
	    use[i] = true;
	} else {
	    LL wx = X[i] - X[a];
	    LL wy = Y[i] - Y[a];
	    use[i] = (vx * wy == vy * wx);
	}
    }

    int p = N, q = N;
    REP (i, N) if (!use[i]) {
	if (p == N) p = i;
	else if (q == N) q = i;
    }

    vx = X[q] - X[p];
    vy = Y[q] - Y[p];
    REP (i, N) if (!use[i]) {
	if (i == p || i == q) {
	} else {
	    LL wx = X[i] - X[p];
	    LL wy = Y[i] - Y[p];
	    if (vx * wy != vy * wx) {
		return false;
	    }
	}
    }
    return true;
}


void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld%lld", X+i, Y+i);


    bool yes = false;
    if (N <= 4) yes = true;
    if (!yes && check(0, 1)) yes = true;
    if (!yes && check(0, 2)) yes = true;
    if (!yes && check(1, 2)) yes = true;

    puts(yes? "YES": "NO");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}