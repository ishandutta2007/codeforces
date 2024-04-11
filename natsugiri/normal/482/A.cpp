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

int N, K;
int A[100111];

int main() {
    scanf("%d%d", &N, &K);
    int pos = 0, lo = 1, hi = N;
    A[pos++] = lo++;
    while (K > 1) {
	A[pos++] = hi--;
	K--;
	if (K == 1) {
	    while (pos < N) A[pos++] = hi--;
	    break;
	}
	A[pos++] = lo++;
	K--;
    }
    while (pos < N) A[pos++] = lo++;

    rprintf("%d", A, A+N);

    return 0;
}