#include<set>
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

template<class T> struct UnionFindSum {
    int n;
    vector<int> U;
    vector<T> D;
    UnionFindSum() {}
    UnionFindSum(int n, const T &init): n(n), U(n, -1), D(n, init) {}
    UnionFindSum(const vector<T> &D): n(D.size()), U(n, -1), D(D) {}
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
    int size() { return n; }
    int count(int x) { return -U[root(x)]; }
    void add(int x, const T &v) { D[root(x)] += v; }
    T get(int x) { return D[root(x)]; }
};

int N, A[100111], B[100111];
bool use[100111];
LL ans[100111];

UnionFindSum<LL> U;
multiset<LL> ms;

void link(int x, int y) {
    LL xg = U.get(x);
    LL yg = U.get(y);
    LL sg = 0;

//    eprintf("%d %lld : %d %lld\n", x, xg, y, yg);

    if (use[x]) {
	ms.erase(ms.find(xg));
	sg += xg;
    } else {
	sg += A[x];
    }

    if (use[y]) {
	ms.erase(ms.find(yg));
	sg += yg;
    } else {
	sg += A[y];
    }

    ms.insert(sg);
    U.link(x, y);
}


int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) scanf("%d", B+i), B[i]--;

    U = UnionFindSum<LL>(N, 0);

    for (int i=N; i--; ) {
	use[B[i]] = true;
	ms.insert(A[B[i]]);
	U.add(B[i], A[B[i]]);

	if (B[i] > 0 && use[B[i]-1]) {
	    link(B[i], B[i]-1);
	}
	if (B[i]+1 < N && use[B[i]+1]) {
	    link(B[i], B[i]+1);
	}

	ans[i] = *ms.rbegin();
    }


    REP (i, N) printf("%lld\n", ans[i+1]);



    return 0;
}