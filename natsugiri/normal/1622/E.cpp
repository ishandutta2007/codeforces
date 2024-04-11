#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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
LL X[10];
char S[10][10011];

LL R[10011];
pair<LL, int> P[10011];

LL best;
int ans[10011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%lld", X+i);
    REP (i, N) scanf("%s", S[i]);

    best = -1;

    memset(R, 0, sizeof (LL) * M);
    REP (i, N) REP (j, M) if (S[i][j] == '1') {
	R[j]++;
    }
    int prv = 0;

    REP (s, 1<<N) {
	LL score = 0;
	REP (i, N) {
	    if (s>>i&1) {
		score += X[i];
	    } else {
		score -= X[i];
	    }
	}

	REP (i, N) if ((prv^s) >> i & 1) {
	    REP (j, M) if (S[i][j] == '1') {
		if (s>>i&1) {
		    R[j] -= 2;
		} else {
		    R[j] += 2;
		}
	    }
	}
	prv = s;

	REP (j, M) P[j] = make_pair(R[j], j);
	sort(P, P+M);
	REP (j, M) {
	    score += P[j].first * (j+1);
	}
	if (score > best) {
	    REP (j, M) {
		ans[P[j].second] = j+1;
	    }
	    best = score;
	}
    }

    rprintf("%d", ans, ans+M);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}