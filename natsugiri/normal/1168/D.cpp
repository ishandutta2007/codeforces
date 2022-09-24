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
struct Seg {
    bool valid;
    int C[27];
    int U[27];

    Seg() {
	valid = true;
	memset(C, 0, sizeof C);
	memset(U, 0, sizeof U);
    }
    void add(char c, int v) {
	if (c == '?') C[26] += v;
	else C[c-'a'] += v;
    }

    void fresh(const Seg &a, const Seg &b) {
	valid = false;
	if (a.valid && b.valid) {
	    valid = true;
	    int qa = a.U[26];
	    int qb = b.U[26];
	    REP (c, 26) {
		U[c] = C[c];
		if (a.U[c] > b.U[c]) {
		    qb -= a.U[c] - b.U[c];
		    U[c] += a.U[c];
		} else {
		    qa -= b.U[c] - a.U[c];
		    U[c] += b.U[c];
		}
	    }
	    if (qa < 0 || qb < 0) {
		valid = false;
	    } else {
		assert(qa == qb);
		U[26] = C[26] + qa;
	    }
	}
    }

    void fresh() {
	valid = true;
	REP (i, 27) U[i] = C[i];
    }
};


const int MAXN = 150011;
int N, Q;
char S[MAXN];
int par[MAXN];
VI G[MAXN];

int depth[MAXN];
int head[MAXN];
int tail[MAXN];
Seg seg[MAXN];

void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, N-1) {
	int v = i+1;
	int p;
	scanf("%d%s", &p, S+v);
	p--;
	G[p].push_back(v);
	par[v] = p;
    }

    REP (i, N) {
	EACH (e, G[i]) depth[*e] = depth[i]+1;
    }
    int ma = *max_element(depth, depth+N);
    bool yes = true;
    REP (i, N) if (G[i].empty() && depth[i] != ma) {
	yes = false;
	break;
    }
    if (yes) {
	REP (i, N) {
	    EACH (e, G[i]) {
		if (G[i].size() == 2u) {
		    head[*e] = *e;
		} else {
		    head[*e] = head[i];
		}
	    }
	}
	for (int i=N; i--;) {
	    if (G[i].size() == 1u) {
		tail[i] = tail[G[i][0]];
	    } else {
		tail[i] = i;
	    }
	}

	for (int i=N; i--;) {
	    int h = head[i];
	    if (i) {
		seg[h].add(S[i], 1);
	    }
	    if (h == i && G[tail[h]].size() == 2u) {
		int a = G[tail[h]][0];
		int b = G[tail[h]][1];
		seg[h].fresh(seg[a], seg[b]);
	    } else {
		seg[h].fresh();
	    }
	}
    }

    REP ($, Q) {
	int v;
	static char s[11];
	scanf("%d%s", &v, s);
	v--;
	if (yes && S[v] != s[0]) {
	    int h = head[v];
	    seg[h].add(S[v], -1);
	    seg[h].add(s[0], 1);
	    S[v] = s[0];
	    while (1) {
		if (G[tail[h]].size() == 2u) {
		    int a = G[tail[h]][0];
		    int b = G[tail[h]][1];
		    seg[h].fresh(seg[a], seg[b]);
		} else {
		    seg[h].fresh();
		}
		if (h == 0) break;
		else h = head[par[h]];
	    }
	}

	if (yes && seg[0].valid) {
	    LL ans = 0;
	    REP (c, 26) ans += (c+1LL) * (seg[0].U[c] + seg[0].U[26]);
	    printf("Shi %lld\n", ans);
	} else {
	    puts("Fou");
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}