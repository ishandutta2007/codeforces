#pragma GCC optimize("O3")
#pragma GCC target("sse4.2")
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

int main() {
    scanf("%d%d", &N, &K);

    if (N <= 3) {
	puts("-1");
    } else if (K == 2) {
	if (N == 4) {
	    puts("-1");
	} else {
	    printf("%d\n", 2 * N - 5);
	    puts("1 2");
	    puts("2 3");
	    puts("3 4");
	    for (int i=5; i<=N; i++) {
		printf("1 %d\n", i);
		printf("4 %d\n", i);
	    }
	}
    } else if (K == 3) {
	if (N == 4) {
	    puts("3");
	    puts("1 2");
	    puts("2 3");
	    puts("3 4");
	} else {
	    printf("%d\n", (N-4)*3 + 1);
	    puts("3 4");
	    for (int i=5; i<=N; i++) {
		printf("1 %d\n", i);
		printf("2 %d\n", i);
		printf("3 %d\n", i);
	    }
	}
    } else {
	puts("-1");
    }

    return 0;
}