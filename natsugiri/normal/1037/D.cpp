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
int A[200011];

int rnk[200011];

struct CMP {
    bool operator()(const int x, const int y) const {
	return rnk[x] < rnk[y];
    }
} cmp;

bool use[200011];
VI ord;


void MAIN() {
    scanf("%d", &N);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }
    REP (i, N) scanf("%d", A+i), A[i]--;

    REP (i, N) rnk[A[i]] = i;
    REP (v, N) sort(G[v].begin(), G[v].end(), cmp);

    ord.reserve(N);
    ord.push_back(0);
    use[0] = true;
    REP (i, N) {
	int v = ord[i];
	EACH (e, G[v]) if (!use[*e]) {
	    ord.push_back(*e);
	    use[*e] = true;
	}
    }

    bool yes = true;
    REP (i, N) if (A[i] != ord[i]) yes = false;
    puts(yes? "Yes": "No");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}