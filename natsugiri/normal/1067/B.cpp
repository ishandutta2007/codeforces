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

int N, K;
VI G[100011];
int D[100011];
int P[100011];
int L[100011];

VI ord;
int bfs(int s) {
    memset(D, 0x3f, sizeof D);
    D[s] = 0;
    ord.clear();
    ord.reserve(N);
    ord.push_back(s);
    P[s] = s;
    REP (i, N) {
	int v = ord[i];
	EACH (e, G[v]) if (D[*e] > D[v] + 1) {
	    D[*e] = D[v]+1;
	    P[*e] = v;
	    ord.push_back(*e);
	}
    }
    return max_element(D, D+N) - D;
}

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    bool yes;
    int x = bfs(0);
    int y = bfs(x);

    if (N <= 3) {
	yes = false;
    } else if (D[y] % 2) {
	yes = false;
    } else {
	int cur = y;
	REP (t, D[y]/2) {
	    cur = P[cur];
	}
	bfs(cur);
	memset(L, -1, sizeof L);
	L[cur] = K;
	yes = true;
	REP (i, N) {
	    int v = ord[i];
	    if (G[v].size() == 1u) {
		if (L[v] != 0) {
		    yes = false;
		}
	    } else {
		int cnt = 0;
		EACH (e, G[v]) if (*e != P[v]) {
		    cnt++;
		    L[*e] = L[v]-1;
		}
		if (cnt < 3) {
		    yes = false;
		}
	    }
	}
    }

    puts(yes? "Yes": "No");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}