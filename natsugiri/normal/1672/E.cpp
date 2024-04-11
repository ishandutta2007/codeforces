#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<map>

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

int L[2000] = {5, 2, 7, 3, 5, 6};
void init() {
#ifdef LOCAL
    N = 6;
    // N = 2000;
    // REP (i, N) L[i] = rand() % 1000 + 1000;
#endif
}

map<int, int> mp;
int ans;

int cnt;

int query(const int w) {
    auto it = mp.find(w);
    if (it != mp.end()) return it->second;

    cnt++;
    printf("? %d\n", w);
    fflush(stdout);

    int ret = 0;

#ifdef LOCAL
    int width = -1;
    REP (i, N) {
	if (w < L[i]) {
	    ret = 0;
	    break;
	} else if (width >= L[i]) {
	    width -= L[i];
	    width--;
	} else {
	    width = w - L[i] - 1;
	    ret++;
	}
    }
    
#else
    scanf("%d", &ret);
#endif

    if (ret) {
	amin(ans, w * ret);
    }
    eprintf("ret = %d\n", ret);
    return mp[w] = ret;
}

int X[(1<<22)+1];

void MAIN() {
#ifdef LOCAL
    init();
#else
    scanf("%d", &N);
#endif
    ans = 1<<30;

    int lo = 0, hi = 1<<22;
    while (hi - lo > 1) {
	int mid = (lo + hi) / 2;
	int q = query(mid);
	if (q == 1) hi = mid;
	else lo = mid;
    }

    memset(X, 0x3f, sizeof X);
    REP (b, N) {
	int m = hi - b;
	for (int i=1; i*i<=m; i++) if (m % i == 0) {
	    if (i > b) amin(X[m / i], m);
	    if (m/i > b) amin(X[i], m);
	}
    }

    for (int w=hi; w>=1; w--) {
	if (X[w] < ans) {
	    int q = query(w);
	    if (q == 0) break;
	}
    }

    printf("! %d\n", ans);
    fflush(stdout);
    eprintf("cnt = %d\n", cnt);

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}