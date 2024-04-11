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

struct UnionFind {
    int n;
    vector<int> U;
    UnionFind() {}
    UnionFind(int n_): n(n_), U(n, -1) {}
    int root(int x) {
	if (U[x] < 0) return x;
	return U[x] = root(U[x]);
    }
    int link(int x, int y) {
	x = root(x); y = root(y);
	if (x == y) return x;
	if (U[y] < U[x]) swap(x, y);
	U[x] += U[y];
	n--;
	return U[y] = x;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size() { return n; }
    int count(int x) { return -U[root(x)]; }
};

// CC : # conected components
// C[i] : if C[i] < 0 : Black, if C[i] > 0 : White (for i=0..N-1)
// ret[i] : connected componen i (#Black, #White)
const int MAX_N = 1000011, MAX_M = 1000011;
int N, M, A[MAX_M], B[MAX_M];
int C[2*MAX_N], CC;
vector<pair<int, int> > bipartite() {
    memset(C, 0, sizeof (int) * 2 * N);
    CC = 0;
    UnionFind U(2*N);
    REP (i, M) {
	U.link(A[i], B[i]+N);
	U.link(A[i]+N, B[i]);
    }
    vector<pair<int, int> > ret;
    REP (i, N) if (U.same(i, i+N)) return ret; // not bipartite
    vector<int> cnt(2*N, 0);
    REP (i, N) cnt[U.root(i)]++;
    REP (i, N) {
	int a = U.root(i), b = U.root(i+N);
	if ((a == i && a < b) || (b == i+N && b < a)) {
	    ret.push_back(make_pair(cnt[a], cnt[b]));
	    CC++;
	    C[a] = -CC; C[b] = CC;
	}
    }
    REP (i, N) C[i] = C[U.root(i)];
    return ret;
}

int main() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	scanf("%d%d", A+i, B+i);
	A[i]--;
	B[i]--;
    }

    vector<pair<int, int> > ret = bipartite();


    if (ret.empty()) {
	puts("-1");
	return 0;
    } else {
	int cnt = 0;
	REP (i, N) if (C[i] < 0) cnt++;
	printf("%d\n", cnt);
	REP (i, N) if (C[i] < 0) printf("%d ", i+1); printf("\n");
	printf("%d\n", N - cnt);
	REP (i, N) if (C[i] > 0) printf("%d ", i+1); printf("\n");
    }


    return 0;
}