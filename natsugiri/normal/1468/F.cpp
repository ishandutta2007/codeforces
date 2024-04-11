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

typedef unsigned long long ULL;

ULL gcd(ULL x, ULL y) {
    while (1) {
	if (x) y %= x; else return y;
	if (y) x %= y; else return x;
    }
}

int N;
pair<LL, LL> V[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	LL x, y, u, v;
	scanf("%lld%lld%lld%lld", &x, &y, &u, &v);
	x -= u;
	y -= v;
	LL g = gcd(abs(x), abs(y));
	V[i] = make_pair(x/g, y/g);
    }

    sort(V, V+N);
    LL ans = 0;
    REP (i, N) {
	auto p = equal_range(V, V+N, make_pair(-V[i].first, -V[i].second));
	ans += p.second - p.first;
    }

    printf("%lld\n", ans / 2);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}