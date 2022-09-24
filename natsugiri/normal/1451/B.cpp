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

int N, Q;
char S[111];
int sums[111];

void MAIN() {
    scanf("%d%d", &N, &Q);
    scanf("%s", S);
    REP (i, N) sums[i+1] = sums[i] + (S[i] == '1'? 1: 0);

    REP ($, Q) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--;

	bool yes = false;
	bool b0 = false, b1 = false;
	if (sums[x] < x) b0 = true;
	if (sums[x]) b1 = true;

	if (S[x] == '0' && b0) yes = true;
	if (S[x] == '1' && b1) yes = true;

	b0 = b1 = false;
	if (sums[N] - sums[y] < N - y) b0 = true;
	if (sums[N] - sums[y]) b1 = true;

	if (S[y-1] == '0' && b0) yes = true;
	if (S[y-1] == '1' && b1) yes = true;

	puts(yes? "YES": "NO");
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}