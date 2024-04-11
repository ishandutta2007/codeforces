#include<stack>
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

template<class T> struct Fenwick {
    int n;
    T* d;
    Fenwick() : n(0), d(NULL) {}
    Fenwick(int n_) : n(n_) {
	d = new T[n_]();
    }
    Fenwick(const Fenwick &y) : n(y.n) {
	d = new T[n];
	memcpy(d, y.d, sizeof (T) * n);
    }
    ~Fenwick() {
	delete[] d; d = NULL;
	n = 0;
    }
    friend void swap(Fenwick &x, Fenwick &y) {
	swap(x.n, y.n); swap(x.d, y.d);
    }
    Fenwick& operator=(Fenwick y) {
	swap(*this, y);
	return *this;
    }
    inline void add(int i, const T &x) {
	for (; i<n; i|=i+1) d[i] += x;
    }
    inline T sum(int r) {
	T s = T();
	for (; r; r&=r-1) s += d[r-1];
	return s;
    }
    T sum(int l, int r) {
	return sum(r) - sum(l);
    }
};

int N, Q;
int P[1000011];
int nxt[1000011], prv[1000011];

struct Query {
    int l, r, i;
} query[1000011];

struct CmpR {
    bool operator()(const Query &x, const Query &y) const {
	return x.r < y.r;
    }
} cmpR;
struct CmpL {
    bool operator()(const Query &x, const Query &y) const {
	return x.l < y.l;
    }
} cmpL;

LL ans[1000111];

void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, N) scanf("%d", P+i), P[i]--;
    REP (i, Q) {
	int l;
	scanf("%d", &l);
	query[i].l = l-1;
	query[i].i = i;
    }
    REP (i, Q) {
	int r;
	scanf("%d", &r);
	query[i].r = r;
    }

    // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    stack<int> st;
    st.push(-1);
    REP (i, N) {
	while (st.top() >= 0 && P[st.top()] < P[i]) st.pop();
	prv[i] = st.top()+1;
	st.push(i);
    }
    sort(query, query+Q, cmpL);
    vector<pair<int, int> > Z; Z.reserve(N);
    REP (i, N) Z.emplace_back(prv[i], i);
    sort(Z.begin(), Z.end());

    Fenwick<LL> S(N);
    Fenwick<int> F(N);
    for (int q=Q, pos=N-1; q--; ) {
	while (pos>=0 && query[q].l <= Z[pos].first) {
	    int idx = Z[pos].second;
	    S.add(idx, Z[pos].first);
	    F.add(idx, 1);
	    pos--;
	}
	LL l = query[q].l;
	LL r = query[q].r;
	LL s = S.sum(l, r);
	LL c = F.sum(l, r);
	LL len = r - l;
	ans[query[q].i] -= s + (len-c)*l;
    }

    while (!st.empty()) st.pop();

    // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    st.push(N);
    for (int i=N; i--;) {
	while (st.top() < N && P[st.top()] < P[i]) st.pop();
	nxt[i] = st.top();
	st.push(i);
    }
    sort(query, query+Q, cmpR);
    REP (i, N) Z[i] = make_pair(nxt[i], i);
    sort(Z.begin(), Z.end());

    S = Fenwick<LL>(N);
    F = Fenwick<int>(N);
    for (int q=0, pos=0; q<Q; q++) {
	while (pos<N && Z[pos].first < query[q].r) {
	    int idx = Z[pos].second;
	    S.add(idx, Z[pos].first);
	    F.add(idx, 1);
	    pos++;
	}
	LL l = query[q].l;
	LL r = query[q].r;
	LL s = S.sum(l, r);
	LL c = F.sum(l, r);
	LL len = r - l;
	ans[query[q].i] += s + (len-c)*r;
    }

    rprintf("%lld", ans, ans+Q);

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}