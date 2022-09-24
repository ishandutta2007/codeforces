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
char S[111];

bool ok(int A, int B, int C) {
    int sum = 0;
    REP (i, N) {
	int m = 0;
	if (S[i] == 'A') m = A;
	if (S[i] == 'B') m = B;
	if (S[i] == 'C') m = C;

	if (m == 0) return false;
	sum += m;
	if (sum < 0) return false;
    }

    return sum == 0;
}

void MAIN() {
    scanf("%s", S);
    N = strlen(S);

    bool yes = false;
    if (!yes && ok(+1, +1, -1)) yes = true;
    if (!yes && ok(+1, -1, +1)) yes = true;
    if (!yes && ok(-1, +1, +1)) yes = true;

    if (!yes && ok(-1, -1, +1)) yes = true;
    if (!yes && ok(-1, +1, -1)) yes = true;
    if (!yes && ok(+1, -1, -1)) yes = true;

    puts(yes? "YES": "NO");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}