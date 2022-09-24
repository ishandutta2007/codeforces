#include<set>
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

int N, M, L;
LL A[100111];

void MAIN() {
    scanf("%d%d%d", &N, &M, &L);
    REP (i, N) scanf("%lld", A+i);
    set<int> se;
    REP (i, N) {
	if (A[i] > L && (i == 0 || A[i-1] <= L)) se.insert(i);
    }

    REP ($, M) {
	char op[11];
	scanf("%s", op);
	if (*op == '0') {
	    printf("%d\n", (int)se.size());
	} else {
	    int p, d;
	    scanf("%d%d", &p, &d);
	    p--;

	    if (A[p] <= L && A[p]+d > L) {
		if (p+1 < N && A[p+1] > L) {
		    se.erase(p+1);
		}
		if (p == 0 || A[p-1] <= L) {
		    se.insert(p);
		}
	    }
	    A[p] += d;
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}