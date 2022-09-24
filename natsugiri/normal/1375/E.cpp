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
int A[1011];
pair<int, int> P[1011], Q[1011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
#ifdef LOCALX
    N = 100;
    REP (i, N) A[i] = rand() % 1000000;
    REP (i, N) eprintf("%d ", A[i]);
    eprintf("\n");
#endif


    REP (i, N) P[i] = Q[i] = make_pair(A[i], i);
    sort(P, P+N);

    vector<pair<int, int> > ans;
    VI E;
    vector<pair<pair<int, int>, int> > group;

    for (int r=N; r--;) {
#ifdef LOCALX
	REP (i, N) eprintf("(%d %d) ", Q[i].first, Q[i].second);
	eprintf(": %d\n", r);
#endif
	E.clear();
	group.clear();
	group.emplace_back(Q[r], r);
	int target = -1;
	REP (i, r) if (A[i] > A[r]) {
	    E.push_back(i);
	    group.emplace_back(Q[i], i);
	    if (Q[i] == P[r]) {
		target = i;
	    }
	}
	
	if (E.empty()) {
	    assert(P[r] == Q[r]);
	} else {
	    assert(target != -1);
	    sort(group.begin(), group.end());

	    REP (i, group.size()-1u) {
		int idx = group[i+1].second;
		swap(Q[idx], Q[r]);
		ans.emplace_back(idx, r);
	    }
	}
    }

    printf("%d\n", (int)ans.size());
    EACH (e, ans) {
	printf("%d %d\n", e->first+1, e->second+1);
    }
}

int main() {
    int TC = 1;
    //scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}