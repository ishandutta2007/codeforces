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
char S[100011];
int C[26];

void MAIN() {
    scanf("%d%d%s", &N, &K, S);
    sort(S, S+N);

    if (K == 1) {
	puts(S);
	return;
    }

    memset(C, 0, sizeof C);
    REP (i, N) C[S[i]-'a']++;

    vector<pair<int, char> > V;
    REP (i, 26) if (C[i]) {
	V.emplace_back(C[i], i+'a');
    }

    if (V.size() == 1u) {
	REP (a, (N+K-1)/K) putchar(S[0]);
	putchar('\n');
	return;
    }

    if (V.size() == 2u && V[0].first == K) {
	putchar(V[0].second);
	REP (a, (N-1)/K) putchar(V[1].second);
	putchar('\n');
	return;
    }

    if (V[0].first < K) {
	putchar(S[K-1]);
	putchar('\n');
	return;
    }

    puts(S+K-1);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}