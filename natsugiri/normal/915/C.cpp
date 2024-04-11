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
char A[21], B[21];
bool LE() {
    REP (i, N) {
	if (A[i] > B[i]) return false;
	if (A[i] < B[i]) return true;
    }
    return true;
}

void MAIN() {
    scanf("%s%s", A, B);
    N = strlen(A);
    if (N < (int)strlen(B)) {
	sort(A, A+N);
	reverse(A, A+N);
    } else {
	REP (i, N) {
	    for (int d=10; d>=0; d--) {
		int pos = find(A+i, A+N, d+'0') - A;
		if (pos == N) continue;
		swap(A[i], A[pos]);
		sort(A+i+1, A+N);
		if (LE()) break;
	    }
	}
    }
    puts(A);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}