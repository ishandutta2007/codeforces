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
VI G[100111];
int par[100111], depth[100111];
int C[100111];

void MAIN() {
    scanf("%d", &N);
    REP (i, N-1) {
	int x;
	scanf("%d", &x);
	G[x-1].push_back(i+1);
    }

    VI ord;
    ord.reserve(N);
    ord.push_back(0);
    par[0] = 0;
    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) if (*e != par[v]) {
	    ord.push_back(*e);
	    par[*e] = v;
	    depth[*e] = depth[v] + 1;
	}
    }


    REP (i, N) C[depth[i]]++;
    int ans = 0;
    REP (i, N+1) ans += C[i] & 1;
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}