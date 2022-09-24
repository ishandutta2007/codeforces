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
int M;
int A[300011];
int B[300011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    scanf("%d", &M);
    REP (i, M) scanf("%d", B+i);

    int ans = 0;
    LL cur = A[0];
    int i = 1, j = 0;
    while (1) {
	if (cur == 0) {
	    ans++;
	    if (i == N) break;
	    cur = A[i++];
	    continue;
	} else if (cur > 0) {
	    if (j == M) break;
	    cur -= B[j++];
	    continue;
	} else {
	    if (i == N) break;
	    cur += A[i++];
	    continue;
	}
    }

    if (i == N && j == M && cur == 0) {
	printf("%d\n", ans);
    } else {
	puts("-1");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}