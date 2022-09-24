#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<cmath>

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


int N, K;
int A[100011];
int B[100011];
int hit;
int cnt;

void init() {
    hit = rand() % N;
    REP (i, N) A[i] = K;
}

void go() {
    REP (j, N) B[j] = 0;
    REP (j, N) {
	if (j == hit) {
	    B[(j+1)%N] += A[j];
	} else {
	    B[(j-1+N)%N] += A[j]/2;
	    B[(j+1)%N] += (A[j]+1)/2;
	}
    }
    REP (j, N) A[j] = B[j];
}


bool use[100011];

int query(int x) {
    cnt++;
    x %= N;
    if (x < 0) x += N;
    printf("? %d\n", x+1);
    fflush(stdout);

#ifdef LOCAL
    int ret = A[x];
    //rprintf("%d", A, A+N);
    //printf("ret %d\n", ret);
    go();
    return ret;
#else

    int ret;
    scanf("%d", &ret);
    return ret;
#endif
}

void answer(int x) {
    x %= N;
    printf("! %d\n", x+1);
    fflush(stdout);

#ifdef LOCAL
    eprintf("answer %d, count %d\n", hit+1, cnt);
    assert(x == hit);
    assert(cnt <= 1000);
#endif
}

const int WASTE = 300;

void MAIN() {
    scanf("%d%d", &N, &K);

#ifdef LOCAL
    init();
#endif

    REP (i, WASTE) {
	query(0);
    }

    int step = sqrt(N);

    int lo, hi;
    int x = 0;
    for (int i=0; ; i++) {
	x += step;
	x %= N;
	while (use[x]) {
	    x++;
	    if (x == N) x = 0;
	}
	use[x] = true;

	int q = query(x);
	if (q < K) {
	    lo = x;
	    hi = x + min((N-2)/2, WASTE + i);
	    break;
	} else if (q > K) {
	    hi = x;
	    lo = x - min((N-2)/2, WASTE + i);
	    break;
	}
    }

    while (lo < 0) {
	lo += N;
	hi += N;
    }
    while (lo < hi) {
	int mid = (lo + hi) / 2;
	int q = query(mid);

	if (q < K) {
	    lo = mid + 1;
	} else if (K < q) {
	    hi = mid - 1;
	} else {
	    lo = hi = mid;
	}
    }

    answer(lo);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}