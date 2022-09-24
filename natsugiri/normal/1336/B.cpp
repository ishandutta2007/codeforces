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

void read(int n, vector<LL> &v) {
    v.resize(n);
    REP (i, n) scanf("%lld", &v[i]);
    sort(v.begin(), v.end());
}

LL sq(LL x) { return x * x; }

vector<LL> R, G, B;
LL eval(int r, int g, int b) {
    return sq(R[r] - G[g]) + sq(G[g] - B[b]) + sq(B[b] - R[r]);
}

LL ans;
void solve() {
    int r = 0, g = 0, b = 0;
    for (; g<(int)G.size(); g++) {
	while (r+1 < (int)R.size() && R[r+1] <= G[g]) r++;
	while (b+1 < (int)B.size() && B[b] < G[g]) b++;
	LL tmp = eval(r, g, b);
	amin(ans, tmp);
    }
}

void MAIN() {
    {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	read(a, R);
	read(b, G);
	read(c, B);
    }
    ans = eval(0, 0, 0);

    solve();
    swap(R, B);
    solve();

    swap(R, G);
    solve();
    swap(R, B);
    solve();

    swap(R, G);
    solve();
    swap(R, B);
    solve();

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}