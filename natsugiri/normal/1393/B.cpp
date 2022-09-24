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

int N, Q;
int C[100011];
int B[9];

void add(int a, int sgn) {
    B[min(8, C[a])]--;
    C[a] += sgn;
    B[min(8, C[a])]++;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	int a;
	scanf("%d", &a);
	add(a, 1);
    }

    scanf("%d", &Q);
    REP ($, Q) {
	char op[11];
	int a;
	scanf("%s%d", op, &a);
	add(a, *op == '+'? 1: -1);

	bool yes = false;
	if (B[8]) yes = true;
	else if (B[4] + B[5] + B[6] + B[7] >= 2) yes = true;
	else if (B[6] + B[7]) {
	    yes = B[2] + B[3];
	} else if (B[4] + B[5]) {
	    yes = (B[2] + B[3] >= 2);
	}

	puts(yes? "YES": "NO");
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}