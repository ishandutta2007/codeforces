#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<map>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

struct UnionFind {
    int n, cc, *u;
    UnionFind() : n(0), cc(0), u(NULL) {}
    UnionFind(int n_) : n(n_), cc(n_) {
	u = new int[n_];
	memset(u, -1, sizeof (int) * n);
    }
    UnionFind(const UnionFind &y) : n(y.n), cc(y.cc) {
	u = new int[y.n];
	memcpy(u, y.u, sizeof (int) * n);
    }
    ~UnionFind() {
	delete[] u; u = NULL;
	n = cc = 0;
    }
    friend void swap(UnionFind &x, UnionFind &y) {
	swap(x.n, y.n); swap(x.cc, y.cc); swap(x.u, y.u);
    }
    UnionFind& operator=(UnionFind y) { 
	swap(*this, y);
	return *this;
    }
    int root(int x) {
	int y = x, t;
	while (u[y] >= 0) y = u[y];
	while (x != y) { t = u[x]; u[x] = y; x = t; }
	return y;
    }
    bool link(int x, int y) {
	x = root(x); y = root(y);
	if (x == y) return false;
	if (u[y] < u[x]) swap(x, y);
	u[x] += u[y]; u[y] = x; cc--;
	return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int count_node(int x) { return -u[root(x)]; }
    int count_tree() { return cc; }
};
int N;
map<pair<LL, LL>, int> mp;

int get(LL a, LL b, LL c, LL d) {
    // (a/b, c/d);
    LL x = a*d, y = c*b;
    LL g = __gcd(x, y);
    x /= g;
    y /= g;

    pair<LL, LL> key(x, y);
    auto it = mp.find(key);
    if (it == mp.end()) {
	int sz = mp.size();
	mp.emplace(key, sz);
	return sz;
    } else {
	return it->second;
    }
}

VI G[400011];
int X[200011];
int Y[200011];
bool vis[400011];

vector<pair<int, int> > ans;

VI B[400011];
int save[400011];
int par[400011];


void MAIN() {
    scanf("%d", &N);


    REP (i, N) {
	LL a, b, c, d;
	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);

	int x = get(a+b, b, c, d);
	int y = get(a, b, c+d, d);
	X[i] = x;
	Y[i] = y;
    }

    UnionFind U(mp.size());
    REP (i, N) {
	int x = X[i];
	int y = Y[i];

	if (U.same(x, y)) {
	    B[x].push_back(i);

	} else {
	    G[x].push_back(i);
	    G[y].push_back(i);
	    U.link(x, y);
	}
    }

    VI que;

    REP (i, mp.size()) if (!vis[i]) {
	que.clear();
	par[i] = i;
	vis[i] = true;
	que.push_back(i);

	for (int j=0; j<(int)que.size(); j++) {
	    int v = que[j];
	    EACH (e, G[v]) {
		int w = v ^ X[*e] ^ Y[*e];
		if (w == par[v]) continue;
		que.push_back(w);
		par[w] = v;
		vis[w] = true;
	    }
	}

	for (int j=que.size(); j--;) {
	    int v = que[j];
	    save[v] = -1;
	    EACH (e, G[v]) {
		int w = v ^ X[*e] ^ Y[*e];
		if (w == par[v]) continue;
		
		if (save[w] != -1) {
		    ans.emplace_back(*e, save[w]);
		    save[w] = -1;
		} else if (save[v] != -1) {
		    ans.emplace_back(save[v], *e);
		    save[v] = -1;
		} else {
		    save[v] = *e;
		}
	    }

	    EACH (e, B[v]) {
		if (save[v] != -1) {
		    ans.emplace_back(save[v], *e);
		    save[v] = -1;
		} else {
		    save[v] = *e;
		}
	    }
	}

	//rprintf("%d", que.begin(), que.end());
    }

    printf("%d\n", (int)ans.size());
    EACH (e, ans) {
	printf("%d %d\n", e->first+1, e->second+1);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}