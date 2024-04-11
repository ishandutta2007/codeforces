#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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
string S, T;
char buf[10011];

int link[10011];
int dp[10011][10011];
// 400 MB;

void MAIN() {
    scanf("%s", buf);
    S = buf;
    scanf("%s", buf);
    T = buf;

    memset(link, -1, sizeof link);

    {
	VI stk;
	REP (i, S.size()) {
	    if (S[i] == '.') {
		if (stk.size()) {
		    link[i] = stk.back();
		    stk.pop_back();
		}
	    } else {
		stk.push_back(i);
	    }
	}
    }

    memset(dp, 0x3f, sizeof dp);
    const int INF = dp[0][0];
    dp[0][0] = 0;

    REP (i, S.size()) {
	if (S[i] == '.') {
	    if (link[i] != -1) {
		REP (j, T.size()+1) {
		    amin(dp[i+1][j], dp[link[i]][j]);
		}
	    }
	} else {
	    REP (j, T.size()) {
		if (S[i] == T[j]) {
		    amin(dp[i+1][j+1], dp[i][j]);
		}
	    }
	}

	// del;
	REP (j, T.size()+1) {
	    amin(dp[i+1][j], dp[i][j] + 1);
	}
    }

    int ans = dp[S.size()][T.size()];
    printf("%d\n", ans);
    assert(ans != INF);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}