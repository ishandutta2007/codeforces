#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
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

ULL gcd(ULL x, ULL y) {
    while (1) {
	if (x) y %= x; else return y;
	if (y) x %= y; else return x;
    }
}

int normal(int x) {
    int r = 1;
    for (int i=2; i*i<=x; i++) {
	if (x % i == 0) {
	    r *= i;
	    while (x % i == 0) x /= i;
	}
    }
    if (x > 1) r *= x;
    return r;
}

int N;
const int SIZE = 300111;
int A[SIZE];
int C[SIZE];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) C[A[i]] = 1;

    REP (i, N) A[i] = normal(A[i]);
    sort(A, A+N);
    N = unique(A, A+N) - A;
    REP (i, N) C[A[i]] = 1;

    int g = A[0];
    REP (i, N) g = gcd(g, A[i]);

    if (g != 1) {
	puts("-1");
	return;
    }
    if (A[0] == 1) {
	puts("1");
	return;
    }
    REP (i, SIZE-1) if (C[i] && C[i+1]) {
	puts("2");
	return;
    }

    REP (i, SIZE-1) if (C[i]) {
	for (int j=i+i; j<SIZE; j+=i) C[j] = 0;
    }

    N = 0;
    REP (i, SIZE) if (C[i]) A[N++] = i;
    memset(C, 0x3f, sizeof C);

    REP (i, N) C[A[i]] = 1;
    for (int t=SIZE-1; t>1; t--) if (C[t] < 200) {
	REP (i, N) {
	    int z = gcd(t, A[i]);
	    amin(C[z], C[t]+1);
	}
    }

    int ans = C[1];
    if (ans > 200) ans = -1;
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}