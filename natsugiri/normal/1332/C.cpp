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
char S[200011];

int C[26];

void MAIN() {
    scanf("%d%d", &N, &K);
    scanf("%s", S);

    int ans = 0;
    REP (i, K/2) {
	int cnt = 0;
	memset(C, 0, sizeof C);
	for (int j=0; j<N; j+=K) {
	    char a = S[j+i];
	    char b = S[j+K-1-i];
	    C[a-'a']++;
	    C[b-'a']++;
	    cnt+=2;
	}
	ans += cnt - *max_element(C, C+26);
    }

    if (K % 2 == 1) {
	int cnt = 0;
	memset(C, 0, sizeof C);
	for (int j=0; j<N; j+=K) {
	    char a = S[j+K/2];
	    C[a-'a']++;
	    cnt++;
	}
	ans += cnt - *max_element(C, C+26);
    }
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}