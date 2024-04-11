#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<cmath>

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

int query(VI L, VI R) {
    printf("? %d %d\n", (int)L.size(), (int)R.size());
    REP (i, L.size()) L[i]++;
    rprintf("%d", L.begin(), L.end());
    REP (i, R.size()) R[i]++;
    rprintf("%d", R.begin(), R.end());
    fflush(stdout);

    int ret;
    scanf("%d", &ret);
    return ret;
}

void answer(VI ans) {
    printf("! %d", (int)ans.size());
    REP (i, ans.size()) printf(" %d", ans[i]+1);
    puts("");
    fflush(stdout);
}

int idx[2011];
VI L, R;
char S[2011];

void MAIN() {
    scanf("%d", &N);

    int first;
    L.clear();
    L.push_back(0);
    for (int i=1; i<N; i++) {
	R.clear();
	R.push_back(i);
	int q = query(L, R);
	if (q == 0) {
	    L.push_back(i);
	} else {
	    first = i;
	    break;
	}
    }

    VI tmp = L;
    while (tmp.size() >= 2u) {
	int n = tmp.size();
	L.assign(tmp.begin()+n/2, tmp.end());
	int q = query(L, R);
	if (q == 0) {
	    REP (i, L.size()) tmp.pop_back();
	}  else {
	    swap(tmp, L);
	}
    }

    VI ans;
    int second = tmp[0];
    REP (i, N) {
	if (i == first) {
	} else if (i == second) {
	} else if (i < first) {
	    ans.push_back(i);
	} else {
	    L.clear();
	    L.push_back(i);
	    int q = query(L, R);
	    if (q == 0) ans.push_back(i);
	}
    }

    answer(ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}