#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N;
char S[100011];

void MAIN() {
    scanf("%d", &N);
    scanf("%s", S);

    int zero = count(S, S+N, '0');
    char ans = 0;

    if (zero == 0) {
	ans = 'D';
    } else if (N % 2 == 0) {
	ans = 'B';
    } else if (S[N/2] == '1') {
	ans = 'B';
    } else if (zero == 1) {
	ans = 'B';
    } else {
	ans = 'A';
    }

    if (ans == 'A') puts("ALICE");
    else if (ans == 'B') puts("BOB");
    else if (ans == 'D') puts("DRAW");
    else assert(false);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}