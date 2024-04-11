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

const int MAXN = 100011;
int N;
VI G[MAXN];
int nxt[MAXN];
int dp[MAXN];
int name[MAXN];

void MAIN() {
    scanf("%d", &N);

#ifdef MYTEST
    REP (t, 20000) rand();
    N = 100000;
    REP (i, N-1) {
	int x = rand() % (i+1);
	G[x].push_back(i+1);
	//eprintf("%d -> %d\n", x, i+1);
    }
#else
    REP (i, N-1) {
	int x;
	scanf("%d", &x);
	G[x].push_back(i+1);
    }
#endif

    memset(nxt, -1, sizeof nxt);

    VI ans;
    for (int v=N; v--;) {
	if (G[v].empty()) {
	    dp[v] = 1;
	    name[v] = v;
	} else {
	    vector<pair<int, int> > X;
	    EACH (e, G[v]) {
		X.emplace_back(dp[*e], *e);
	    }
	    sort(X.begin(), X.end());
	    int prv = v;
	    REP (i, X.size()) {
		if (i) {
		    REP (t, dp[X[i-1].second]) {
			ans.push_back(X[i].second);
		    }
		}
		nxt[prv] = X[i].second;
		prv = name[X[i].second];
	    }

	    dp[v] = X.back().first + 1;
	    name[v] = name[X.back().second];
	}
    }

    int cur = 0;
    REP (i, N) {
	printf("%d%c", cur, " \n"[i==N-1]);
	cur = nxt[cur];
    }
    assert(cur == -1);

    printf("%d\n", (int)ans.size());
    rprintf("%d", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}