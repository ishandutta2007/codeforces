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

unsigned gcd(unsigned x, unsigned y) {
    if (!x || !y) return 0;

    while (1) {
	if (x) y %= x; else return y;
	if (y) x %= y; else return x;
    }
}

int N, Q;

const int SIZE = 1<<19;
unsigned D[SIZE*2];
void build() {
    for (int i=SIZE; --i;) D[i] = gcd(D[i*2], D[i*2+1]);
}

int X, Y, G;

int intersect(int l, int r) {
    return max(0, min(Y, r) - max(X, l));
}

int get_left(int l, int r, int k) {
    if (D[k] && D[k] % G == 0) {
	return intersect(l, r);
    }

    if (l+1 == r) {
	return 0;
    }

    int m = (l+r)/2;
    if (X < m) {
	int p = get_left(l, m, k*2);
	if (m < Y && p == intersect(l, m)) {
	    p += get_left(m, r, k*2+1);
	}
	return p;
    } else {
	return get_left(m, r, k*2+1);
    }
}

int get_right(int l, int r, int k) {
    if (D[k] && D[k] % G == 0) {
	return intersect(l, r);
    }

    if (l+1 == r) {
	return 0;
    }

    int m = (l+r)/2;
    if (m < Y) {
	int p = get_right(m, r, k*2+1);
	if (X < m && p == intersect(m, r)) {
	    p += get_right(l, m, k*2);
	}
	return p;
    } else {
	return get_right(l, m, k*2);
    }
}

void update(int i, unsigned y) {
    i += SIZE;
    D[i] = y;
    for (i>>=1; i; i>>=1) {
	D[i] = gcd(D[i*2], D[i*2+1]);
    }
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%u", D+SIZE+i);
    build();

    scanf("%d", &Q);
    REP ($, Q) {
	char op[11];
	scanf("%s", op);
	if (*op == '1') {
	    int l, r, x;
	    scanf("%d%d%d", &l, &r, &x);
	    l--;
	    X = l;
	    Y = r;
	    G = x;
	    int len = get_left(0, SIZE, 1) + get_right(0, SIZE, 1);
	    if (len + 1 >= Y - X) puts("YES");
	    else puts("NO");
	} else {
	    int i;
	    unsigned y;
	    scanf("%d%u", &i, &y);
	    i--;
	    update(i, y);
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}