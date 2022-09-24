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

int Ax[4], Ay[4];
int Bx[4], By[4];


void MAIN() {
    REP (i, 4) scanf("%d%d", Ax+i, Ay+i);
    REP (i, 4) scanf("%d%d", Bx+i, By+i);

    REP (i, 4) {
	int x = Bx[i] + By[i];
	int y = Bx[i] - By[i];
	Bx[i] = x;
	By[i] = y;
    }

    int left, right, top, bottom;
    left = *min_element(Bx, Bx+4);
    right = *max_element(Bx, Bx+4);
    top = *max_element(By, By+4);
    bottom = *min_element(By, By+4);

    bool yes = false;
    int x_lo, x_hi,  y_lo, y_hi;
    x_lo = *min_element(Ax, Ax+4);
    x_hi = *max_element(Ax, Ax+4);
    y_lo = *min_element(Ay, Ay+4);
    y_hi = *max_element(Ay, Ay+4);


    for (int y=y_lo; y<=y_hi; y++) {
	for (int x=x_lo; x<=x_hi; x++) {
	    int kx = x + y;
	    int ky = x - y;

	    if (left <= kx && kx <= right
		    && bottom <= ky && ky <= top) {
		yes = true;
	    }
	}
    }

    puts(yes? "YES": "NO");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}