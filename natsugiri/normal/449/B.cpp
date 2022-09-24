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

int N, M, K;
struct Edge {
    int dst;
    LL cst;
    bool train;
    bool operator<(const Edge &y) const {
	return y.cst < cst;
    }
};
vector<Edge> G[100111];

LL len[100111];
int cnt[100111][2];

int main() {
    scanf("%d%d%d", &N, &M, &K);
    REP (i, M) {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	a--; b--;
	G[a].push_back((Edge){ b, c, false});
	G[b].push_back((Edge){ a, c, false});
    }


    REP (i, K) {
	int a, c;
	scanf("%d%d", &a, &c);
	a--;

	G[0].push_back((Edge){a, c, true});
    }

    priority_queue<Edge> Q;
    memset(len, 0x3f, sizeof len);
    Q.push((Edge){ 0, 0, false });
    len[0] = 0;

    while (!Q.empty()) {
	Edge e = Q.top(); Q.pop();
	if (e.cst > len[e.dst]) continue;
	EACH (f, G[e.dst]) if (len[f->dst] > e.cst + f->cst) {
	    len[f->dst] = e.cst + f->cst;
	    Q.push((Edge){ f->dst, len[f->dst], false });
	}
    }

    int ans = 0;
    REP (v, N) EACH (e, G[v]) {
	if (len[v] + e->cst == len[e->dst]) {
	    cnt[e->dst][e->train]++;
	} else if (e->train) {
	    ans++;
	}
    }

    REP (v, N) {
	if (cnt[v][0] > 0) ans += cnt[v][1];
	else if (cnt[v][1]) ans += cnt[v][1] - 1;
    }

    printf("%d\n", ans);

    return 0;
}