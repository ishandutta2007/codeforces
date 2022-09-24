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

const double PI = acos(-1);

int N;
LL X[1111], Y[1111], R[1111];
VI G[1111];
int deg[1111];
int lv[1111];

inline LL sq(LL x) { return x * x; }


void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld%lld%lld", X+i, Y+i, R+i);

    REP (i, N) REP (j, N) {
	if (i == j) continue;
	if (R[i] > R[j] && R[i] * R[i] >= sq(X[i] - X[j]) + sq(Y[i] - Y[j])) {
	    G[i].push_back(j);
	    deg[j]++;
	}
    }

    VI ord;
    ord.reserve(N);
    REP (i, N) if (deg[i] == 0) ord.push_back(i);
    REP (i, N) {
	int v = ord[i];
	EACH (e, G[v]) {
	    deg[*e]--;
	    lv[*e] = lv[v] + 1;
	    if (deg[*e] == 0) ord.push_back(*e);
	}
    }


    LL ans = 0;
    REP (i, N) {
	if (lv[i] == 0 || (lv[i] & 1)) ans += R[i] * R[i];
	else ans -= R[i] * R[i];
    }

    printf("%.12f\n", ans * PI);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}