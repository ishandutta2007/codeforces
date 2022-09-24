#include<bitset>
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

const int SIZE = 1<<14;
typedef bitset<SIZE> Bits;

int N, Q;

VI segs[2*SIZE];
void add_(int x, int y, int v, int l, int r, int k) {
    if (y <= l || r <= x) {
    } else if (x <= l && r <= y) {
	segs[k].push_back(v);
    } else {
	add_(x, y, v, l, (l+r)/2, k*2);
	add_(x, y, v, (l+r)/2, r, k*2+1);
    }
}
void add(int x, int y, int v) {
    add_(x, y, v, 0, SIZE, 1);
}

Bits B[SIZE*2];
Bits ans;
void rec(int k) {
    EACH (e, segs[k]) {
	B[k] |= B[k] << *e;
    }
    if (SIZE <= k) {
	ans |= B[k];
    } else {
	B[k*2] = B[k*2+1] = B[k];
	rec(k*2);
	rec(k*2+1);
    }
}

void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, Q) {
	int l, r, x;
	scanf("%d%d%d", &l, &r, &x);
	l--;
	add(l, r, x);
    }


    B[1].set(0);
    rec(1);

    VI output;
    for (int i=1; i<=N; i++) {
	if (ans.test(i)) output.push_back(i);
    }

    printf("%d\n", (int)output.size());
    rprintf("%d", output.begin(), output.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}