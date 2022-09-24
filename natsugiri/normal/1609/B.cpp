#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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

int N, Q;
char S[100011];

int abc(int i) {
    if (i < 0) return 0;
    if (N <= i+2) return 0;
    return (S[i] == 'a' && S[i+1] == 'b' && S[i+2] == 'c')? 1: 0;
}

void MAIN() {
    scanf("%d%d%s", &N, &Q, S);

    int sum = 0;
    REP (i, N-2) sum += abc(i);

    REP ($, Q) {
	int pos;
	char c[11];
	scanf("%d%s", &pos, c);
	pos--;
	sum -= abc(pos-2);
	sum -= abc(pos-1);
	sum -= abc(pos);
	S[pos] = c[0];
	sum += abc(pos-2);
	sum += abc(pos-1);
	sum += abc(pos);
	printf("%d\n", sum);
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}