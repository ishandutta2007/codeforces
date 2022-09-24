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

struct Seg {
    int len;
    int d6[4][6];
    int d7[4][7];
    int d8[4][8];
    int d9[4][9];
    int d10[4][10];

    Seg() : len(0) {
	reset();
    }
    Seg(int v) : len(1) {
	reset();
	d6[v][0]++;
	d7[v][0]++;
	d8[v][0]++;
	d9[v][0]++;
	d10[v][0]++;
    }

    void reset() {
	memset(d6, 0, sizeof d6);
	memset(d7, 0, sizeof d7);
	memset(d8, 0, sizeof d8);
	memset(d9, 0, sizeof d9);
	memset(d10, 0, sizeof d10);
    }
};

const Seg unit = Seg();
Seg operator*(const Seg &x, const Seg &y) {
    if (x.len == 0) return y;
    if (y.len == 0) return x;

    Seg z = x;
    z.len = x.len + y.len;
    REP (c, 4) REP (i, 6) z.d6[c][(i+x.len) % 6] += y.d6[c][i];
    REP (c, 4) REP (i, 7) z.d7[c][(i+x.len) % 7] += y.d7[c][i];
    REP (c, 4) REP (i, 8) z.d8[c][(i+x.len) % 8] += y.d8[c][i];
    REP (c, 4) REP (i, 9) z.d9[c][(i+x.len) % 9] += y.d9[c][i];
    REP (c, 4) REP (i, 10) z.d10[c][(i+x.len) % 10] += y.d10[c][i];
    return z;
};

struct SegmentTree {
    int n;
    vector<Seg> d;
    SegmentTree(int n_=0): n(n_), d(2*n) { }
    SegmentTree(const vector<Seg> & d_): n(d_.size()), d(2*n) {
	for (int i=0; i<n; i++) d[i+n] = d_[i];
	for (int i=n; --i; ) d[i] = d[i*2] * d[i*2+1];
    }
    void modify(int i, const Seg &s) {
	i += n;
	d[i] = s;
	for (i/=2; i; i/=2) d[i] = d[i*2] * d[i*2+1];
    }
    Seg query(int x, int y) {
	x += n; y += n;
	Seg ls = unit, rs = unit;
	for (; x < y; x>>=1, y>>=1) {
	    if (y & 1) rs = d[--y] * rs;
	    if (x & 1) ls = ls * d[x++];
	}
	return ls * rs;
    }
};
int N;
char S[100111];
int A[100111];
int B[100111];

int enc(char c) {
    if (c == 'A') return 0;
    if (c == 'T') return 1;
    if (c == 'G') return 2;
    if (c == 'C') return 3;
    return -1;
}

void MAIN() {

    scanf("%s", S);
    N = strlen(S);
    REP (i, N) A[i] = enc(S[i]);

    SegmentTree X(vector<Seg>(A, A+N));

    int Q;
    scanf("%d", &Q);
    REP ($, Q) {
	char op[11];
	scanf("%s", op);
	if (*op == '1') {
	    int x;
	    char c[11];
	    scanf("%d%s", &x, c);
	    x--;
	    X.modify(x, Seg(enc(c[0])));
	} else {
	    int l, r;  char E[37];
	    scanf("%d%d%s", &l, &r, E);
	    l--;
	    int len = strlen(E);
	    Seg s = X.query(l, r);

	    int ans = 0;

	    if (len == 1 || len == 2 || len == 4 || len == 8) {
		REP (i, len) {
		    int c = enc(E[i]);
		    for (int j=i; j<8; j+=len) {
			ans += s.d8[c][j];
		    }
		}
	    } else if (len == 3 || len == 6) {
		REP (i, len) {
		    int c = enc(E[i]);
		    for (int j=i; j<6; j+=len) {
			ans += s.d6[c][j];
		    }
		}
	    } else if (len == 5 || len == 10) {
		REP (i, len) {
		    int c = enc(E[i]);
		    for (int j=i; j<10; j+=len) {
			ans += s.d10[c][j];
		    }
		}
	    } else if (len == 7) {
		REP (i, len) {
		    int c = enc(E[i]);
		    ans += s.d7[c][i];
		}
	    } else if (len == 9) {
		REP (i, len) {
		    int c = enc(E[i]);
		    ans += s.d9[c][i];
		}
	    }

	    printf("%d\n", ans);
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}