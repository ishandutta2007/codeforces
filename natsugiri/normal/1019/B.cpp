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

/*
1 2 1 2
3 4 3 2

1 2 1 2 3 2 1 2
3 4 3 4 5 4 3 2

3 2 1 2 3 4 3 4
5 4 3 2 1 2 1 2

3 4 3 4 5 4 3 2
1 2 1 2 3 2 1 2

2 1 2 3 2 1 2 3
4 3 4 5 4 3 2 1
*/


int N;
int H;
int A[100111];
int cnt;

void query(int pos) {
    cnt += 2;
    int x;
    printf("? %d\n", pos+1);
    fflush(stdout);
    scanf("%d", &x);
    A[pos] = x;

    printf("? %d\n", pos+1+H);
    fflush(stdout);
    scanf("%d", &x);
    A[pos+H] = x;
}

void answer(int pos) {
    printf("! %d\n", pos+1);
    fflush(stdout);
}

bool intersection(int a, int b, int c, int d) {
    if (a < c && b > d) return true;
    if (a > c && b < d) return true;
    return false;
}


void MAIN() {
    scanf("%d", &N);
    if (N % 4) {
	puts("! -1");
	return;
    }

    H = N/2;

    query(0);
    if (A[0] == A[H]) {
	answer(0);
	return;
    }

    int lo = 1, hi = H;
    while (hi-lo>1) {
	int mid = (lo+hi)/2;
	query(mid);
	if (A[mid] == A[mid+H]) {
	    answer(mid);
	    return;
	}
	if (intersection(A[lo-1], A[mid], A[lo-1+H], A[mid+H])) {
	    hi = mid;
	} else {
	    lo = mid+1;
	}
    }

    if (cnt + 2 <= 60) {
	query(lo);
	if (A[lo] == A[lo+H]) {
	    answer(lo);
	} else {
	    puts("! -1");
	}
    } else {
	answer(lo);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}