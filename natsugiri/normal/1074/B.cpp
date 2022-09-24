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

int N;
VI G[1111];
VI X, Y;

int queryA(int v) {
    printf("A %d\n", v+1);
    fflush(stdout);
    scanf("%d", &v);
    return v-1;
}
int queryB(int v) {
    printf("B %d\n", v+1);
    fflush(stdout);
    scanf("%d", &v);
    return v-1;
}

int par[1111], dist[1111];
VI ord;
void bfs(int s) {
    ord.clear();
    par[s] = s;
    dist[s] = 0;
    ord.push_back(s);
    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) if (*e != par[v]) {
	    dist[*e] = dist[v] + 1;
	    par[*e] = v;
	    ord.push_back(*e);
	}
    }
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) G[i].clear();

    REP (i, N-1) {
	int a, b;
	scanf("%d%d", &a, &b);
	a--; b--;
	G[a].push_back(b);
	G[b].push_back(a);
    }

    int K1, K2;
    scanf("%d", &K1);
    X.resize(K1);
    REP (i, K1) scanf("%d", &X[i]), X[i]--;

    scanf("%d", &K2);
    Y.resize(K2);
    REP (i, K2) scanf("%d", &Y[i]), Y[i]--;

    int v = queryB(Y[0]);

    bfs(v);

    int best_dist = N, best_v = X[0];
    EACH (e, X) if (dist[*e] < best_dist) {
	best_dist = dist[*e];
	best_v = *e;
    }

    int w = queryA(best_v);
    EACH (e, Y) if (w == *e) {
	printf("C %d\n", best_v+1);
	fflush(stdout);
	return;
    }

    puts("C -1");
    fflush(stdout);
    return;
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}