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
char S[100011];

void go(int y, int x, int &y1, int &x1, char c) {
    if (c == 'U') {
	y1 = y + 1;
	x1 = x;
    } else {
	y1 = y;
	x1 = x + 1;
    }
}

void MAIN() {
    scanf("%d%s", &N, S);
    int ans = 0;
    if (N >= 3) {
	int x = 0, y = 0;
	int x1, y1, x2, y2;
	go(y, x, y1, x1, S[0]);
	go(y1, x1, y2, x2, S[1]);
	for (int i=2; i<=N; i++) {
	    if (y1 == x1 && (x<y) != (x2<y2)) {
		ans++;
	    }
	    y = y1; x = x1;
	    y1 = y2; x1 = x2;
	    go(y2, x2, y2, x2, S[i]);
	}

    }
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}