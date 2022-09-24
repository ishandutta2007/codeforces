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
VI G[100011];
int par[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    int root = 0;
    REP (i, N) if (G[root].size() < G[i].size()) {
	root = i;
    }


    bool yes = true;
    REP (i, N) if (i != root) {
	if (G[i].size() > 2u) yes = false;
    }

    if (!yes) {
	puts("No");
    } else {
	VI ord; ord.reserve(N);
	ord.push_back(root);
	par[root] = root;
	REP (i_, N) {
	    int v = ord[i_];
	    EACH (e, G[v]) if (*e != par[v]) {
		par[*e] = v;
		ord.push_back(*e);
	    }
	}

	VI Z;
	REP (v, N) if (v != root && G[v].size() == 1u) {
	    Z.push_back(v);
	}

	puts("Yes");
	printf("%d\n", (int)Z.size());
	EACH (e, Z) {
	    int u = root+1;
	    int v = *e+1;
	    if (u > v) swap(u, v);
	    printf("%d %d\n", u, v);
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}