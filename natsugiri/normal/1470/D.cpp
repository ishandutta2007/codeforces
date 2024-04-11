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

int N, M;
VI G[300011];

VI que;
int par[300011];
bool use[300011];

VI ans;

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) G[i].clear();

    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--;
	y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }


    que.clear();
    que.push_back(0);
    REP (i, N) par[i] = -1;
    par[0] = 0;
    for (int i=0; i<(int)que.size(); i++) {
	int v = que[i];
	EACH (e, G[v]) if (par[*e] == -1) {
	    par[*e] = v;
	    que.push_back(*e);
	}
    }

    if ((int)que.size() == N) {
	REP (i, N) use[i] = false;
	ans.clear();
	REP (i, N) {
	    int v = que[i];
	    if (!use[v]) {
		ans.push_back(v+1);
		use[v] = true;
		EACH (e, G[v]) use[*e] = true;
	    }
	}

	puts("YES");
	printf("%d\n", (int)ans.size());
	rprintf("%d", ans.begin(), ans.end());
    } else {
	puts("NO");
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}