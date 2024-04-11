#include<stack>
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
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }


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

int N, A[100011], Q;
int B[100011];
int main() {
    scanf("%d%d", &N, &Q);
    REP (i, N) scanf("%d", A+i);

    REP (i, N-1) B[i] = abs(A[i+1] - A[i]);

    IRXQ<int> rxq(VI(B, B+N));
    
    REP ($, Q) {
	int L, R;
	scanf("%d%d", &L, &R);
	
	stack<int> le, ri;
	le.push(L-1); ri.push(R-1);
	LL ans = 0;
	while (!le.empty()) {
	    L = le.top(); le.pop();
	    R = ri.top(); ri.pop();
	    int i = rxq.max_i(L, R);
	    ans += (LL)B[i] * (i-L+1) * (R-i);

	    if (L < i) { le.push(L); ri.push(i); }
	    if (i+1 < R) { le.push(i+1); ri.push(R); }
	}

	printf("%lld\n", ans);

    }
    
    return 0;
}