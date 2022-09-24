#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0; i<int(n); i++)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

struct SetSum {
    typedef int T;
    int N, M;
    vector<bool> zero;
    vector<T> all;
    vector<T> part;
    // all and zero are lazy
    SetSum(int N): N(N) {
	M = 1;
	for (; M<N;) M *= 2;
	all = part = vector<T>(M*2);
	zero = vector<bool>(M*2, false);
    }
    void force(int k) {
	if (zero[k]) {
	    if (k<M) zero[k*2] = zero[k*2+1] = true;
	    zero[k] = false;
	    all[k] = part[k] = 0;
	}
    }
    void add(int x, int y, T v) { add(x, y, 1, 0, M, v); }
    T add(int x, int y, int k, int l, int r, T v) {
	force(k);
	if (x<=l && r<=y) {
	    all[k] += v;
	} else if (x<r && l<y) {
	    part[k] = 0;
	    part[k] += add(x, y, k*2, l, (l+r)/2, v);
	    part[k] += add(x, y, k*2+1, (l+r)/2, r, v);
	}
	return (r-l)*all[k] + part[k];
    }
    void set(int x, int y, T v) {
	reset(x, y, 1, 0, M, 0);
	add(x, y, 1, 0, M, v);
    }
    void reset(int x, int y) { reset(x, y, 1, 0, M, 0); }
    T reset(int x, int y, int k, int l, int r, T v) {
	force(k);
	if (x<=l && r<=y) {
	    zero[k] = true;
	    all[k] = part[k] = 0;
	} else if (x<r && l<y) {
	    part[k] = 0;
	    part[k] += reset(x, y, k*2, l, (l+r)/2, v + all[k]);
	    part[k] += reset(x, y, k*2+1, (l+r)/2, r, v + all[k]);
	    all[k] = 0;
	} else {
	    force(k);
	    all[k] += v;
	}
	return (r-l)*all[k] + part[k];
    }
    T sum(int x, int y) { return sum(x, y, 1, 0, M); }
    T sum(int x, int y, int k, int l, int r) {
	force(k);
	if (r<=x || y<=l) return 0;
	if (x<=l && r<=y) return (r-l)*all[k] + part[k];
	return (min(y, r)-max(x, l)) * all[k] +
	    sum(x, y, k*2, l, (l+r)/2) +
	    sum(x, y, k*2+1, (l+r)/2, r);
    }
};

int N, M;
int L[300011], R[300011], X[300011];
int main() {
    scanf("%d%d", &N, &M);
    SetSum Z(N);
    REP (i, M) scanf("%d%d%d", L+i, R+i, X+i);
    for (int i=M; i--; ) {
        Z.set(L[i]-1, X[i]-1, X[i]);
        Z.set(X[i], R[i], X[i]);
    }

    REP (i, N) printf("%d%c", Z.sum(i, i+1), i==N-1 ? '\n' : ' ');

    return 0;
}