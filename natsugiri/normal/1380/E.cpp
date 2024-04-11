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

int N, M;
VI S[200011];
int C[200011];
int name[200011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) {
	int a;
	scanf("%d", &a);
	a--;
	S[a].push_back(i);
	C[i] = a;
    }

    int diff = 0;
    REP (i, N-1) if (C[i] != C[i+1]) diff++;

    REP (i, N) name[i] = i;

    printf("%d\n", diff);

    REP ($, M-1) {
	int a_, b_;
	scanf("%d%d", &a_, &b_);
	a_--; b_--;
	int a = name[a_];
	int b = name[b_];

	if (S[a].size() < S[b].size()) {
	    swap(a, b);
	}

	EACH (e, S[b]) {
	    if (*e && C[*e-1] != C[*e]) diff--;
	    if (*e+1 < N && C[*e+1] != C[*e]) diff--;
	    C[*e] = a;
	    if (*e && C[*e-1] != C[*e]) diff++;
	    if (*e+1 < N && C[*e+1] != C[*e]) diff++;
	}
	S[a].insert(S[a].end(), S[b].begin(), S[b].end());
	S[b] = VI();

	name[a_] = a;

	printf("%d\n", diff);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}