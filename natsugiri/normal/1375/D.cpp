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

int N;
int A[1011];
int C[1011];

bool ok() {
    REP (i, N-1) if (A[i] > A[i+1]) return false;
    return true;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    VI ans;
    while (!ok()) {
	REP (i, N+1) C[i] = 0;
	REP (i, N) C[A[i]]++;
	priority_queue<int, VI, greater<int> > Q;
	REP (i, N+1) if (C[i] == 0) Q.push(i);
	
	while (!Q.empty()) {
	    int v = Q.top();
	    Q.pop();
	    if (C[v]) continue;

	    int pos;
	    if (v == N) {
		pos = -1;
		REP (i, N) if (A[i] != i) {
		    pos = i;
		    break;
		}
		if (pos == -1) break;
	    } else {
		pos = v;
	    }

	    ans.push_back(pos);
	    C[A[pos]]--;
	    if (C[A[pos]] == 0) Q.push(A[pos]);
	    A[pos] = v;
	    C[v]++;
	}
    }

    printf("%d\n", (int)ans.size());
    EACH (e, ans) ++*e;
    rprintf("%d", ans.begin(), ans.end());
    // rprintf("%d", A, A+N);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}