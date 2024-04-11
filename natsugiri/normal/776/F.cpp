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

int N, M;

struct Edge {
    int to;
    int pos;
    Edge *rev;
    int use;
    int aux;
    Edge() {
	rev = NULL;
	use = -1;
    }
    Edge(int t_) : to(t_) {
	rev = NULL;
	use = -1;
	aux = 0;
    }
    bool operator<(const Edge &y) const {
	return aux < y.aux;
    }
};

struct CMP {
    bool operator()(Edge *x, Edge *y) const {
	return x->aux < y->aux;
    }
} cmp;

Edge E_pool[300111];
int e_cnt = 0;
Edge* new_edge(int to) {
    E_pool[e_cnt] = Edge(to);
    return &E_pool[e_cnt++]; 
}

vector<Edge*> G[100111];

int cnt = 0;
VI T[100111];
void add_edge(int x, int y) {
    T[x].push_back(y);
    T[y].push_back(x);
}

int node2idx[100111];
int ans[100111];

bool use[100111];
int sz[100111];
int par[100111];
int dp[100111];
void rec(int s, int depth) {
    // bfs
    VI ord;
    ord.push_back(s);
    par[s] = s;
    for (int i=0; i<(int)ord.size(); i++) {
	int v = ord[i];
	EACH (e, T[v]) if (!use[*e] && *e != par[v]) {
	    par[*e] = v;
	    ord.push_back(*e);
	}
    }
    // dp
    for (int i=ord.size(); i--; ){
	int v=  ord[i];
	sz[v] = 1;
	dp[v] = 1;
	EACH (e, T[v]) if (!use[*e] && *e != par[v]) {
	    sz[v] += sz[*e];
	    amax(dp[v], sz[*e]);
	}
    }

    int root = s;
    int m = ord.size();
    for (int i=0; i<(int)ord.size(); i++) {
	int v = ord[i];
	if (max(dp[v], m - sz[v]) < max(dp[root], m - sz[root])) {
	    root = v;
	}
    }

    use[root] = true;
    ans[node2idx[root]] = depth;

    EACH (e, T[root]) if (!use[*e]) {
	rec(*e, depth+1);
    }
}

int main() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	Edge *xe = new_edge(y);
	Edge *ye = new_edge(x);
	xe->rev = ye;
	ye->rev = xe;
	G[x].push_back(xe);
	G[y].push_back(ye);
    }

    REP (i, N) {
	Edge *xe = new_edge((i+1)%N);
	G[i].push_back(xe);

	EACH (e, G[i]) {
	    xe = *e;
	    if (xe->to < i) {
		xe->aux = -xe->to;
	    } else {
		xe->aux = N + N - xe->to;
	    }
	}
	sort(G[i].begin(), G[i].end(), cmp);
	REP (j, G[i].size()) {
	    G[i][j]->pos = j;
	}
    }

    vector<pair<VI, int> > vv;
    REP (i, N) EACH (e, G[i]) {
	Edge *xe = *e;
	if (xe->use == -1) {
	    Edge *f = xe;
	    VI v;
	    while (f->use == -1) {
		f->use = cnt;
		v.push_back(f->to);
		if (f->rev == NULL) {
		    f = G[f->to][0];
		} else {
		    if (f->rev->use != -1) {
			add_edge(f->rev->use, cnt);
		    }
		    f = G[f->to][f->rev->pos + 1];
		}
	    }

	    sort(v.rbegin(), v.rend());
	    vv.push_back(make_pair(v, cnt));
	    cnt++;
	}
    }

    sort(vv.begin(), vv.end());
    REP (i, cnt) node2idx[vv[i].second] = i;

    rec(0, 1);
//    eprintf("%d\n", cnt);
    rprintf("%d", ans, ans + cnt);

    return 0;
}