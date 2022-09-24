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

template<class T> struct RXQ {
    int n;
    vector<T> A; vector<int> I;
    RXQ(int n_=0): n(n_), A(n), I(2*n) {
	for (int i=0; i<n; i++) I[i+n] = i;
	for (int i=n; --i;) I[i] = I[2*i];
    }
    RXQ(const vector<T> &a): n(a.size()), A(a), I(2*n) {
	for (int i=0; i<n; i++) I[i+n] = i;
	for (int i=n; --i;) I[i] = (A[I[i*2]] < A[I[i*2+1]]? I[i*2]: I[i*2+1]);
    }
    void modify(int i, const T &v) {
	A[i] = v;
	for (i+=n; i>>=1;) I[i] = (A[I[i*2]] < A[I[i*2+1]]? I[i*2+1]: I[i*2]);
    }
    int max_i(int x, int y) {
	x += n; y += n;
	int p = -1;
	for (; x<y; x>>=1, y>>=1) {
	    if (y & 1) { --y; if (p < 0 || A[p] < A[I[y]]) p = I[y]; }
	    if (x & 1) { if (p < 0 || A[p] < A[I[x]]) p = I[x]; x++; }
	}
	return p;
    }
    T max_v(int x, int y) { return A[max_i(x, y)]; }
};

int N;
int A[1000111];
const LL INF = 1LL<<60;

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    RXQ<LL> nega(vector<LL>(N, -INF)), posi(vector<LL>(N, -INF));
    LL ans = 0;
    REP (i, N) {
	LL tmp = 0;

	nega.modify(i, ans - A[i]);
	posi.modify(i, ans + A[i]);
	if (i) {
	    amax(tmp, nega.max_v(0, i) + A[i]);
	    amax(tmp, posi.max_v(0, i) - A[i]);
	}
	amax(ans, tmp);
    }

    printf("%lld\n", ans);

    return 0;
}