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

int N;
int M;
int A[100011];

LL sum;
LL F(int i) {
    LL ret = 0;
    if (i && A[i-1] != A[i]) ret += (LL)i * (N-i);
    if (i+1 < N && A[i] != A[i+1]) ret += (LL)(i+1) * (N-i-1);
    return ret;
}

void modify(int i, int x) {
    sum -= F(i);
    A[i] = x;
    sum += F(i);
}

void MAIN() {
    scanf("%d%d", &N, &M);
    sum = (LL)N * (N+1) / 2;
    REP (i, N) {
	int x;
	scanf("%d", &x);
	modify(i, x);
    }

    REP ($, M) {
	int pos, val;
	scanf("%d%d", &pos, &val);
	pos--;
	modify(pos, val);
	printf("%lld\n", sum);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}