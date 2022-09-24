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
int A[100011];
int B[100011];
int last[100011];
bool use[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    memset(last, -1, sizeof last);
    REP (i, N) last[A[i]] = i;

    priority_queue<int, VI, greater<int> > Q;
    REP (i, N+1) if (last[i] == -1) Q.push(i);

    bool yes = true;
    VI pool;
    int idx = 0;

    REP (i, N) {
	if (A[i] < idx) {
	    yes = false;
	    break;
	}

	if (A[i] != idx) {
	    if (Q.empty()) {
		yes = false;
		break;
	    } else {
		B[i] = Q.top();
		Q.pop();
		use[B[i]] = true;
		while (use[idx]) idx++;
	    }

	    if (A[i] != idx) {
		yes = false;
		break;
	    }
	} else {
	    if (Q.empty()) {
		B[i] = 1000000;
	    } else {
		B[i] = Q.top();
		Q.pop();
		use[B[i]] = true;
		while (use[idx]) idx++;
	    }
	}

	if (last[A[i]] == i) {
	    Q.push(A[i]);
	}
    }

    if (yes) {
	rprintf("%d", B, B+N);
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