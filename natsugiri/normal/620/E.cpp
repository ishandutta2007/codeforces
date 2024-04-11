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

typedef vector<VI> Adj;


struct TreeDFS {
    vector<int> subtree_size, parent, depth;
    vector<int> preorder, postorder, postorder_size;
    vector<int> ett_in, ett_out;
    TreeDFS(const Adj &T, int r=0) {
	int n = T.size();
	subtree_size = parent = depth = vector<int>(n);
	postorder_size = vector<int>(n);
	ett_in = ett_out = vector<int>(n);
	dfs(T, r, -1);
    }
    void dfs(const Adj &T, int v, int p) {
	parent[v] = p;
	ett_in[v] = preorder.size();
	preorder.push_back(v);
	postorder_size[v] = postorder.size();
	subtree_size[v] = 1;
	for (int i=0; i<(int)T[v].size(); i++) {
	    if (T[v][i] == p) continue;
	    depth[T[v][i]] = depth[v]+1;
	    dfs(T, T[v][i], v);
	    subtree_size[v] += subtree_size[T[v][i]];
	}
	ett_out[v] = postorder.size();
	postorder.push_back(v);
    }
};	


struct Seg {
    LL val;
    LL lazy;
    explicit Seg(LL val_=0): val(val_), lazy(0) {}
};
const Seg unit = Seg();
Seg operator+(const Seg &x, const Seg &y) {
    Seg z;
    z.val = x.val | y.val;
    z.lazy = 0;
    return z;
};

struct SegmentTree {
    int n, m;
    vector<Seg> d;
    SegmentTree(int n): n(n) {
	m=1;
	for (;m<n;) m*=2;
	d = vector<Seg>(m*2);
    }
    void modify(int x, const LL &s) {
	x += m;
	d[x].val = s; d[x].lazy = 0;
	for (x/=2; x; x/=2) d[x] = d[x*2] + d[x*2+1];
    }
    void force(int k) {
	if (k < m && d[k].lazy) {
	    d[2*k].val = d[2*k].lazy = d[2*k+1].val = d[2*k+1].lazy = d[k].val = d[k].lazy;
	    d[k].lazy = 0;
	}
    }
    void set(int x, int y, LL v) { set(x, y, v, 1, 0, m); }
    void set(int x, int y, LL v, int k, int l, int r) {
	force(k);
	if (r<=x || y<=l) return ;
	if (x<=l && r<=y) { d[k].val = d[k].lazy = v; return ;  }
	set(x, y, v, k*2, l, (l+r)/2);
	set(x, y, v, k*2+1, (l+r)/2, r);
	d[k] = d[k*2] + d[k*2+1];
    }
    Seg query(int x, int y) { return query(x, y, 1, 0, m); }
    Seg query(int x, int y, int k, int l, int r) {
	force(k);
	if (r<=x || y<=l) return unit;
	if (x<=l && r<=y) return d[k];
	return query(x, y, k*2, l, (l+r)/2) + query(x, y, k*2+1, (l+r)/2, r);
    }
};




int N, M;
Adj G;
int C[400111];

int main() {
    scanf("%d%d", &N, &M);
    G = Adj(N);
    
    REP (i, N) scanf("%d", C+i), C[i]--;
    REP (i, N-1) {
	int a, b;
	scanf("%d%d", &a, &b);
	a--; b--;
	G[a].push_back(b);
	G[b].push_back(a);
    }

    TreeDFS D(G);
    SegmentTree S(N);
    REP (i, N) S.modify(D.ett_in[i], 1LL<<C[i]);
    
    REP ($, M) {
	char op[8];
	scanf("%s", op);

	if (op[0] == '1') {
	    int x, y;
	    scanf("%d%d", &x, &y);
	    x--;
	    y--;
	    S.set(D.ett_in[x], D.ett_in[x] + D.subtree_size[x], 1LL<<y);
	} else {
	    int x;
	    scanf("%d", &x);
	    x--;
	    Seg g = S.query(D.ett_in[x], D.ett_in[x] + D.subtree_size[x]);
	    printf("%d\n", (int)__builtin_popcountll(g.val));
	}
	
    }
    
    
    return 0;
}