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

const int MAXN = 100011;
int N;
VI G[MAXN];
int par[MAXN], sz[MAXN];
VI ord;

void MAIN() {
    scanf("%d", &N);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }


    if (N & 1) {
	puts("-1");
	return;
    }

    ord.reserve(N);
    ord.push_back(0);

    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) if (*e != par[v]) {
	    par[*e] = v;
	    ord.push_back(*e);
	}
    }

    REP (i_, N) {
	int v = ord[N-1-i_];
	sz[v] = 1;
	EACH (e, G[v]) if (*e != par[v]) {
	    sz[v] += sz[*e];
	}
    }

    int ans = 0;

    REP (i, N) if (sz[i] % 2 == 0) ans++;

    ans--;
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}