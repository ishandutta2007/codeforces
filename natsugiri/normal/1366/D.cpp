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

int N;
int A[500011];
int D1[500011];
int D2[500011];

const int MAX = 10000011;
int min_factor[MAX];
void make_prime() {
    for (int i=2; i<MAX; i+=2) min_factor[i] = 2;
    for (int i=3; i*i<MAX; i++) {
	if (min_factor[i] == 0) {
	    min_factor[i] = i;
	    for (int j=i*i; j<MAX; j+=i)
		if (min_factor[j] == 0) min_factor[j] = i;
	}
    }
    for (int i=2; i<MAX; i++) {
	if (min_factor[i] == 0) min_factor[i] = i;
    }
}

void MAIN() {
    make_prime();
    scanf("%d", &N);
    REP (i, N) {
	int a;
	scanf("%d", &a);
	int p = min_factor[a];
	D1[i] = 1;
	int m = a;
	while (p && m % p == 0) {
	    D1[i] *= p;
	    m /= p;
	}
	D2[i] = m;

	if (1 < D1[i] && D1[i] < a && 1 < D2[i] && D2[i] < a) {
	    // assert(__gcd(D1[i] + D2[i], a) == 1);
	} else {
	    D1[i] = D2[i] = -1;
	}
    }

    rprintf("%d", D1, D1+N);
    rprintf("%d", D2, D2+N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}