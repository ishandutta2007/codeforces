#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N;
int P[2011], C[2011];
VI G[2011];
VI X[2011];
int ans[2011];

void MAIN() {
    int root;
    scanf("%d", &N);
    REP (i, N) {
	scanf("%d%d", P+i, C+i);
	P[i]--;
	if (P[i] == -1) root = i;
	else G[P[i]].push_back(i);
    }

    VI ord;
    ord.reserve(N);
    ord.push_back(root);
    REP (i, N) {
	int v = ord[i];
	EACH (e, G[v]) {
	    ord.push_back(*e);
	}
    }

    bool yes = true;
    REP (i_, N) {
	int v = ord[N-1-i_];
	EACH (e, G[v]) {
	    X[v].insert(X[v].end(), X[*e].begin(), X[*e].end());
	}

	if ((int)X[v].size() < C[v]) {
	    yes = false;
	} else {
	    X[v].insert(X[v].begin() + C[v], v);
	}
    }

    if (yes) {
	puts("YES");
	REP (i, N) ans[X[root][i]] = i + 1;
	rprintf("%d", ans, ans+N);
    } else {
	puts("NO");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}