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
int A[101];
char buf[101];

int main() {
    scanf("%d%d", &N, &K);
    REP (i, N) A[i] = i;
    REP (i, N-K+1) {
	scanf("%s", buf);
	if (buf[0] == 'N') {
	    A[i+K-1] = A[i];
	}
    }

    REP (i, N) {
	printf("%c%c%c",'A' + A[i] / 26, 'a' + A[i] % 26, i==N-1?'\n':' ');
    }

    return 0;
}