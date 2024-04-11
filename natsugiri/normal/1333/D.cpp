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

int N, K;
char S[3111];
vector<VI> ans, ans2;

void MAIN() {
    scanf("%d%d", &N, &K);
    scanf("%s", S);

    VI cur, nxt;
    REP (i, N-1) {
	if (S[i] == 'R' && S[i+1] == 'L') cur.push_back(i);
    }
    while (cur.size()) {
	ans.push_back(cur);
	EACH (e, cur) {
	    S[*e] = 'L';
	    S[*e+1] = 'R';
	}
	nxt.clear();
	EACH (e, cur) {
	    if (*e && S[*e-1] == 'R' && (nxt.empty() || nxt.back() != *e - 1)) nxt.push_back(*e-1);
	    if (S[*e+2] == 'L') nxt.push_back(*e+1);
	}
	swap(cur, nxt);
    }

    int least = ans.size();
    int most = 0;
    EACH (e, ans) most += e->size();
    if (least <= K && K <= most) {
	REP (i, ans.size()) {
	    ans2.push_back(VI());
	    REP (j, ans[i].size()) {
		if (j && least < K) {
		    ans2.push_back(VI());
		    least++;
		}
		ans2.back().push_back(ans[i][j]);
	    }
	}
	REP (i, ans2.size()) {
	    printf("%d", (int)ans2[i].size());
	    EACH (e, ans2[i]) printf(" %d", *e+1);
	    puts("");
	}
    } else {
	puts("-1");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}