#include<random>
#include<cmath>
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

mt19937 engine;

const LL ABS = 1500000;
const LL NORM = ABS * ABS;

LL norm(LL x, LL y) {
    return x * x + y * y;
}

bool in_13(LL x, LL y) {
    return (0 <= x && 0 <= y) || (x <= 0 && y <= 0);
}
bool in_24(LL x, LL y) {
    return (0 <= x && y <= 0) || (x <= 0 && 0 <= y);
}

int N;

struct Point {
    LL x, y;
    int i;
} P[100011];

struct Data {
    LL x, y;
    int c;
    int p;
    LL norm() { return ::norm(x, y); }
};
Data d[100011][2];

int ans[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	int x, y;
	scanf("%d%d", &x, &y);
	P[i].x = x;
	P[i].y = y;
	P[i].i = i;
    }

    while (1) {

	REP (t, 2) d[0][t].x = d[0][t].y = 0;

	REP (i, N) {
	    REP (t, 2) d[i+1][t].p = -1;

	    REP (t, 2) if (d[i][t].p != -1) {
		for (int sgn=-1; sgn<=1; sgn+=2) {
		    LL x = d[i][t].x + sgn * P[i].x;
		    LL y = d[i][t].y + sgn * P[i].y;

		    if (in_13(x, y)) {
			if (d[i+1][0].p == -1 || norm(x, y) < d[i+1][0].norm()) {
			    d[i+1][0].x = x;
			    d[i+1][0].y = y;
			    d[i+1][0].c = sgn;
			    d[i+1][0].p = t;
			}
		    }
		    if (in_24(x, y)) {
			if (d[i+1][1].p == -1 || norm(x, y) < d[i+1][1].norm()) {
			    d[i+1][1].x = x;
			    d[i+1][1].y = y;
			    d[i+1][1].c = sgn;
			    d[i+1][1].p = t;
			}
		    }
		}
	    }
	}

	REP (t, 2) if (d[N][t].p != -1) {
	    if (d[N][t].norm() <= NORM) {
		int cur = t;
		for (int i=N-1; i>=0; i--) {
		    ans[P[i].i] = d[i+1][cur].c;
		    cur = d[i+1][cur].p;
		}

		rprintf("%d", ans, ans+N);
//		{
//		    LL sx = 0, sy = 0;
//		    REP (i, N) {
//			sx += P[i].x * ans[P[i].i];
//			sy += P[i].y * ans[P[i].i];
//		    }
//		    eprintf("%lld\n", norm(sx, sy));
//		}
		return;
	    }
	}

	shuffle(P, P+N, engine);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}