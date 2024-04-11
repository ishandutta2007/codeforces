#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N;

VI G[200011];
int par[200011];
int sz[200011];
LL ans[200011];

bool use[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) G[i].clear();

    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	G[x].push_back(y);
	G[y].push_back(x);
    }

    VI que;

    que.push_back(0);
    REP (i, N) {
	int v = que[i];
	EACH (e, G[v]) if (*e != par[v]) {
	    par[*e] = v;
	    que.push_back(*e);
	}
    }

    REP (i, N) {
	int v = que[N-1-i];
	sz[v] = 1;
	EACH (e, G[v]) if (*e != par[v]) {
	    sz[v] += sz[*e];
	}
    }

    REP (i, N+5) {
	ans[i] = 0;
	use[i] = false;
    }


    int A = 0, B = 0;
    LL szA = 0, szB = 0;
    use[0] = true;

    ans[0] = (LL)N * (N-1) / 2;

    {
	LL sum = 1;
	EACH (e, G[0]) {
	    ans[1] += sum * sz[*e];
	    sum += sz[*e];
	}
    }


    for (int v=1; v<N; v++) {
	bool bad = false;
	if (!use[v]) {
	    int x = v;
	    while (1) {
		use[x] = true;
		int p = par[x];
		if (p == A) {
		    A = v;
		    szA = sz[v];
		    break;
		}
		if (p == B) {
		    B = v;
		    szB = sz[v];
		    break;
		}
		if (use[p]) {
		    bad = true;
		    break;
		}
		x = p;
	    }

	    if (v == 1) {
		int tmp = 1;
		EACH (e, G[0]) if (!use[*e]) {
		    tmp += sz[*e];
		}

		if (A == 0) szA = tmp;
		else if (B == 0) szB = tmp;
		else assert(false);
	    }
	} 

	if (bad) break;

	ans[v+1] = szA * szB;
    }

    // rprintf("%lld", ans, ans+N+1);
    REP (v, N+1) {
	ans[v] -= ans[v+1];
    }

    rprintf("%lld", ans, ans+N+1);

}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}