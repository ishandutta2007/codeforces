#include<deque>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }


// <O(nlogn), O(1)>
template<class T>
struct IRMQ {
    vector<T> A;
    vector<vector<int> > M;
    IRMQ(){}
    IRMQ(const vector<T> &A_): A(A_) {
	int N = A.size(), LOGN = __lg(N)+1;
	M.resize(LOGN);
	for (int i=0; i<LOGN; i++) M[i].resize(N);
	for (int j=0; j<N; j++) M[0][j] = j;
	for (int i=0; i<LOGN-1; i++)
	    for (int j=0; j+(1<<i)<N; j++)
		if (A[M[i][j+(1<<i)]] < A[M[i][j]]) M[i+1][j] = M[i][j+(1<<i)];
		else M[i+1][j] = M[i][j];
    }
    T min_v(int l, int r) { // assert(0 <= l < r <= N)
	return A[min_i(l, r)];
    }
    int min_i(int l, int r) {
	int d = __lg(r-l);
	if (A[M[d][r-(1<<d)]] < A[M[d][l]]) return M[d][r-(1<<d)];
	else return M[d][l];
    }
};


template<class T>
struct IRXQ {
    vector<T> A;
    vector<vector<int> > X;
    IRXQ(){}
    IRXQ(const vector<T> &A_): A(A_) {
	int N = A.size(), LOGN = __lg(N)+1;
	X.resize(LOGN);
	for (int i=0; i<LOGN; i++) X[i].resize(N);
	for (int j=0; j<N; j++) X[0][j] = j;
	for (int i=0; i<LOGN-1; i++)
	    for (int j=0; j+(1<<i)<N; j++)
		if (A[X[i][j]] < A[X[i][j+(1<<i)]]) X[i+1][j] = X[i][j+(1<<i)];
		else X[i+1][j] = X[i][j];
    }
    T max_v(int l, int r) { // assert(0 <= l < r <= N)
	return A[max_i(l, r)];
    }
    int max_i(int l, int r) {
	int d = __lg(r-l);
	if (A[X[d][l]] < A[X[d][r-(1<<d)]]) return X[d][r-(1<<d)];
	else return X[d][l];
    }
};

int N, K;
int V[1000111], R[1000111];
long double C[1000111];


int main() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", V+i), V[i] *= 100;
    REP (i, N) scanf("%d", R+i);

    IRXQ<int> VM(VI(V, V+N));
    IRMQ<int> RM(VI(R, R+N));

    for (int i=0; i<N; i++) {
	int lo = i+1, hi = N;
	while (hi - lo > 1) {
	    int mid = (lo + hi) / 2;
	    if (VM.max_v(i, mid) < RM.min_v(i, mid)) {
		lo = mid;
	    } else {
		hi = mid;
	    }
	}

	int c = max(
		min(VM.max_v(i, lo), RM.min_v(i, lo)),
		min(VM.max_v(i, hi), RM.min_v(i, hi)));
	C[i] = c;
    }

    sort(C, C+N);
    long double ans = 0;
    long double rate = 1.0;
    rate = (long double) K / N;
    REP (i, N-K+1) {
	ans += rate * C[i];
	rate = rate / (N-i-1) * (N-K-i);
    }
    printf("%.9f\n", (double)ans);


    return 0;
}