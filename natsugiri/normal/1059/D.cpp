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

int N;
int X[100011], Y[100011];

bool possible() {
    int pos = 0, neg = 0;
    REP (i, N) {
	if (Y[i] > 0) pos++;
	if (Y[i] < 0) {
	    neg++;
	    Y[i] = -Y[i];
	}
    }
    return pos == 0 || neg == 0;
}

long double sq(long double x) { return x*x; }

bool ok(double mid) {
    vector<pair<double, int> > S; S.reserve(N*2);
    REP (i, N) {
	if (Y[i] > mid*2) return false;
	double d = abs(Y[i] - mid);
//	double w = sqrt(max(0.0, sq(mid) - sq(d)));
	double w = sqrt(max(0.0L, 1.0L - sq(d/mid)))*mid;
	// (X[i]-w, X[i]+w);
	
	S.emplace_back(X[i]-w, -1);
	S.emplace_back(X[i]+w, 1);
    }

    sort(S.begin(), S.end());
    int cnt = 0;
    REP (i, N*2) {
	cnt += S[i].second;
	if (cnt == -N) return true;
    }
    return false;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d%d", X+i, Y+i);
//#ifdef LOCAL
//    N = 100000;
//    REP (i, N) {
//	X[i] = rand() % 10000000;
//	Y[i] = rand() % 10000000;
//    }
//#endif

    if (possible()) {
	double lo = 0, hi = 1.0;
	while (!ok(hi)) {
	    lo = hi;
	    hi += hi;
	}
	REP (i, 50) {
	    double mid = (lo + hi) / 2;
	    (ok(mid)? hi: lo) = mid;
	}
	printf("%.12f\n", hi);
//	eprintf("%.12f\n", lo);
//	eprintf("%.12f\n", (hi-lo)/lo);
    } else {
	puts("-1");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}