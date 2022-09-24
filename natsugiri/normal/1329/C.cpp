#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>

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

int H, G, A[1<<21];

void MAIN() {
    scanf("%d%d", &H, &G);
    for (int i=1; i<(1<<H); i++) scanf("%d", A+i);
    for (int i=1<<H; i<(2<<H); i++) A[i] = 0;

    priority_queue<pair<int, int> > Q;
    Q.emplace(A[1], 1);
    VI ans;
    while (Q.size()) {
	const int pos = Q.top().second;
	Q.pop();
	int v = pos;
	while (A[v*2] || A[v*2+1]) {
	    if (A[v*2] > A[v*2+1]) v = v*2;
	    else v = v*2+1;
	}

	if (v < (1<<G)) {
	    if (A[pos*2]) Q.emplace(A[pos*2], pos*2);
	    if (A[pos*2+1]) Q.emplace(A[pos*2+1], pos*2+1);
	} else {
	    ans.push_back(pos);
	    v = pos;
	    while (A[v*2] || A[v*2+1]) {
		if (A[v*2] > A[v*2+1]) {
		    A[v] = A[v*2];
		    v = v*2;
		} else {
		    A[v] = A[v*2+1];
		    v = v*2+1;
		}
	    }
	    A[v] = 0;
	    Q.emplace(A[pos], pos);
	}
    }

    LL sum = 0;
    REP (i, 1<<G) sum += A[i];
    printf("%lld\n", sum);
    rprintf("%d", ans.begin(), ans.end());
    // rprintf("%d", A+1, A+(1<<G));
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}