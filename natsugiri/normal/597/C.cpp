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
struct Fenwick : vector<T> {
    typedef vector<T> S;
    int N;
    Fenwick(int N_=0): S(N_), N(N_) {}
    void add(int i, T x) {
	for (; i<N; i|=i+1) S::operator[](i) += x;
    }
    T sum(int r) {
	    T s = 0;
	    for (; r; r&=r-1) s += S::operator[](r-1);
	    return s;
    }
    T sum(int l, int r) {
	if (l==0) {
	    T s = 0;
	    for (; r; r&=r-1) s += S::operator[](r-1);
	    return s;
	} else {
	    return sum(0, r) - sum(0, l);
	}
    }
};

int N, K, A[100111];
Fenwick<LL> F[11];
int main() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", A+i), A[i]--;

    REP (i, K) F[i] = Fenwick<LL>(N);
    LL ans = 0;
    if (K == 0) {
	ans = N;
    } else {
	REP (i, N) {
	    F[0].add(A[i], 1);
	    REP (d, K-1) F[d+1].add(A[i], F[d].sum(A[i]));
	    ans += F[K-1].sum(A[i]);
	}
    }
    printf("%lld\n", ans);
    return 0;
}