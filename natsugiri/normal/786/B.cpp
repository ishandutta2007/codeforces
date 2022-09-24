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


int N, Q, S;
LL len[400111];

vector<pair<int, LL> > G[400111];

void edge1(int v, int u, int c) {
    G[v].emplace_back(u, c);
}
void edge2(int v, int l, int r, int c) {
    l += N; r += N;
    for (; l < r; l>>=1, r>>=1) {
	if (l & 1) {
	    if (l >= N) G[v].emplace_back(l-N, c);
	    else G[v].emplace_back(l+N, c);
	    l++;
	}
	if (r & 1) {
	    r--;
	    if (r >= N) G[v].emplace_back(r-N, c);
	    else G[v].emplace_back(r+N, c);
	}
    }
}
void edge3(int l, int r, int v, int c) {
    l += N; r += N;
    for (; l < r; l>>=1, r>>=1) {
	if (l & 1) {
	    if (l >= N) G[l-N].emplace_back(v, c);
	    else G[l+N+N].emplace_back(v, c);
	    l++;
	}
	if (r & 1) {
	    r--;
	    if (r >= N) G[r-N].emplace_back(v, c);
	    else G[r+N+N].emplace_back(v, c);
	}
    }
}

int main() {
    scanf("%d%d%d", &N, &Q, &S);
    S--;
    REP (i, Q) {
	int t;
	int v, u, l, r, c;
	scanf("%d", &t);
	if (t == 1) {
	    scanf("%d%d%d", &v, &u, &c);
	    v--; u--;
	    edge1(v, u, c);
	} else if (t == 2) {
	    scanf("%d%d%d%d", &v, &l, &r, &c);
	    v--; l--;
	    edge2(v, l, r, c);
	} else if (t == 3) {
	    scanf("%d%d%d%d", &v, &l, &r, &c);
	    v--; l--;
	    edge3(l, r, v, c);
	}
    }

    for (int i=2; i<2*N; i++) {
	int v, u;
	v = i/2; u = i;
	if (N <= v) v -= N;
	else v += N;
	if (N <= u) u -= N;
	else u += N;
	G[v].emplace_back(u, 0);

	v = i/2; u = i;
	if (N <= v) v -= N;
	else v += N+N;
	if (N <= u) u -= N;
	else u += N+N;
	G[u].emplace_back(v, 0);
    }

    priority_queue<pair<LL, int> > pq;
    pq.emplace(0, S);
    memset(len, 0x3f, sizeof len);
    const LL INF = len[0];
    len[S] = 0;
    while (!pq.empty()) {
	pair<LL, int> p = pq.top(); pq.pop();
	int v = p.second;
	if (len[v] < -p.first) continue;
	EACH (e, G[v]) {
	    if (len[e->first] > len[v] + e->second) {
		len[e->first] = len[v] + e->second;
		pq.emplace(-len[e->first], e->first);
	    }
	}
    }

    REP (i, N) if (len[i] == INF) len[i] = -1;
    rprintf("%lld", len, len+N);
    return 0;
}