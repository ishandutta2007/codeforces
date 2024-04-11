#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
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
VI G[1011];
bool use[1011];
int par[1011], deg[1011];

int query(int x, int y) {
    printf("? %d %d\n", x+1, y+1);
    fflush(stdout);
    int z;
    scanf("%d", &z);
    return z-1;
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

    int s = 0;
    while (1) {
	VI que;
	que.push_back(s);
	par[s] = s;
	for (int i=0; i<(int)que.size(); i++) {
	    int v = que[i];
	    EACH (e, G[v]) if (!use[*e] && *e != par[v]) {
		par[*e] = v;
		que.push_back(*e);
	    }
	}

	if (que.size() == 1u) {
	    break;
	} else if (que.size() == 2u) {
	    s = query(que[0], que[1]);
	    break;
	} else {
	    memset(deg, 0, sizeof deg);
	    EACH (e, que) {
		EACH (f, G[*e]) if (!use[*f]) {
		    deg[*e]++;
		}
	    }
	    int c = max_element(deg, deg+N) - deg;
	    int x = -1, y = -1;
	    EACH (e, G[c]) if (!use[*e]) {
		if (x == -1) x = *e;
		else if (y == -1) {
		    y = *e;
		    break;
		}
	    }
	    int q = query(x, y);

	    if (q == c) {
		s = c;
		use[x] = use[y] = true;
	    } else if (q == x) {
		s = x;
		use[c] = use[y] = true;
	    } else {
		s = y;
		use[c] = use[x] = true;
	    }
	}
    }

    printf("! %d\n", s+1);
    fflush(stdout);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}