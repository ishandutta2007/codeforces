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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

struct UnionFind {
    int n;
    vector<int> U;
    UnionFind() {}
    UnionFind(int n): n(n), U(n, -1) {}
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
int N, M, A[1000111]; 

VI I[1000111], X[1000111];

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", A+i);
    UnionFind U(N);
    REP (i, M) {
	int a, b;
	scanf("%d%d", &a, &b);
	U.link(a-1, b-1);
    }

    REP (i, N) {
	int r = U.root(i);
	I[r].push_back(i);
	X[r].push_back(A[i]);
    }
    REP (i, N+1) {
	sort(X[i].rbegin(), X[i].rend());
	REP (j, X[i].size()) 
	    A[I[i][j]] = X[i][j];
    }
    REP (i, N) printf("%d%c", A[i], i==N-1? '\n': ' ');

    return 0;
}