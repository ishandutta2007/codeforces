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

template<class T> inline void amin(T &a, T b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, T b) { if (a<b) a=b; }

typedef long long LL;
typedef vector<double> Arr;
typedef vector<Arr> Mat;

Mat identity(int n) {
    Mat r(n, Arr(n, 0));
    for (int i=0; i<n; i++) r[i][i] = 1;
    return r;
}

Mat mulMat(const Mat&a, const Mat&b) {
    int m=a.size(), n=a[0].size(), p=b[0].size();
    Mat r(m, Arr(p, 0));
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            for (int k=0; k<p; k++)
                r[i][k] += a[i][j] * b[j][k];
    return r;
}

Mat powMat(Mat a, LL b) {
    Mat r = identity(a.size());
    for (;b; b>>=1) {
	if (b&1) r = mulMat(r, a);
	a = mulMat(a, a);
    }
    return r;
}

Arr mulMatArr(const Mat&a, const Arr&x) {
    int m=a.size(), n=a[0].size();
    Arr r(m, 0);
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            r[i]+=a[i][j]*x[j];
    return r;
}

int N, K;
int A[111];
int main() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", A+i);
    Mat M(N*N, Arr(N*N));
    Arr X(N*N);

    double P = 1.0 / (N * (N+1.0) / 2.0);
    REP (l, N) {
	for (int r=l; r<N; r++) { // [l .. r]
	    REP (i, N) REP (j, N) {
		int ni = i, nj = j;
		if (l<=i && i<=r) ni = r+l-i;
		if (l<=j && j<=r) nj = r+l-j;
		M[ni * N + nj][i * N + j] += P;
	    }
	}
    }

    REP (i, N) REP (j, N) 
	if (A[i] < A[j]) X[i*N + j] = 1.0;

    M = powMat(M, K);
    Arr Z = mulMatArr(M, X);

    double ans = 0;
    REP (i, N) REP (j, N) if (i > j) ans += Z[i*N + j];
    printf("%.12f\n", ans);
    
    return 0;
}