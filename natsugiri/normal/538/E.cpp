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

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

const int MAX = 200011;
int N;
VI G[MAX];
int depth[MAX], par[MAX], leaves[MAX];
VI ord;

void bfs() {
    ord.push_back(0);
    par[0] = -1;
    REP (i, N) {
	int v = ord[i];
	EACH (e, G[v]) {
	    ord.push_back(*e);
	    par[*e] = v;
	    depth[*e] = depth[v] + 1;
	}
    }

    for (int i=N; --i;) {
	int v = ord[i];
	if (v !=0 && G[v].size() == 0u) leaves[v] = 1;
	leaves[par[v]] += leaves[v];
    }
}

int mem[MAX];
int max_game() {
    if (N == 1) return 1;
    
    for (int i=N; i--;) {
	int v = ord[i];
	if (v != 0 && G[v].size() == 0u) { // leaf
	    mem[v] = 1;
	} else {
	    int ma = -1;
	    if (depth[v] & 1) { // min
		ma = 1;
		EACH (e, G[v]) ma += mem[*e] - 1;
	    } else { // max
		EACH (e, G[v]) amax(ma, leaves[v] - leaves[*e] + mem[*e]);
	    }
	    mem[v] = ma;
	}
    }
    return mem[0];
}

int min_game() {
    if (N == 1) return 1;
    memset(mem, 0, sizeof mem);
    
    for (int i=N; i--;) {
	int v = ord[i];
	if (v != 0 && G[v].size() == 0u) { // leaf
	    mem[v] = 1;
	} else {
	    int mi = N + 10;
	    if (depth[v] & 1) { // min
		EACH (e, G[v]) amin(mi, mem[*e]);
	    } else { // max
		mi = 0;
		EACH (e, G[v]) mi += mem[*e];
	    }

	    mem[v] = mi;
	}
    }
    return mem[0];
}

int main() {
    scanf("%d", &N);
    REP (i, N-1) {
	int a, b;
	scanf("%d%d", &a, &b);
	a--;	b--;
	G[a].push_back(b);
//	G[b].push_back(a);
    }
    bfs();
//    REP (i, N) eprintf("%d %d %d %d\n", i+1, par[i]+1, depth[i], leaves[i]);

    printf("%d %d\n", max_game(), min_game());
    return 0;
}