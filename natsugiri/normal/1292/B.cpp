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

LL Ax, Ay, Bx, By;
LL Xs, Ys, T;


LL X[111], Y[111];
int len;


void MAIN() {
    scanf("%lld%lld%lld%lld%lld%lld", X, Y, &Ax, &Ay, &Bx, &By);
    scanf("%lld%lld%lld", &Xs, &Ys, &T);

    len = 1;
    while (1) {
	X[len] = Ax * X[len-1] + Bx;
	Y[len] = Ay * Y[len-1] + By;
	len++;
	if ((X[len-1]-Xs) + (Y[len-1]-Ys) > T) break;
    }

    int ans = 0;
    REP (i, len) {
	LL rst = T - abs(X[i] - Xs) - abs(Y[i] - Ys);
	if (rst >= 0) {
	    // down;
	    int guess = 1;
	    for (int j=i-1; j>=0; j--) {
		rst -= abs(X[j] - X[j+1]) + abs(Y[j] - Y[j+1]);
		if (rst >= 0) {
		    guess++;
		} else {
		    break;
		}
	    }
	    amax(ans, guess);

	    // up;
	    guess = 1;
	    for (int j=i+1; j<len; j++) {
		rst -= abs(X[j] - X[j-1]) + abs(Y[j] - Y[j-1]);
		if (rst >= 0) {
		    guess++;
		} else {
		    break;
		}
	    }
	    amax(ans, guess);
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