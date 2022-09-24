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
vector<pair<int, int> > G[100011];

int depth[100011];
LL dist[100011];
int par[100011];
VI ord;
int bfs(int s) {
    memset(par, -1, sizeof par);
    dist[s] = 0;
    depth[s] = 0;
    par[s] = s;
    ord.clear();
    ord.push_back(s);
    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) if (par[e->first] == -1) {
	    depth[e->first] = depth[v] + 1;
	    dist[e->first] = dist[v] + e->second;
	    par[e->first] = v;
	    ord.push_back(e->first);
	}
    }

    return max_element(dist, dist + N) - dist;
}

int root, leaf;
int cur, nxt;
bool ok(LL mid) {
    cur = leaf;
    while (cur != root && dist[leaf]-dist[par[cur]] <= mid) cur = par[cur];
    nxt = cur;
    while (nxt != root && dist[nxt] > mid) nxt = par[nxt];

    int t = depth[cur] - depth[nxt] + 1;
    return t <= K;
}

LL bfs2(LL hi) {
    ok(hi);
    ord.clear();
    int x = cur;
    while (1) {
	ord.push_back(x);
	if (x == nxt) break;
	x = par[x];
    }
    memset(par, -1, sizeof par);

    EACH (e, ord) {
	par[*e] = *e;
	dist[*e] = 0;
    }

    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) if (par[e->first] == -1) {
	    dist[e->first] = dist[v] + e->second;
	    par[e->first] = v;
	    ord.push_back(e->first);
	}
    }

    return *max_element(dist, dist + N);
}

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N-1) {
	int x, y, w;
	scanf("%d%d%d", &x, &y, &w);
	x--; y--;
	G[x].emplace_back(y, w);
	G[y].emplace_back(x, w);
    }

    root = bfs(0);
    leaf = bfs(root);

    LL lo = -1, hi = dist[leaf];
    while (hi - lo > 1) {
	LL mid = (lo + hi) / 2;
	(ok(mid)? hi: lo) = mid;
    }

    LL ans = bfs2(hi);

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}