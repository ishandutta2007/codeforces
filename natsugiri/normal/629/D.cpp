#include<cmath>
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

template<class T> struct RXQ {
    int n;
    vector<T> A; vector<int> I;
    RXQ(int n_=0): n(n_), A(n), I(2*n) {
	for (int i=0; i<n; i++) I[i+n] = i;
	for (int i=n; --i;) I[i] = I[2*i];
    }
    RXQ(const vector<T> &a): n(a.size()), A(a), I(2*n) {
	for (int i=0; i<n; i++) I[i+n] = i;
	for (int i=n; --i;) I[i] = (A[I[i*2]] < A[I[i*2+1]]? I[i*2+1]: I[i*2]);
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

const double PI = acos(-1);
int N, R[100111], H[100111];
int id[100111];
pair<LL, int> P[100111];

LL vol(int i) {
    return (LL)R[i] * R[i] * H[i];
}
int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d%d", R+i, H+i);

    REP (i, N) P[i] = make_pair(vol(i), -i);
    sort(P, P+N);
    
    REP (i, N) id[-P[i].second] = i;
    RXQ<LL> X(N);
    REP (i, N) {
	LL g = X.max_v(0, id[i]+1);
	X.modify(id[i], g + vol(i));
    }

    LL ans = X.max_v(0, N);
    printf("%.9f\n", ans * PI);
    return 0;
}