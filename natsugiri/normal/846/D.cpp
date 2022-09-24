#include<deque>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N, M, K, Q;
int F[511][511];
const int INF = 0x3f3f3f3f;

template<class T> struct SlideMinimum : deque<T> {
    typedef deque<T> S; // S[0] <= S[1] <= ..
    SlideMinimum(): S() {}
    const T& min() { return S::front(); } // you can call [0]
    void push(const T &x) {
	while (!S::empty() && x < S::back()) S::pop_back();
	S::push_back(x);
    }
    bool pop_one(const T &x) {
	if (!S::empty() && x == S::front()) {
	    S::pop_front();
	    return true;
	} else {
	    return false;
	}
    }
};
void MAIN() {
    scanf("%d%d%d%d", &N, &M, &K, &Q);

    memset(F, 0x3f, sizeof F);

    REP ($, Q) {
	int x, y, c;
	scanf("%d%d%d", &x, &y, &c);
	x--; y--;
	amin(F[x][y], c);
    }

    SlideMinimum<int> S;
    int ans = INF;
    REP (i, N-K+1) {
	// [i, i+K)
	S.clear();

	REP (j, K-1) {
	    for (int t=i; t<i+K; t++) {
		S.push(-F[t][j]);
	    }
	}

	for (int j=K-1; j<M; j++) {
	    for (int t=i; t<i+K; t++) {
		S.push(-F[t][j]);
	    }

	    amin(ans, -S.min());

	    for (int t=i; t<i+K; t++) {
		S.pop_one(-F[t][j-K+1]);
	    }
	}
    }

    if (ans == INF) ans = -1;
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}