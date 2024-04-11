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

const int MAXN = 400111;
int N;

struct Seg {
    int val;
    int sz;
    Seg(int v=0) { val=v; sz=0; }
    Seg inc() const {
	Seg z = *this;
	z.sz++;
	if (z.sz <= N/2) z.val = z.sz;
	return z;
    }
};
Seg operator+(const Seg &x, const Seg &y) {
    Seg z;
    z.val = max(x.val, y.val);
    z.sz = x.sz + y.sz;
    return z;
}

VI G[MAXN];
VI ord;
Seg up[MAXN], dw[MAXN];
int ans[MAXN];
vector<Seg> L[MAXN], R[MAXN];

void treeDP() {
    ord.clear(); ord.reserve(N);
    ord.push_back(0);
    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) {
	    ord.push_back(*e);
	    G[*e].erase(remove(G[*e].begin(), G[*e].end(), v), G[*e].end()); // remove parent
	}
    }

    REP (i_, N) {
	int v = ord[N-1-i_];
	int m = G[v].size();
	L[v].assign(m+1, Seg());
	R[v].assign(m+1, Seg());
	REP (i, m)
	    L[v][i+1] = L[v][i] + up[G[v][i]];
	for (int i=m; i--; )
	    R[v][i] = up[G[v][i]] + R[v][i+1];
	up[v] = R[v][0].inc(); // up[v] = L[v].all + v own
    }

    dw[0] = Seg();
    REP (i_, N) {
	int v = ord[i_];
	// ans[v] = R[v][0] + dw[v]; // whne v == 0, dw[v] is an empty tree
	if (N - up[v].sz > N / 2) ans[v] = (dw[v].sz - dw[v].val <= N / 2);
	else {
	    ans[v] = true;
	    REP (i, G[v].size()) {
		int w = G[v][i];
		if (up[w].sz > N / 2 && up[w].sz - up[w].val > N / 2) ans[v] = false;
	    }
	}
	REP (i, G[v].size()) {
	    int w = G[v][i];
	    dw[w] = (R[v][i+1] + dw[v] + L[v][i]).inc(); // add v own
	}
    }
}


int main() {
    scanf("%d", &N);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    treeDP();

    REP (i, N) printf("%d%c", (int)ans[i], i==N-1?'\n': ' ');;

    return 0;
}