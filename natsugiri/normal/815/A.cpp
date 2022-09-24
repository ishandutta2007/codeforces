#include<stack>
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

int N, M;
int G[111][111];

vector<pair<char, int> > ans;

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) REP (j, M) scanf("%d", G[i]+j);

    // all
    {
	int mi = G[0][0];
	int ma = G[0][0];
	REP (i, N) {
	    amin(mi, *min_element(G[i], G[i] + M));
	    amin(ma, *max_element(G[i], G[i] + M));
	}

	if (mi > 0) {
	    if (M < N) {
		REP (j, M) {
		    REP (t, mi) ans.emplace_back('c', j);
		}
	    } else {
		REP (i, N) {
		    REP (t, mi) ans.emplace_back('r', i);
		}
	    }

	    REP (i, N) REP (j, M) G[i][j] -= mi;
	}
    }

    stack<int> R, C;
    REP (i, N) REP (j, M) if (G[i][j] == 0) {
	R.push(i);
	C.push(j);
    }
    while (!R.empty()) {
	int r = R.top(); R.pop();
	int c = C.top(); C.pop();

	REP (j, M) if (G[r][j] > 0) {
	    int mi = G[0][j];
	    REP (i, N) amin(mi, G[i][j]);
	    if (mi > 0) {
		REP (t, mi) ans.emplace_back('c', j);
		REP (i, N) {
		    G[i][j] -= mi;
		    if (G[i][j] == 0) {
			R.push(i); C.push(j);
		    }
		}
	    }
	}

	REP (i, N) if (G[i][c] > 0) {
	    int mi = G[i][0];
	    REP (j, M) amin(mi, G[i][j]);
	    if (mi > 0) {
		REP (t, mi) ans.emplace_back('r', i);
		REP (j, M) {
		    G[i][j] -= mi;
		    if (G[i][j] == 0) {
			R.push(i); C.push(j);
		    }
		}
	    }
	}
    }


    int ma = 0;
    REP (i, N) amax(ma, *max_element(G[i], G[i] + M));
    if (ma == 0) {
	printf("%d\n", (int)ans.size());
	EACH (e, ans) {
	    if (e->first == 'r') printf("row %d\n", e->second + 1);
	    else printf("col %d\n", e->second + 1);
	}
    } else {
	puts("-1");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}