#include<tuple>
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
using Tuple = tuple<int, int, int>;
Tuple X[100111];
int ans[100111];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	int l, r;
	scanf("%d%d", &l, &r);
	X[i] = Tuple(l, r, i);
    }

    sort(X, X+N);

    REP (i, N) ans[i] = 2;

    bool yes = false;
    int ma = -1;
    REP (i, N) {
	int l, r, idx;
	tie(l, r, idx) = X[i];
	if (i && ma < l) {
	    yes = true;
	    break;
	} 
	ans[idx] = 1;
	amax(ma, r);
    }

    if (yes) {
	rprintf("%d", ans, ans+N);
    } else {
	puts("-1");
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}