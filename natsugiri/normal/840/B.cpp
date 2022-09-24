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

const int MAXN = 300111;

int N, M;
int D[MAXN];
vector<pair<int, int> > G[MAXN];
vector<pair<int, int> > H[MAXN];
int par[MAXN];
int act[MAXN];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", D+i);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].emplace_back(y, i);
	G[y].emplace_back(x, i);
    }

    int cnt = count(D, D+N, 1);
    if (cnt % 2 == 1 && count(D, D+N, -1) == 0) {
	puts("-1");
	return;
    }

    if (cnt % 2 == 1) {
	*find(D, D+N, -1) = 1;
    }

    VI ord; ord.reserve(N);
    memset(par, -1, sizeof par);
    ord.push_back(0);
    par[0] = 0;
    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) if (par[e->first] == -1) {
	    par[e->first] = v;
	    H[v].push_back(*e);
	    ord.push_back(e->first);
	}
    }


    VI ans;
    REP (i_, N) {
	int v = ord[N-1-i_];
	if (D[v] == 1) act[v] = 1;

	EACH (e, H[v]) {
	    if (act[e->first]) {
		ans.push_back(e->second);
		act[v]++;
	    }
	}

	act[v] &= 1;
    }

    printf("%d\n", (int)ans.size());
    EACH (e, ans) printf("%d\n", *e+1);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}