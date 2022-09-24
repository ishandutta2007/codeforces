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

struct Edge {
    int src, dst, id, rev;
};

int N;
const int BASE = 200011;
vector<Edge> G[2 * BASE];
int iter[2 * BASE];
int CNT[2 * BASE];
char S[BASE];

void add_edge(int v, int w, int i) {
    G[v].push_back((Edge){ v, w, i });
    G[w].push_back((Edge){ w, v, i });
    CNT[v]--; CNT[w]--; S[i] = -1;
}

void flip(int v, int k) {
    int w = G[v][k].dst, i = G[v][k].id;
    S[i] *= -1;
    CNT[v] += 2 * S[i];
    CNT[w] += 2 * S[i];
}

int use[2*BASE], use_i;
bool dfs(int v, char c) {
    REP (i_, G[v].size()) {
	iter[v]++; if (iter[v] == (int)G[v].size()) iter[v] = 0;
	Edge *e = &G[v][iter[v]];
	int w = e->dst;
	if (use[w] != use_i && S[e->id] == c) {
	    use[w] = use_i;
	    if (abs(CNT[w]) >= abs(CNT[w] - 2 * c) || dfs(w, -c)) {
		S[e->id] *= -1;
		CNT[w] -= 2 * c;
		CNT[v] -= 2 * c;
		return true;
	    }
	}
    }
    return false;
}

void update(int v) {
    char c = 1;
    if (CNT[v] < 0) c = -1;

    use_i++;
    use[v] = use_i;
    dfs(v, c);
}

int main() {
    scanf("%d", &N);
    REP (i, N) {
	int x, y;
	scanf("%d%d", &x, &y);
	add_edge(x, y+BASE, i);
    }

    while (1) {
	bool loop = false;
	REP (i, 2 * BASE) {
	    while (abs(CNT[i]) > 1) {
		update(i);
		loop = true;
	    }
	}
	if (!loop) break;
    }

    REP (i, N) putchar(S[i] == 1? 'r' : 'b');
    putchar('\n');


    return 0;
}