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


int N, M, W;
int A[1111];
int B[1111];
VI G[1111];

int dp[2][2111];

int main() {
    scanf("%d%d%d", &N, &M, &W);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) scanf("%d", B+i);
    UnionFind U(N);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	U.link(x, y);
    }

    REP (i, N) G[U.root(i)].push_back(i);

    memset(dp, 0xfc, sizeof dp);
    int *cur = dp[0];
    int *nxt = dp[1];
    cur[0] = 0;

    REP (i, N) if (!G[i].empty()) {
	memset(nxt, 0xfc, sizeof (int) * 2111);

	int sum_a = 0, sum_b = 0;
	EACH (e, G[i]) {
	    REP (j, W-A[*e]+1) amax(nxt[j + A[*e]], cur[j] + B[*e]);
	    sum_a += A[*e];
	    sum_b += B[*e];
	}
	REP (j, W-sum_a+1) amax(nxt[j + sum_a], cur[j] + sum_b);

	REP (j, W+1) amax(cur[j], nxt[j]);
    }

    printf("%d\n", *max_element(cur, cur+W+1));

    return 0;
}