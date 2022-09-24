#include<set>
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


int N, Q;
int main() {
    scanf("%d%d", &N, &Q);

    UnionFind U(N);
    set<int> S;
    REP (i, N) S.insert(i);

    REP (i, Q) {
	int T, X, Y;
	scanf("%d%d%d", &T, &X, &Y);
	X--; Y--;
	
	if (0) {
	} else if (T == 1) {
	    U.link(X, Y);
	} else if (T == 2) { // [X, Y]
	    set<int>::iterator it = S.lower_bound(X);
	    while (*it < Y) {
		U.link(*it, *it+1);
		S.erase(it++);
	    }
	} else if (T == 3) {
	    puts(U.same(X, Y) ? "YES" : "NO");
	}
    }

    return 0;
}