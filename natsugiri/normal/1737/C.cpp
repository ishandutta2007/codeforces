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


int Rs[3];
int Cs[3];
void MAIN() {
    int N;
    scanf("%d", &N);
    REP (i, 3) scanf("%d%d", Rs+i, Cs+i);
    sort(Rs, Rs+3);
    sort(Cs, Cs+3);
    int R = Rs[1];
    int C = Cs[1];

    int X, Y;
    scanf("%d%d", &X, &Y);

    bool yes = false;
    if ((R == 1 || R == N) && (C == 1 || C == N)) {
	yes = (X == R || Y == C);
    } else {
	yes = ((R-X) % 2 == 0 || (C-Y) % 2 == 0);
    }
    puts(yes?"YES":"NO");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}