#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
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
char S[5011];

void MAIN() {
    scanf("%d", &N);
    scanf("%s", S);
    string best = S;
    int bestk = 1;
    for (int k=2; k<=N; k++) {
	string tmp;
	for (int i=k-1; i<N; i++) tmp.push_back(S[i]);
	if ((N-k) % 2 == 0) {
	    for (int i=k-2; i>=0; i--) tmp.push_back(S[i]);
	} else {
	    REP (i, k-1) tmp.push_back(S[i]);
	}
	if (best > tmp) {
	    best = tmp;
	    bestk = k;
	}
    }

    printf("%s\n%d\n", best.c_str(), bestk);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}