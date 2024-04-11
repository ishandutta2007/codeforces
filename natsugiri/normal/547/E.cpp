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

class SAIS {
public: 
    vector<int> sa, lcp, rank;
    SAIS(const string &str_) : str(str_) {
	N = str.size()+1;
	S = vector<int>(N, 0);
	for (int i=0; i<N; i++) S[i] = str[i];
	*this = SAIS(S, 256);
    }
    SAIS(const vector<int> &S_, int A_SIZE_, bool b=true/* rank, lcp */) : S(S_), A_SIZE(A_SIZE_) {
	buildSA();
	if (b) buildLCP();
    }
private:
    string str;
    vector<int> S;
    int A_SIZE;
    int N;
    vector<int> t, B;
    enum { STYPE, LTYPE };

    inline bool is_lms(int i) {
	return i>0 && t[i] == STYPE && t[i-1] == LTYPE;
    }
    void bucket() {
	B = vector<int>(A_SIZE);
	for (int i=0; i<N; i++) B[S[i]]++;
	for (int i=0; i<A_SIZE-1; i++) B[i+1] += B[i];
    }
    void induced_sort() {
	bucket();
	for (int i=0; i<N; i++) {
	    int j = sa[i]-1;
	    if (j >= 0 && S[j] >= S[j+1]) sa[B[S[j]-1]++] = j;
	}
	bucket();
	for (int i=N; i--; ) {
	    int j = sa[i]-1;
	    if (j >= 0 && S[j] <= S[j+1]) sa[--B[S[j]]] = j;
	}
    }
    void buildSA() {
	N = S.size();
	sa.assign(N, -1);
	if (N == 1) {
	    sa[0] = 0;
	    return;
	}
	t.assign(N, STYPE);
	for (int i=N-1; i--;)
	    if (S[i] > S[i+1] || (S[i] == S[i+1] && t[i+1] == LTYPE))
		t[i] = LTYPE;
	bucket();
	for (int i=N; i--;)
	    if (is_lms(i)) sa[--B[S[i]]] = i;
	induced_sort();

	int N1 = 0;
	for (int i=0; i<N; i++) if (is_lms(sa[i])) sa[N1++] = sa[i];

	fill(sa.begin()+N1, sa.end(), -1);
	int name = 0, prev = -1;
	for (int i=0; i<N1; i++) {
	    int cur = sa[i];
	    bool diff = (prev == -1);
	    for (int j=0; !diff; j++) {
		if (j>0 && is_lms(cur+j)) break;
		if (S[cur+j] != S[prev+j]) diff = true;
	    }
	    if (diff) name++;
	    sa[N1+cur/2] = name-1;
	    prev = cur;
	}
	vector<int> S1, sa1(N1);
	for (int i=N1; i<N; i++) if (sa[i]>=0) S1.push_back(sa[i]);
	if (name == N1) for (int i=0; i<N1; i++) sa1[S1[i]] = i;
	else sa1 = SAIS(S1, name, false).sa;

	N1 = 0;
	for (int i=0; i<N; i++) if (is_lms(i)) S1[N1++] = i;
	for (int i=0; i<N1; i++) sa1[i] = S1[sa1[i]];

	fill(sa.begin(), sa.end(), -1);
	bucket();
	for (int i=N1; i--;) {
	    int j = sa1[i];
	    sa[--B[S[j]]] = j;
	}
	induced_sort();
//	eprintf("%d %d -- \n", N, N1);
    }
    void buildLCP() {
	rank.resize(N);
	lcp.resize(N-1);
	for (int i=0; i<N; i++) rank[sa[i]] = i;
	int h = 0;
	for (int i=0; i<N-1; i++) {
	    int j = sa[rank[i]-1];
	    if (h>0) h--;
	    for (; j+h<N && i+h<N && S[j+h] == S[i+h]; h++) ;
	    lcp[rank[i]-1] = h;
	}
    }

public:
    IRMQ<int> rmq;
    int common_prefix(int x, int y) {
	if (x == y) return N-1-x;
	if (y >= N-1) return 0;
	if (rank[x] > rank[y]) swap(x, y);
	return rmq.min_v(rank[x], rank[y]);
    }
//private:
    void buildRMQ() {
	rmq = IRMQ<int>(lcp);
    }
};

