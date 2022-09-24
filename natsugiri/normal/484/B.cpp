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
int A[200111];
const int MAX = 2000111;
int C[MAX];
int Prev[MAX];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) C[A[i]] = 1;

    int last = -1;
    REP (i, MAX) {
	Prev[i] = last;
	if (C[i]) last = i;
    }

    int ans = 0;
    REP (i, MAX) if (C[i]) {
	for (int j=i; j<MAX; j+=i) if (Prev[j] > i) {
	    amax(ans, Prev[j] % i);
	}
    }

    printf("%d\n", ans);

    return 0;
}