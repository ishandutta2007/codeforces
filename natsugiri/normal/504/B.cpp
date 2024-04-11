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

template<class T>
struct Fenwick : vector<T> {
    typedef vector<T> S;
    const int n;
    Fenwick() : S() {}
    Fenwick(int _n) : S(_n), n(_n) {}
    void add(int i, T x) {
	for (; i<n; i|=i+1) S::operator[](i) += x;
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

int N;
VI P, Q;

int main() {
    scanf("%d", &N);
    P.resize(N); Q.resize(N);
    REP (i, N) scanf("%d", &P[i]);
    REP (i, N) scanf("%d", &Q[i]);

    VI R;
    Fenwick<int> PF(N), QF(N);

    int c = 0;
    REP (i, N) {
	int k = N-i-1;
	int x = (PF.sum(0, P[k]) + QF.sum(0, Q[k])) + c;
	PF.add(P[k], 1);
	QF.add(Q[k], 1);
	R.push_back(x % (i+1));
	c = x / (i+1);
    }
    //REP (j, R.size()) printf("%d%c", R[j], j+1 == (int)R.size() ? '\n' : ' ');
    
    reverse(R.begin(), R.end());

    Fenwick<int> RF(N);
    REP (i, R.size()) {
	int k = R[i];
	int lo = 0, hi = N;
	while (hi-lo>1) {
	    int m=(lo+hi)/2;
	    if (RF.sum(0, m)+k < m) hi = m;
	    else lo = m;
	}
	R[i] = lo;
	RF.add(lo, 1);
    }

    REP (j, R.size()) printf("%d%c", R[j], j+1 == (int)R.size() ? '\n' : ' ');

    return 0;
}