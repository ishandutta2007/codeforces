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

string S, T;
char buf[1011];
int dp[411];

void MAIN() {
    scanf("%s", buf);
    S = buf;
    scanf("%s", buf);
    T = buf;

    bool yes = false;
    REP (sep, T.size()+1u) {
	memset(dp, 0xc0, sizeof dp);
	dp[0] = sep;
	REP (i, S.size()) {
	    for (int a=sep; a>=0; a--) {
		int b = dp[a];
		if (b < 0) continue;

		if (a < sep && S[i] == T[a]) {
		    amax(dp[a+1], b);
		}
		if (b < (int)T.size() && S[i] == T[b]) {
		    amax(dp[a], b+1);
		}
	    }
	}

	if (dp[sep] == (int)T.size()) {
	    yes = true;
	    break;
	}
    }

    puts(yes? "YES": "NO");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}