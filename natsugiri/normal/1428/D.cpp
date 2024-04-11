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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N;
int A[100011];
vector<pair<int, int> > ans, stk, stkH;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    bool yes = true;

    for (int i=N; i--;) {
	if (A[i] == 0) {

	} else if (A[i] == 1) {
	    ans.emplace_back(i, i);
	    stk.emplace_back(i, i);
	} else if (A[i] == 2) {
	    if (stk.empty()) {
		yes = false;
	    } else {
		auto p = stk.back();
		stk.pop_back();
		ans.emplace_back(p.first, i);
		stkH.emplace_back(p.first, i);
	    }
	} else {
	    if (stk.empty() && stkH.empty()) {
		yes = false;
	    } else if (!stkH.empty()) {
		auto p = stkH.back();
		stkH.pop_back();
		ans.emplace_back(i, i);
		ans.emplace_back(i, p.second);
		stkH.emplace_back(i, i);
	    } else {
		auto p = stk.back();
		stk.pop_back();
		ans.emplace_back(i, i);
		ans.emplace_back(i, p.second);
		stkH.emplace_back(i, i);
	    }
	}
    }

    if (yes) {
	printf("%d\n", (int)ans.size());
	REP (i, ans.size()) {
	    printf("%d %d\n", ans[i].first+1, ans[i].second+1);
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