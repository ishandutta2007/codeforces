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

int hh, mm;
int H, D, C, N;

void MAIN() {
    scanf("%d %d %d %d %d %d", &hh, &mm, &H, &D, &C, &N);

    int t = 0;
    {
	int h = hh; 
	int m = mm;
	while (h < 20) {
	    while (m < 60) {
		t++;
		m++;
	    }
	    m = 0;
	    h++;
	}
    }


    double ans = (H+N-1) / N * C;

    double ans2 = (H + t * D + N - 1) / N * C * 0.8;
    
    printf("%.9f\n", min(ans, ans2));

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}