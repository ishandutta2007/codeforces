#include<cmath>
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

int N;
char buf[100111];
int A[100111];

int main() {
    scanf("%s", buf);
    int n = strlen(buf);
    REP (i, n) A[n-1-i] += buf[i] - '0';
    scanf("%s", buf);
    int m = strlen(buf);
    REP (i, m) A[m-1-i] -= buf[i] - '0';

    int k = max(n, m);

    for (int i=k-1; i>=2; i--) {
	if (abs(A[i]) <= 2) {
	    A[i-1] += A[i];
	    A[i-2] += A[i];
	} else {
	    if (A[i] > 0) puts(">");
	    else puts("<");
	    return 0;
	}
    }

    if (A[0] == 0 && A[1] == 0) {
	puts("=");
    } else {
	double x = (sqrt(5.0) + 1) * 0.5 * A[1] + A[0];
	if (x > 0) puts(">");
	else puts("<");
    }

    return 0;
}