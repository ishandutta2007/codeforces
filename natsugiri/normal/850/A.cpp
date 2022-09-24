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

const int LIMIT = 60;
int N;
LL P[1011][5];


void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	REP (j, 5) scanf("%lld", P[i]+j);
    }

    VI ans;
    REP (i, N) {
	bool yes = true;
	REP (a, min(N, LIMIT)) if (a != i) {
	    REP (b, a) if (b != i) {
		LL nu = 0;
		REP (t, 5) {
		    nu += (P[a][t] - P[i][t]) * (P[b][t] - P[i][t]);
		}
		if (nu > 0) {
		    yes = false;
		    break;
		}
	    }
	    if (!yes) break;
	}
	if (yes) ans.push_back(i+1);
    }

    printf("%d\n", (int)ans.size());
    EACH (e, ans) printf("%d\n", *e);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}