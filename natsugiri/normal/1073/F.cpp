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
VI G[200011];
int P[200011];
int D[200011];

VI ord;
int bfs(int s) {
    ord.clear();
    ord.reserve(N);
    ord.push_back(s);
    P[s] = s;
    D[s] = 0;
    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) if (*e != P[v]) {
	    ord.push_back(*e);
	    P[*e] = v;
	    D[*e] = D[v] + 1;
	}
    }


    int ret = -1;
    REP (v, N) if (G[v].size() >= 3u) {
	if (ret == -1 || D[ret] < D[v]) {
	    ret = v;
	}
    }
    return ret;
}


pair<int, int> ma[200011][2];
bool use[200011];

VI gen(int y) {
    int x = bfs(y);

    REP (i_, N) {
	int v = ord[N-1-i_];
	pair<int, int> b[4] = {};
	EACH (e, G[v]) if (*e != P[v]) {
	    b[0] = ma[*e][0];
	    b[1] = ma[*e][1];
	    sort(b, b+4);
	}
	if (G[v].size() == 1u && !use[v]) b[0] = make_pair(D[v], v);
	sort(b, b+4);
	ma[v][0] = b[2];
	ma[v][1] = b[3];
    }

    int best = 0;
    VI bestX;
    
    REP (v, N) if (G[v].size() >= 3u && D[v] == D[x]) {
	if (ma[v][0].first + ma[v][1].first > best) {
	    best = ma[v][0].first + ma[v][1].first;
	    bestX = {ma[v][0].second, ma[v][1].second};
	}
    }

    use[bestX[0]] = use[bestX[1]] = true;
    return bestX;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    int y = bfs(0);
    int x = bfs(y);
    VI bestX = gen(y);
    VI bestY = gen(x);
    printf("%d %d\n", bestX[0]+1, bestY[0]+1);
    printf("%d %d\n", bestX[1]+1, bestY[1]+1);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}