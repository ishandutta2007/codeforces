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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

struct UnionFind {
    int n;
    vector<int> U;
    UnionFind() {}
    UnionFind(int n_): n(n_), U(n_, -1) {}
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

int N, M;
int W[200111], C[200111];
int X[200111], Y[200111];
int S;
int Z[200111];

struct ByArray {
    int *A;
    ByArray(int *A_) : A(A_) {}
    bool operator()(const int x, const int y) const {
	return A[x] < A[y];
    }
};

int ordW[200111];
int D[200111];
int ordD[200111];

int main() {
    scanf("%d%d", &N, &M);
    REP (i, M) scanf("%d", W+i);
    REP (i, M) scanf("%d", C+i);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	X[i] = x;
	Y[i] = y;
    }
    scanf("%d", &S);
    
    REP (i, M) ordW[i] = ordD[i] = i;
    ByArray byW(W), byD(D);
    sort(ordW, ordW+M, byW);

    for (int s=19; s--;) {
	int diff = 1 << s;
	sort(ordD, ordD+M, byD);
	int cur = 0;
	UnionFind U(N);
	REP (i, M) {
	    while (cur < M) {
		int idx = ordD[cur];
		if (D[idx] + diff == i) {
		    if (!U.same(X[idx], Y[idx])) D[idx] += diff;
		    cur++;
		} else {
		    break;
		}
	    }

	    {
		int idx = ordW[i];
		if (!U.same(X[idx], Y[idx])) {
		    U.link(X[idx], Y[idx]);
		    Z[i] = W[idx];
		}
	    }
	}
    }

    LL sum = 0;
    REP (i, M) sum += Z[i];

    LL best = sum + 1;
    int pos = -1;

    REP (i, M) {
	LL tmp = sum - Z[D[i]] + W[i] - S / C[i];
	if (best > tmp) {
	    best = tmp;
	    pos = i;
	}
    }

    printf("%lld\n", best);

    {
	UnionFind U(N);
	REP (i, M) {
	    int idx;
	    LL cost;
	    if (i == D[pos]) {
		idx = pos;
		cost = W[pos] - S / C[pos];
	    } else {
		idx = ordW[i];
		cost = W[idx];
	    }

	    int x = X[idx], y = Y[idx];
	    if (!U.same(x, y)) {
		printf("%d %lld\n", idx+1, cost);
		U.link(x, y);
	    }
	}
    }

    return 0;
}