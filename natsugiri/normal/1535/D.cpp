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

int K;
char S[(1<<18)+11];

int PA(int i) {
    int x = (1<<K)-1 - i;
    x /= 2;
    return (1<<K)-1 - x;
}
int LE(int i) {
    int x = (1<<K)-1 - i;
    x = 2*x+1;
    return (1<<K)-1 - x;
}
int RI(int i) {
    int x = (1<<K)-1 - i;
    x *= 2;
    return (1<<K)-1 - x;
}


int half;
int P[1<<18];

void modify(int i, char c) {
    S[i] = c;

    while (1) {
	if (i < half) {
	    if (S[i] == '0') P[i] = 1;
	    if (S[i] == '1') P[i] = 1;
	    if (S[i] == '?') P[i] = 2;
	} else {
	    if (S[i] == '0') P[i] = P[LE(i)];
	    if (S[i] == '1') P[i] = P[RI(i)];
	    if (S[i] == '?') P[i] = P[LE(i)] + P[RI(i)];
	}

	i = PA(i);
	if (i == (1<<K)-1) break;
    }
}

void MAIN() {
    scanf("%d%s", &K, S);

    
    half = 1<<(K-1);

    REP (i, (1<<K)-1) {
	modify(i, S[i]);
    }

    int Q;
    scanf("%d", &Q);
    REP ($, Q) {
	int a;
	static char b[11];
	scanf("%d%s", &a, b);
	a--;
	modify(a, *b);
	printf("%d\n", P[(1<<K)-2]);
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}