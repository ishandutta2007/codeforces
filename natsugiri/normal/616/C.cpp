#include<map>
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

int N, M;
char F[1011][1011];

const int dy[] = { 0, 1, 0, -1};
const int dx[] = { 1, 0, -1, 0};

bool in(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
} 
int main() {
    scanf("%d%d", &N, &M);
    UnionFind U(N*M);
    REP (i, N) scanf("%s", F[i]);
    REP (i, N) REP (j, M) {
	if (F[i][j] == '.') {
	    if (i && F[i-1][j] == '.') {
		U.link(i*M+j, (i-1)*M+j);
	    }
	    if (j && F[i][j-1] == '.') {
		U.link(i*M+j, i*M+j-1);
	    }
	}
    }

    REP (i, N) {
	REP (j, M) {
	    if (F[i][j] == '.') putchar('.');
	    else {
		map<int, int> mp;
		REP (d, 4) {
		    int y = i + dy[d], x = j + dx[d];
		    if (in(y, x) && F[y][x] == '.') mp[U.root(y*M+x)] = U.count(y*M+x);
		}
		int tmp = 1;
		EACH (e, mp) tmp += e->second;
		putchar('0' + tmp%10);
	    }
	}
	putchar('\n');
    }
    return 0;
}