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

const int MAXN = 300011;
int N;
int X, Y;
VI G[MAXN];
int par[MAXN];

bool H[MAXN];
VI ord;

void bfs(int s) {
    ord.clear();
    ord.push_back(s);
    par[s] = s;

    for (int i_=0; i_<(int)ord.size(); i_++) {
	int v = ord[i_];
	EACH (e, G[v]) if (!H[*e] && *e != par[v]) {
	    par[*e] = v;
	    ord.push_back(*e);
	}
    }
}

void MAIN() {
    scanf("%d%d%d", &N, &X, &Y);
    X--; Y--;
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    ord.reserve(N);
    bfs(X);

    int cur = Y;
    while (1) {
	H[cur] = true;
	if (cur == X) break;
	cur = par[cur];
    }

    bfs(X);
    LL A = ord.size();
    bfs(Y);
    LL B = ord.size();

    LL ans = (LL)N * (N-1) - A * B;

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}