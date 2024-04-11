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

int N, K, X;
int A[100111];

const int SIZE = 1024;
int buf[2][SIZE];
int *cur = buf[0], *nxt = buf[1];

int main() {
    scanf("%d%d%d", &N, &K, &X);
    REP (i, N) scanf("%d", A+i);

    REP (i, N) cur[A[i]]++;
    REP (t, K) {
	memset(nxt, 0, sizeof (int) * SIZE);
	int cnt = 0;
	REP (i, SIZE) {
	    int a = 0, b = 0;
	    if (cnt & 1) {
		a = cur[i] / 2;
		b = cur[i] - a;
	    } else {
		b = cur[i] / 2;
		a = cur[i] - b;
	    }
	    cnt += cur[i];
	    nxt[i] += b;
	    nxt[i^X] += a;
	}

	swap(cur, nxt);
    }

    int ma = -1, mi = -1;
    REP (i, SIZE) if (cur[i]) {
	if (mi == -1) mi = i;
	ma = i;
    }
    printf("%d %d\n", ma, mi);

    return 0;
}