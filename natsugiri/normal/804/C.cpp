#include<set>
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

const int MAXN = 300111;
int N, M;
VI S[MAXN];
VI G[MAXN];
int par[MAXN];
int C[MAXN];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) {
	int t;
	scanf("%d", &t);
	S[i].resize(t);
	REP (j, t) scanf("%d", &S[i][j]), S[i][j]--;
    }

    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    memset(C, -1, sizeof C);
    VI ord; ord.reserve(N);
    ord.push_back(0);
    REP (i_, N) {
	int v = ord[i_];
	set<int> se;
	EACH (e, S[v]) {
	    if (C[*e] != -1) se.insert(C[*e]);
	}

	int cnt = 1;
	EACH (e, S[v]) if (C[*e] == -1) {
	    auto it = se.lower_bound(cnt);
	    while (it != se.end() && *it == cnt) {
		cnt++;
		it = se.lower_bound(cnt);
	    }
	    C[*e] = cnt++;
	}

	EACH (e, G[v]) if (*e != par[v]) {
	    par[*e] = v;
	    ord.push_back(*e);
	}
    }


    REP (i, M) if (C[i] == -1) C[i] = 1;
    printf("%d\n", *max_element(C, C+M));
    rprintf("%d", C, C+M);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}