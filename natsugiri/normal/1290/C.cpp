#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}
template<class T> struct UnionFindSum {
    int n;
    vector<int> U;
    vector<T> D;
    UnionFindSum() {}
    UnionFindSum(int n_, const T &init): n(n_), U(n, -1), D(n, init) {}
    int root(int x) {
	if (U[x] < 0) return x;
	return U[x] = root(U[x]);
    }
    int link(int x, int y) {
	x = root(x); y = root(y);
	if (x == y) return x;
	if (U[y] < U[x]) swap(x, y);
	U[x] += U[y];
	D[x] += D[y];
	n--;
	return U[y] = x;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -U[root(x)]; }
    int count() { return n; }
    void add(int x, const T &v) { D[root(x)] += v; }
    T get(int x) { return D[root(x)]; }
};

int N, K;
char S[300011];

VI L2S[300011];

int T, F;
int cost;

UnionFindSum<int> U;
int COST(int s) {
    if (U.same(s, T) || U.same(s, F)) return U.get(T);
    return min(U.get(s), U.size(s) - U.get(s));
}

void MAIN() {
    scanf("%d%d", &N, &K);
    scanf("%s", S);
    REP (i, K) {
	int len;
	scanf("%d", &len);
	REP (j, len) {
	    int x;
	    scanf("%d", &x);
	    x--;
	    L2S[x].push_back(i);
	}
    }

    cost = 0;

    U = UnionFindSum<int>(2*K+2, 0);
    REP (i, K) U.D[i*2+1] = 1;
    F = K*2;
    T = F+1;

    REP (i, N) {
	if (S[i] == '0') {
	    if (L2S[i].size() == 1u) {
		int x = L2S[i][0]*2;
		if (!U.same(T, x+1)) { // ON;
		    cost -= COST(T);
		    cost -= COST(x);
		    U.link(T, x+1);
		    U.link(F, x);
		    cost += COST(T);
		}
	    } else if (L2S[i].size() == 2u) { // DIFF;
		int x = L2S[i][0]*2;
		int y = L2S[i][1]*2;
		if (!U.same(x, y+1)) {
		    cost -= COST(x);
		    cost -= COST(y);
		    U.link(x, y+1);
		    U.link(x+1, y);
		    cost += COST(y);
		}
	    } else {
		assert(false);
	    }
	} else {
	    if (L2S[i].empty()) {
		// nothing;
	    } else if (L2S[i].size() == 1u) { // OFF;
		int x = L2S[i][0]*2;
		if (!U.same(F, x+1)) {
		    cost -= COST(T);
		    cost -= COST(x);
		    U.link(T, x);
		    U.link(F, x+1);
		    cost += COST(T);
		}
	    } else if (L2S[i].size() == 2u) { // SAME;
		int x = L2S[i][0]*2;
		int y = L2S[i][1]*2;
		if (!U.same(x, y)) {
		    cost -= COST(x);
		    cost -= COST(y);
		    U.link(x, y);
		    U.link(x+1, y+1);
		    cost += COST(y);
		}
	    } else {
		assert(false);
	    }
	}

	printf("%d\n", cost);
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}