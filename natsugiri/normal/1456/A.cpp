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

int N, P, K;
char S[100011];

int X, Y;
LL C[100011];
void MAIN() {
    scanf("%d%d%d", &N, &P, &K);
    scanf("%s", S);
    scanf("%d%d", &X, &Y);

    for (int i=N; i--;) {
	int j = i + K;
	if (N <= j) C[i] = 0;
	else C[i] = C[j];
	if (S[i] == '0') C[i] += X;
    }

    LL ans = 1LL<<60;
    REP (i, N+1) {
	if (N-i < P) break;
	LL tmp = (LL)i * Y;
	int j = P + i - 1;
	if (j < N) tmp += C[j];

	amin(ans, tmp);
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}