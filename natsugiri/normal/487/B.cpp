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
template<class T> struct RMQ {
    int n;
    vector<T> A; vector<int> I;
    RMQ(int n_=0): n(n_), A(n), I(2*n) {
	for (int i=0; i<n; i++) I[i+n] = i;
	for (int i=n; --i;) I[i] = I[2*i];
    }
    RMQ(const vector<T> &a): n(a.size()), A(a), I(2*n) {
	for (int i=0; i<n; i++) I[i+n] = i;
	for (int i=n; --i;) I[i] = (A[I[i*2+1]] < A[I[i*2]]? I[i*2+1]: I[i*2]);
    }
    void modify(int i, const T &v) {
	A[i] = v;
	for (i+=n; i>>=1;) I[i] = (A[I[i*2+1]] < A[I[i*2]]? I[i*2+1]: I[i*2]);
    }
    int min_i(int x, int y) {
	x += n; y += n;
	int p = -1;
	for (; x<y; x>>=1, y>>=1) {
	    if (y & 1) { --y; if (p < 0 || A[I[y]] < A[p]) p = I[y]; }
	    if (x & 1) { if (p < 0 || A[I[x]] < A[p]) p = I[x]; x++; }
	}
	return p;
    }
    T min_v(int x, int y) { return A[min_i(x, y)]; }
};

template<class T>
struct IRMXQ {
    vector<T> A;
    vector<vector<int> > M, X;
    IRMXQ(){}
    IRMXQ(const vector<T> &A_): A(A_) {
	int N = A.size(), LOGN = __lg(N)+1;
	M.resize(LOGN); X.resize(LOGN);
	for (int i=0; i<LOGN; i++) { M[i].resize(N); X[i].resize(N); }
	for (int j=0; j<N; j++) M[0][j] = X[0][j] = j;
	for (int i=0; i<LOGN-1; i++) {
	    for (int j=0; j+(1<<i)<N; j++) {
		if (A[M[i][j+(1<<i)]] < A[M[i][j]]) M[i+1][j] = M[i][j+(1<<i)];
		else M[i+1][j] = M[i][j];
		if (A[X[i][j]] < A[X[i][j+(1<<i)]]) X[i+1][j] = X[i][j+(1<<i)];
		else X[i+1][j] = X[i][j];
	    }
	}
    }
    T min_v(int l, int r) { // assert(0 <= l < r <= N)
	return A[min_i(l, r)];
    }
    int min_i(int l, int r) {
	int d = __lg(r-l);
	if (A[M[d][r-(1<<d)]] < A[M[d][l]]) return M[d][r-(1<<d)];
	else return M[d][l];
    }
    T max_v(int l, int r) {
	return A[max_i(l, r)];
    }
    int max_i(int l, int r) {
	int d = __lg(r-l);
	if (A[X[d][l]] < A[X[d][r-(1<<d)]]) return X[d][r-(1<<d)];
	else return X[d][l];
    }
};


int N, S, L;
int A[100111];

int main() {
    scanf("%d%d%d", &N, &S, &L);
    REP (i, N) scanf("%d", A+i);

    IRMXQ<int> R(VI(A, A+N));
    RMQ<int> F(VI(N+10, N+10));

    F.modify(0, 0);

    for (int i=L, j=0; i<=N; i++) {
	while (R.max_v(j, i) - R.min_v(j, i) > S) {
	    j++;
	}
	if (j <= i-L) {
	    int mi = F.min_v(j, i-L+1);
	    F.modify(i, mi + 1);
	}
    }

    int ans = F.min_v(N, N+1);
    if (ans <= N) printf("%d\n", ans);
    else puts("-1");
    return 0;
}