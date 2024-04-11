#include<queue>
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
VI G[200111];
int A[200111];
int C[200111];
int par[200111], sz[200111], dp[200111];
VI ver[200111];
VI ord;
vector<pair<int, int> > ans;

int main() {
    scanf("%d%d", &N, &K);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }
    REP (i, 2 * K) {
	scanf("%d", A+i);
	A[i]--;
	C[A[i]] = 1;
    }

    ord.reserve(N);
    ord.push_back(0);
    par[0] = -1;
    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) if (*e != par[v]) {
	    ord.push_back(*e);
	    par[*e] = v;
	}
    }
    REP (i_, N) {
	int v = ord[N-1-i_];
	sz[v] = C[v];
	dp[v] = 0;
	EACH (e, G[v]) if (*e != par[v]) {
	    sz[v] += sz[*e];
	    amax(dp[v], sz[*e]);
	}
    }

    int centre = 0;
    int best = N + 1;
    REP (i, N) {
	int tmp = max(dp[i], 2 * K - sz[i]);
	if (tmp < best) {
	    centre = i;
	    best = tmp;
	}
    }

    ord.clear(); ord.reserve(N);
    ord.push_back(centre);
    memset(par, -1, sizeof par);
    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) if (*e != par[v]) {
	    ord.push_back(*e);
	    par[*e] = v;
	}
    }
    REP (i_, N-1) {
	int v = ord[N-1-i_];
	if (C[v]) ver[v].push_back(v);
	EACH (e, G[v]) if (*e != par[v]) {
	    if (ver[v].size() < ver[*e].size()) swap(ver[v], ver[*e]);
	    ver[v].insert(ver[v].end(), ver[*e].begin(), ver[*e].end());
	    ver[*e] = VI();
	}
    }


    if (C[centre]) ver[centre].push_back(centre);
    priority_queue<pair<int, int> > Q;
    REP (i, N) if (ver[i].size()) Q.push(make_pair(ver[i].size(), i));
    while (!Q.empty()) {
	pair<int, int> a = Q.top(); Q.pop();
	pair<int, int> b = Q.top(); Q.pop();
	ans.push_back(make_pair(ver[a.second].back(), ver[b.second].back()));
	ver[a.second].pop_back();
	ver[b.second].pop_back();
	a.first--; b.first--;
	if (a.first) Q.push(a);
	if (b.first) Q.push(b);
    }

    printf("1\n%d\n", centre+1);
    REP (i, K) printf("%d %d %d\n", ans[i].first+1, ans[i].second+1, centre+1);

    return 0;
}