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

string S, T;
char buf[10011];

void MAIN() {
    scanf("%s", buf); S = buf;
    scanf("%s", buf); T = buf;

    bool yes = false;
    REP (c, T.size()) {
	bool p = true;
	for (int k=0; c+k<(int)T.size() && 0 <= c-k; k++) {
	    if (T[c+k] != T[c-k]) p = false;
	}
	if (p) {
	    REP (i, S.size()) if (T[c] == S[i]) {
		bool test = true;
		for (int k=0; c+k<(int)T.size() || 0 <= c-k; k++) {
		    if (c+k < (int)T.size()) {
			if (i-k < 0) { test = false; break; }
			if (T[c+k] != S[i-k]) { test = false; break; }
		    }
		    if (0 <= c-k) {
			if (i-k < 0) { test = false; break; }
			if (T[c-k] != S[i-k]) { test = false; break; }
		    }
		}
		if (test) {
		    yes = true;
		    goto OUT;
		}
	    }
	}
    }

OUT:
    puts(yes? "YES": "NO");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}