template<class T>
struct Fenwick : vector<T> {
    typedef vector<T> S;
    int N;
    Fenwick(int N_=0): S(N_), N(N_) {}
    void add(int i, T x) {
	for (; i<N; i|=i+1) S::operator[](i) += x;
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
    int lower_bound(T x) { // argmin_i x <= sum(0,i)
	int i = 1, j = 0;
	T s = T();
	while (i<N) i<<=1;
	for (; i; i>>=1) {
	    if (i+j <= N && s + S::operator[](i+j-1) < x) {
		s += S::operator[](i+j-1);
		j += i;
	    }
	}
	return j;
    }
};


// Given A[0 .. N-1]
// Queries l r k => #[ A[i] < k | i in [l, r)]
vector<int> KQUERY(const vector<int> &A, const vector<int> &L, const vector<int> &R, const vector<int> &K) {
    int N = A.size(), Q = L.size();
    vector<pair<int, int> > Ai(N), Kq(Q);
    for (int i=0; i<N; i++) Ai[i] = make_pair(A[i], i);
    for (int q=0; q<Q; q++) Kq[q] = make_pair(K[q], q);
    sort(Ai.begin(), Ai.end()); sort(Kq.begin(), Kq.end());
    Fenwick<int> F(N);
    vector<int> ret(Q);
    for (int q=0, i=0; q<Q; q++) {
	int x = Kq[q].second;
	while (i < N && Ai[i].first < Kq[q].first) F.add(Ai[i++].second, 1);
	ret[x] = F.sum(L[x], R[x]);
    }
    return ret;
}

int N, Q;
int L[200111], idx[500111];
char buf[200111];
VI S;

int main() {
    scanf("%d%d", &N, &Q);

    int l = 0;
    REP (i, N) {
	scanf("%s", buf);
	L[i] = strlen(buf);
	REP (j, L[i]) {
	    S.push_back(buf[j] - 'a' + 1);
	    idx[l++] = i;
	}
	S.push_back(i + 27);
	idx[l++] = -1;
    }
    S.push_back(0); // ????
    idx[l++] = -1;

//    eprintf("%d\n", N+29);
//    EACH (e, S) eprintf("%d ", *e); eprintf("\n");

    SAIS X(S, N+29); X.buildRMQ();

//    REP (i, X.sa.size()) eprintf("%d\t%d\n", X.sa[i], S[X.sa[i]]);

    VI Lr(N), Rr(N);
    int su = 0;
    REP (i, N) {
	int lo, hi;
	lo = 0; hi = X.rank[su];
	while (hi - lo > 1) {
	    int m = (hi + lo) / 2;
	    if (X.common_prefix(su, X.sa[m]) < L[i]) lo = m;
	    else hi = m;
	}
	Lr[i] = hi;
	lo = X.rank[su]; hi = S.size();
	while (hi - lo > 1) {
	    int m = (hi + lo) / 2;
	    if (X.common_prefix(su, X.sa[m]) >= L[i]) lo = m;
	    else hi = m;
	}
	Rr[i] = hi;
	su += L[i] + 1;
//	eprintf("%d : %d %d\n", L[i], Lr[i], Rr[i]);
    }

    VI A(S.size(), 2*N + 256), Lq, Rq, Kq;

    REP (i, S.size()) {
	if (idx[i] != -1) A[X.rank[i]] = idx[i];
    }
//    REP (i, S.size()) eprintf("%d ", A[i]); eprintf("\n");

    REP (q, Q) {
	int l, r, k;
	scanf("%d%d%d", &l, &r, &k);
	l--; k--;
	Lq.push_back(Lr[k]);
	Rq.push_back(Rr[k]);
	Kq.push_back(l);
	Lq.push_back(Lr[k]);
	Rq.push_back(Rr[k]);
	Kq.push_back(r);
    }

    VI ret = KQUERY(A, Lq, Rq, Kq);
    REP (q, Q) printf("%d\n", ret[2*q+1] - ret[2*q]);

    return 0;
}