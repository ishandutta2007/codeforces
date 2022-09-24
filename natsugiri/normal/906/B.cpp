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
2413

24135

123
456
789

246
813
579

1234
5678
9abc

1234
5278
9a3c

123
456

24
6?5

1234
5678

2468
7531

1234
5678


261
483


12345
6789a
bcdef

24135
68a79
cebdf

13524
68a79

12
34
56
78
*/


int N, M;
int A[100111];
VI V[100111];

void eo() {
    puts("YES");
    int val = 2;
    REP (i, N) REP (j, M) {
	if (val > (LL)N*M) val = 1;
	printf("%d%c", val, " \n"[j==M-1]);
	val += 2;
    }
}

void MAIN() {
    scanf("%d%d", &N, &M);

    if (N == 1 && M == 1) {
	puts("YES");
	puts("1");
    } else if (N+M == 3) {
	puts("NO");
    } else if (N+M == 4) {
	puts("NO");
    } else if (min(N, M) == 2 && max(N, M) == 3) {
	puts("NO");
    } else if (N == 3 && M == 3) {
	puts("YES");
	puts("4 9 2");
	puts("3 5 7");
	puts("8 1 6");
    } else {
	bool transpose = N > M;
	if (transpose) swap(N, M);
	if (M % 2) {
	    REP (i, N) {
		V[i].reserve(M);
		int s = i%2;
		REP (t, M) {
		    if (s >= M) s = 1-i%2;
		    int v = (transpose? s*N + i + 1: i*M + s + 1);
		    V[i].push_back(v);
		    s += 2;
		}
	    }
	} else {
	    REP (i, N) {
		V[i].reserve(M);
		int s = 1;
		REP (t, M) {
		    if (s >= M) s = 0;
		    int v = (transpose? s*N + i + 1: i*M + s + 1);
		    V[i].push_back(v);
		    s += 2;
		}
		if (i & 1) reverse(V[i].begin(), V[i].end());
	    }
	}

	puts("YES");
	if (transpose) {
	    REP (j, M) REP (i, N) printf("%d%c", V[i][j], " \n"[i==N-1]);
	} else {
	    REP (i, N) rprintf("%d", V[i].begin(), V[i].end());
	}
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}