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

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }
struct UnionFind {
    vector<int>U;
    int n;
    UnionFind() {}
    UnionFind(int n) :n(n) { U=vector<int>(n, -1); }
    int root(int x) {
	if (U[x]<0) return x;
	return U[x]=root(U[x]);
    }
    int link(int x, int y) {
	int p, q;
	p=root(x); q=root(y);
	if (p==q) return p;
	if (U[q]<U[p]) swap(p, q);
	U[p]+=U[q];
	n--;
	return U[q]=p;
    }
    bool same(int x, int y) { return root(x)==root(y); }
    int size() { return n; }
    int count(int x) { return -U[root(x)]; }
};

int N, M;
VI G[1011];
int A[1011][1011];
char col[1011];
UnionFind U;

bool bi(int v) {
    if (col[v] == 0) col[v] = 1;
    EACH (e, G[v]) {
	if (col[*e] == col[v]) return false;
	if (col[*e]) continue;
	col[*e] = 3 - col[v];
	if (!bi(*e)) return false;
    }
    return true;
}

int main() {
    scanf("%d%d", &N, &M);

    U = UnionFind(N);
    memset(A, 0x3f, sizeof A);

    REP (i, M) {
	int a, b;
	scanf("%d%d", &a, &b);
	a--; b--;
	G[a].push_back(b);
	G[b].push_back(a);
	A[a][b] = A[b][a] = 1;
	U.link(a, b);
    }

    bool yes = true;
    REP (i, N) if (U.root(i) == i) {
	if (!bi(i)) {
	    yes = false;
	    break;
	}
    }

    //REP (i, N) eprintf("%c", col[i] + '#'); eprintf("\n");

    if (yes) {
	REP (i, N) A[i][i] = 0;
	REP (k, N) REP (i, N) REP (j, N) amin(A[i][j], A[i][k] + A[k][j]);
	
	// REP (i, N) {
	//     REP (j, N) {
	// 	if (A[i][j] == A[N][N]) eprintf("* ");
	// 	else eprintf("%d ", A[i][j]);
	//     }
	//     eprintf("\n");
	// }
	
	int ans = 0;
	REP (i, N) if (U.root(i) == i) {
	    VI v;
	    REP (j, N) if (U.same(i, j)) v.push_back(j);
	    int ma = 0;
	    EACH (e, v) EACH (f, v) amax(ma, A[*e][*f]);
	    ans += ma;
	}
	printf("%d\n", ans);
    } else {
	puts("-1");
    }
    
    return 0;
}