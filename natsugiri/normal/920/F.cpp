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

int D[1000111];
void init() {
    for (int i=1; i<1000111; i++) {
	for (int j=i; j<1000111; j+=i) {
	    D[j]++;
	}
    }
}

const int SIZE = 1<<19;
struct Seg {
    LL sum;
    int rest;
} S[SIZE*2];

void build(int a[], int n) {
    REP (i, n) {
	S[i+SIZE].sum = a[i];
	S[i+SIZE].rest = 1;
    }
    for (int i=n; i<SIZE; i++) {
	S[i+SIZE].sum = 0;
	S[i+SIZE].rest = 0;
    }
    for (int i=SIZE; --i;) {
	S[i].sum = S[i*2].sum + S[i*2+1].sum;
	S[i].rest = S[i*2].rest + S[i*2+1].rest;
    }
}
void replace(int x, int y, int k, int l, int r) {
    if (S[k].rest == 0) {
    } else if (y <= l || r <= x) {
    } else if (l+1 >= r) {
	S[k].sum = D[S[k].sum];
	S[k].rest = (S[k].sum > 2 ? 1 : 0);
    } else if (S[k].rest) {
	replace(x, y, k*2, l, (l+r)/2);
	replace(x, y, k*2+1, (l+r)/2, r);
	S[k].sum = S[k*2].sum + S[k*2+1].sum;
	S[k].rest = S[k*2].rest + S[k*2+1].rest;
    }
}
LL sum(int x, int y, int k, int l, int r) {
    if (y <= l || r <= x) {
	return 0;
    } else if (x <= l && r <= y) {
	return S[k].sum;
    } else {
	return sum(x, y, k*2, l, (l+r)/2) + sum(x, y, k*2+1, (l+r)/2, r);
    }
}

int N, M;
int A[300111];

void MAIN() {
    init();

    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", A+i);

    build(A, N);

    REP ($, M) {
	char op[4];
	int L, R;
	scanf("%s%d%d", op, &L, &R);
	L--;
	if (*op == '1') {
	    replace(L, R, 1, 0, SIZE);
	} else {
	    LL ans = sum(L, R, 1, 0, SIZE);
	    printf("%lld\n", ans);
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}