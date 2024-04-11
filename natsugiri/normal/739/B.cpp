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

const int MAXN = 200111;
int N;
int A[MAXN];
vector<pair<int, int> > G[MAXN];
int par[20][MAXN];
LL dist[MAXN];

int ans[MAXN];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    par[0][0] = 0;
    REP (i, N-1) {
	int p, w;
	scanf("%d%d", &p, &w);
	p--;
	par[0][i+1] = p;
	G[p].push_back(make_pair(i+1, w));
    }

    REP (t, 19) REP (v, N) par[t+1][v] = par[t][par[t][v]];
    VI ord;
    ord.reserve(N);
    ord.push_back(0);
    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) {
	    dist[e->first] = dist[v] + e->second;
	    ord.push_back(e->first);
	}
    }

    REP (i_, N) {
	int v = ord[N-1-i_];
	int x = v;
	for (int t=20; t--;) {
	    int p = par[t][x];
	    if (dist[v] - dist[p] <= A[v]) x = p;
	}

	if (v) {
	    ans[par[0][v]] += ans[v] + 1;
	}
	if (x) {
	    ans[par[0][x]]--;
	}
    }
    rprintf("%d", ans, ans+N);

    return 0;
}