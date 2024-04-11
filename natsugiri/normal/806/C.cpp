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
LL A[100111];

int P[111];
int C[111];
int sumsC[111];

void MAIN() {
    assert(39LL == __lg(1000000000000LL));

    scanf("%d", &N);
    REP (i, N) scanf("%lld", A+i);

    REP (i, N) {
	int k = __lg(A[i]);
	if ((1LL << k) == A[i]) {
	    P[k]++;
	    C[k]++;
	} else {
	    C[k+1]++;
	}
    }

    REP (t, 64) sumsC[t+1] = sumsC[t] + C[t];

    VI ans;
    for (int i=1; i<=P[0]; i++) {
	int used = 0, slot = i;

	for (int j=0; j<=45; j++) {
	    int g = min(slot, P[j]);
	    int h = min(slot - g, sumsC[j+1] - g - used);
	    slot = g;
	    used += g + h;
	}

	if (used == N) ans.push_back(i);
    }

    if (ans.empty()) {
	puts("-1");
    } else {
	rprintf("%d", ans.begin(), ans.end());
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}