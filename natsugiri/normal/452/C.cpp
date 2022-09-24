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

int N, M;

int main() {

    scanf("%d%d", &N, &M);
    if (N == 1) {
	puts("1.0");
	return 0;
    }

    double p = 0;
    double r = 1.0 / N;

    REP (i, N-1) {
	r = r / (N*M-i) * (N*M-M-i);
    }
    r *= M;
    r *= (double)N / (N*M-N+1);

    for (int k=1; k<=N && k<=M; k++) {
	// p += (double) k * k / N * nCk(M, k) * nCk(N*M-M, N-k) / nCk(N*M, N);
	p += r * k * k;
	r = r * (M - k) / (k + 1);
	r = r / (N*M-M-(N-k-1)) * (N-k);
    }
    printf("%.9f\n", p);


    return 0;
}