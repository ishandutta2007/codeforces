#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<set>

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
int P[100011];
int B[100011];
int A[100011];

int nxt[32][100011];
bool use[100011];
VI from[100011];

int ans[100011];
int atleast[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", P+i), P[i]--;
    REP (i, N) scanf("%d", B+i);

    REP (i, N) use[P[i]] = true;
    int out = 0;
    REP (i, N) if (!use[i]) out++;

    int ma = *max_element(B, B+N);

    assert((ma - N) % out == 0);
    int turn = (ma - N) / out;

    REP (i, N) nxt[0][i] = P[i];
    REP (t, 31) REP (i, N) nxt[t+1][i] = nxt[t][nxt[t][i]];

    REP (i, N) {
	int x = i;
	REP (t, 31) if (turn >> t & 1) x = nxt[t][x];
	from[x].push_back(i);
    }


    set<int> se;
    REP (i, N) se.insert(i+1);

    REP (i, N) {
	if (from[i].size()) {
	    ans[from[i][0]] = B[i];
	    se.erase(B[i]);
	    for (int k=1; k<(int)from[i].size(); k++) {
		atleast[from[i][k]] = B[i] + 1;
	    }
	}
	// rprintf("%d", from[i].begin(), from[i].end());
    }

    REP (i, N) if (ans[i] == 0) {
	auto it = se.lower_bound(atleast[i]);
	ans[i] = *it;
	se.erase(it);
    }
    rprintf("%d", ans, ans+N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}