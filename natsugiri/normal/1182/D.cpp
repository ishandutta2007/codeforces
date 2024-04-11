#include<map>
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
VI G[100011];
int par[100011];
int sz[100011];
int subsz[100011];
int ma[100011];

VI test;
bool solve(int guess, bool add) {
    memset(par, -1, sizeof par);
    VI cur, nxt;
    cur.push_back(guess);
    par[guess] = guess;
    ma[guess] = 0;
    while (!cur.empty()) {
	map<int, int> mp;
	EACH (e, cur) {
	    mp[G[*e].size()]++;
	}
	if (mp.size() > 2u) {
	    return false;
	}
	if (mp.size() == 2u) {
	    if (add) {
		VI c;
		EACH (e, cur) if (mp[G[*e].size()] == 1) {
		    c.push_back(*e);
		}
		for (int i=0; i<(int)c.size(); i++) {
		    int v = c[i];
		    EACH (e, G[v]) if (*e != par[v]) {
			par[*e] = v;
			c.push_back(*e);
		    }
		}
		EACH (e, c) if (G[*e].size() == 1u) {
		    int v = *e;
		    while (v != guess && G[v].size() <= 2u) v = par[v];
		    if (v == guess) test.push_back(*e);
		}
	    }

	    return false;
	}

	nxt.clear();
	EACH (e, cur) EACH (f, G[*e]) if (*f != par[*e]) {
	    par[*f] = *e;
	    nxt.push_back(*f);
	}
	swap(cur, nxt);
    }
    return true;
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

    if (N == 1) {
	puts("1");
	return;
    }

    VI ord;
    ord.reserve(N);
    ord.push_back(0);
    REP (i, N) {
	int v = ord[i];
	EACH (e, G[v]) if (*e != par[v]) {
	    par[*e] = v;
	    ord.push_back(*e);
	}
    }
    REP (i, N) {
	int v = ord[N-1-i];
	sz[v] = 1;
	EACH (e, G[v]) if (*e != par[v]) {
	    sz[v] += sz[*e];
	    amax(subsz[v], sz[*e]);
	}
    }

    int guess = -1;
    REP (i, N) {
	if (max(N-sz[i], subsz[i]) * 2 <= N) {
	    guess = i;
	    break;
	}
    }

    if (solve(guess, true)) {
	printf("%d\n", guess+1);
	return;
    }
    EACH (e, test) if (solve(*e, false)) {
	printf("%d\n", *e+1);
	return;
    }
    puts("-1");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}