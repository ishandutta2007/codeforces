#include<stack>
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

const int MAX = 1000111;
int N, M;
int A_[MAX];
int &A(int r, int c) {
    return A_[r*M + c];
}
int B_[MAX];
int &B(int r, int c) {
    return B_[r*M + c];
}

pair<int, int> P[MAX];

VI G[MAX];

int name[MAX];
int deg[MAX];
int dp[MAX];



int main() {
    scanf("%d%d", &N, &M);
    REP (i, N * M) {
	scanf("%d", A_+i);
    }

    UnionFind U(N*M);

    REP (i, N) {
	REP (j, M) {
	    P[j] = make_pair(A(i, j), j);
	}
	sort(P, P+M);
	REP (j, M-1) {
	    if (P[j].first == P[j+1].first) {
		int a = i * M + P[j].second;
		int b = i * M + P[j+1].second;
		U.link(a, b);
	    }
	}
    }

    REP (j, M) {
	REP (i, N) {
	    P[i] = make_pair(A(i, j), i);
	}
	sort(P, P+N);
	REP (i, N-1) {
	    if (P[i].first == P[i+1].first) {
		int a = P[i].second * M + j;
		int b = P[i+1].second * M + j;
		U.link(a, b);
	    }
	}
    }

    int cnt = 0;
    REP (i, N*M) if (U.root(i) == i) name[i] = cnt++;
    REP (i, N*M) name[i] = name[U.root(i)];

    REP (i, N) {
	REP (j, M) {
	    P[j] = make_pair(A(i, j), j);
	}
	sort(P, P+M);
	REP (j, M-1) {
	    if (P[j].first < P[j+1].first) {
		int a = i * M + P[j].second;
		int b = i * M + P[j+1].second;
		a = name[a];
		b = name[b];
		G[a].push_back(b);
//		eprintf("%d -> %d\n", a, b);
		deg[b]++;
	    }
	}
    }

    REP (j, M) {
	REP (i, N) {
	    P[i] = make_pair(A(i, j), i);
	}
	sort(P, P+N);
	REP (i, N-1) {
	    if (P[i].first < P[i+1].first) {
		int a = P[i].second * M + j;
		int b = P[i+1].second * M + j;
		a = name[a];
		b = name[b];
		G[a].push_back(b);
//		eprintf("%d -> %d\n", a, b);
		deg[b]++;
	    }
	}
    }



    stack<int> S;
    REP (i, cnt) {
	if (deg[i] == 0) S.push(i);
    }


    REP (i, cnt) {
	int v = S.top(); S.pop();
	EACH (e, G[v]) {
	    amax(dp[*e], dp[v] + 1);
	    deg[*e]--;
	    if (deg[*e] == 0) S.push(*e);
	}
    }

    int cur = 0;
    REP (i, N) {
	REP (j, M) {
	    if (j) putchar(' ');
	    printf("%d", dp[name[U.root(cur)]] + 1);
	    cur++;
	}
	putchar('\n');
    }


    return 0;
}