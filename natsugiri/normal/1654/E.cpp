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
const int MAX_LEN = 200011;
// LL[];
void radix_sort_ll(LL *x, LL *x_end) {
    typedef unsigned long long ULL;
    static ULL y[MAX_LEN], *y_end;
    static unsigned c[256];
    int i, n = x_end - x;
    ULL *p;
    if (n <= 64 || MAX_LEN < n) {
	sort(x, x_end);
    } else {
#define RADIX_SORT_STEP(X, Y, KEY) \
	memset(c, 0, sizeof c); \
	for (i=n, p=(ULL*)X; i--; ++p) c[(KEY)&255]++; \
	for (i=0; i<255; i++) c[i+1] += c[i]; \
	for (i=n, p=(ULL*)X##_end; --p, i--;) Y[--c[(KEY)&255]] = *p;

	y_end = y + n;
	RADIX_SORT_STEP(x, y, *p);
	RADIX_SORT_STEP(y, x, *p>>8);
	RADIX_SORT_STEP(x, y, *p>>16);
	RADIX_SORT_STEP(y, x, *p>>24);
	RADIX_SORT_STEP(x, y, *p>>32);
	RADIX_SORT_STEP(y, x, *p>>40);
	RADIX_SORT_STEP(x, y, *p>>48);
	RADIX_SORT_STEP(y, x, *p>>56 ^ 128);
#undef RADIX_SORT_STEP
    }
}

int N;
LL A[100011];

#ifdef LOCALx
const int MAGIC = 3;
#else
const int MAGIC = 350;
#endif

int ans;

vector<LL> g;
void update(bool add) {

    // sort(g.begin(), g.end());
    radix_sort_ll(g.data(), g.data() + g.size());
    int cnt = 0;
    REP (j, g.size()) {
	if (j == 0 || g[j-1] != g[j]) {
	    cnt = 1;
	} else {
	    cnt++;
	}
	amax(ans, cnt + add);
    }
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", A+i);

    if (N == 1 || N == 2) {
	puts("0");
	return;
    }

    REP (i, N) {
	g.clear();

	for (int j=i+1; j<N && j<i+MAGIC; j++) {
	    LL tmp = A[j] - A[i];
	    if (tmp % (j-i) == 0) {
		g.push_back(tmp / (j-i));
	    }
	}

	update(true);
    }

    for (LL d=-MAGIC; d<=MAGIC; d++) {
	g.clear();
	REP (i, N) g.push_back(A[i] + i * d);
	update(false);
    }

    printf("%d\n", N - ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}