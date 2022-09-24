#include<map>
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
    int size(int x) { return -u[root(x)]; }
    int count() { return cc; }
};


int N, M, Q;
char buf[10011];
map<string, int> mp;
int get(const string &s) {
    if (mp.find(s) == mp.end()) return -1;
    return mp.find(s)->second;
}


int main() {
    scanf("%d%d%d", &N, &M, &Q);
    REP (i, N) {
	scanf("%s", buf);
	mp[buf] = i;
    }

    UnionFind U(2 * N);
    REP (i, M) {
	char op[11];
	int x, y;
	scanf("%s", op);
	scanf("%s", buf);
	x = get(buf);
	scanf("%s", buf);
	y = get(buf);
	
	bool yes = false;
	if (*op == '1') {
	    if (U.same(x, y+N)) yes = false;
	    else { yes = true; U.link(x, y); U.link(x+N, y+N); }
	} else {
	    if (U.same(x, y)) yes = false;
	    else { yes = true; U.link(x, y+N); U.link(x+N, y); }
	}
	puts(yes? "YES": "NO");
    }

    REP (i, Q) {
	int x, y;
	scanf("%s", buf);
	x = get(buf);
	scanf("%s", buf);
	y = get(buf);

	if (x == -1 || y == -1) puts("3");
	else if (U.same(x, y)) puts("1");
	else if (U.same(x, y+N)) puts("2");
	else puts("3");
    }


    return 0;
}