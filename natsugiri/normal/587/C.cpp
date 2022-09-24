#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

int N, M, Q;
VI G[100011], P[100011];

VI add(VI a, const VI &b) {
    a.insert(a.end(), b.begin(), b.end());
    sort(a.begin(), a.end());
    if (a.size() > 10u) a.resize(10);
    return a;
}

int per[100011][20];
int dep[100011];
VI me[100011][20];

VI peo;
int lca(int v, int w) {
    if (dep[v] > dep[w]) swap(v, w);
    for (int i=0; i<20; i++) {
	if ((dep[w] - dep[v]) & (1<<i)) {
	    peo = add(peo, me[w][i]);
	    w = per[w][i];
	}
    }
    if (w == v) {
	peo = add(peo, me[w][0]);
	return w;
    }

    for (int i=19; i>=0; i--) {
	if (per[w][i] != per[v][i]) {
	    peo = add(peo, me[w][i]);
	    peo = add(peo, me[v][i]);
	    w = per[w][i];
	    v = per[v][i];
	}
    }
    peo = add(peo, me[v][0]);
    peo = add(peo, me[w][1]);
    return per[v][0];
}

int main() {
    scanf("%d%d%d", &N, &M, &Q);
    REP (i, N-1) {
	int v, w;
	scanf("%d%d", &v, &w);
	v--; w--;
	G[v].push_back(w);
	G[w].push_back(v);
    }
    REP (i, M) {
	int c;
	scanf("%d", &c);
	c--;
	P[c].push_back(i);
    }
    REP (i, N) {
	sort(P[i].begin(), P[i].end());
	if (P[i].size() > 10u) P[i].resize(10);
    }

    VI ord;
    // memset(per, -1, sizeof per);
    ord.reserve(0);
    ord.push_back(0);
    per[0][0] = 0;

    REP (i, N) {
	int v = ord[i];
	me[v][0] = P[v];
	
	EACH (e, G[v]) if (*e != per[v][0]) {
	    dep[*e] = dep[v] + 1;
	    per[*e][0] = v;
	    ord.push_back(*e);
	}
    }


    REP (t, 19) REP (v, N) {
	per[v][t+1] = per[per[v][t]][t];
	me[v][t+1] = add(me[v][t], me[per[v][t]][t]);
    }

    REP ($, Q) {
	int v, w, a;
	scanf("%d%d%d", &v, &w, &a);
	v--;w--;
	peo.clear();
	int z = lca(v, w);

	if ((int)peo.size() > a) peo.resize(a);

	printf("%d", (int)peo.size());
	REP (i, peo.size()) printf(" %d", peo[i]+1);
	puts("");
    }
    return 0;
}