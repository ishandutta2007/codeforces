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



int N, A[200111];
int B[200111];
int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i), A[i]--;

    UnionFind U(N);
    REP (i, N) U.link(i, A[i]);
    vector<pair<int, int> > v;


    REP (i, N) if (U.root(i) == i) {
	int c = 1;
	int z = i;
	while (B[z] == 0) {
	    B[z] = c;
	    c++;
	    z = A[z];
	}
	v.push_back(make_pair(c - B[z], z));
    }

    int ans;
    sort(v.begin(), v.end());
    if (v[0].first == 1) {
	ans = v.size() - 1;
    } else {
	ans = v.size();
    }
    EACH (e, v) A[e->second] = v[0].second;

    printf("%d\n", ans);
    REP (i, N) printf("%d%c", A[i]+1, i==N-1? '\n': ' ');

    return 0;
}