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
int C[1000011];
int D[1000011];

void add(int h, int w) {
    if (h == 0 || w == 0) return;
    int len=1;
    for (int i=1; i<h+w; i++) {
	D[i] += len;
	if (i < w) len++;
	if (i >= h) len--;
    }
}

void MAIN() {
    scanf("%d", &N);
    int ma = 0;
    REP (i, N) {
	int x;
	scanf("%d", &x);
	C[x]++;
	amax(ma, x);
    }

    for (int h=1; h*h<=N; h++) {
	if (N % h == 0) {
	    int w = N / h;
	    int y = ma, x = 0;
	    if (y >= h) {
		int d = y - h + 1;
		y -= d;
		x += d;
	    }

	    while (x < w && y >= 0) {
		memset(D, 0, sizeof (int) * (ma + 1));
		add(x, y+1);
		add(w-x, y);
		add(x+1, h-y-1);
		add(w-x-1, h-y);
		D[0]++;

		bool yes = true;
		REP (i, ma+1) if (C[i] != D[i]) {
		    yes = false;
		    break;
		}

		if (yes) {
		    printf("%d %d\n", h, w);
		    printf("%d %d\n", y+1, x+1);
		    return;
		}
		y--; x++;
	    }
	}
    }

    puts("-1");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}