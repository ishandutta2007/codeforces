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

int N, K;
int C[200111];
int sz[200111];
VI G[200111];

int main() {
    scanf("%d%d", &N, &K);
    REP (i, K * 2) {
	int a;
	scanf("%d", &a);
	a--;
	C[a]++;
    }

    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    VI ord; ord.reserve(N);
    ord.push_back(0);
    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) {
	    G[*e].erase(remove(G[*e].begin(), G[*e].end(), v), G[*e].end());
	    ord.push_back(*e);
	}
    }

    LL ans = 0;
    REP (i_, N) {
	int v = ord[N-1-i_];
	sz[v] = C[v];
	EACH (e, G[v]) {
	    sz[v] += sz[*e];
	}
	
	if (v) {
	    ans += min(sz[v], 2 * K - sz[v]);
	}
    }

    printf("%lld\n", ans);

    return 0;
}