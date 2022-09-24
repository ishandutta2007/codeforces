#include<random>
#include<chrono>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}


const int LIMIT = 30;
int N;
int A[LIMIT];
int idx[1000111];

int Z[1000111];

int test_a;
int test_d;
int test_ma;
const int TEST_N = 1000000;
void init() {
#ifdef LOCAL
    REP (i, 20) rand();
    test_a = rand() % 100 + 1;
    test_d = rand() % 800 + 1;
    Z[0] = test_a;
    REP (i, TEST_N-1) Z[i+1] = Z[i] + test_d;
    test_ma = Z[TEST_N-1];
    eprintf("%d %d %d\n", test_a, test_d, test_ma);
#endif
}
int I(int i) {
#ifdef LOCAL
    return Z[i];
#else
    printf("? %d\n", i+1);
    fflush(stdout);
    scanf("%d", &i);
    return i;
#endif
}

int X(int x) {
#ifdef LOCAL
    return test_ma > x;
#else
    printf("> %d\n", x);
    fflush(stdout);
    scanf("%d", &x);
    return x;
#endif
}

LL seed() {
    int *a = new int();
    //eprintf("%lld\n", (LL)a);

    using namespace chrono;
    LL t = high_resolution_clock::now().time_since_epoch().count();
    //eprintf("%lld\n", t);
    return (LL)a^t;
}

mt19937 engine(seed());

void MAIN() {
#ifdef LOCAL
    init();
    N = TEST_N;
#else
    scanf("%d", &N);
#endif

    int ansX, ansD;

    if (N <= 60) {
	REP (i, N) A[i] = I(i);
	sort(A, A+N);
	ansX = A[0];
	ansD = A[1] - A[0];
    } else {
	REP (i, N) idx[i] = i;
	shuffle(idx, idx+N, engine);
	REP (i, LIMIT) A[i] = I(idx[i]);
	sort(A, A+LIMIT);
	int g = 0;
	REP (i, LIMIT-1) g = __gcd(g, A[i+1] - A[0]);

	LL high = min(A[0] + (LL)(N-1)*g, 1000000000LL);

	LL ma = A[LIMIT-1];
	for (int t=29; t>=0; t--) {
	    LL be = ma + g * (1LL<<t) - 1;
	    if (be <= high && X(be)) {
		ma = be + 1;
	    }
	}
	ansX = ma - (N-1)*g;
	ansD = g;
    }

    printf("! %d %d\n", ansX, ansD);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}