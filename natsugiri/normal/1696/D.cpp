#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)
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
    T at(int i) const {
	return A[i];
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

int N;
int P[250011];
int D[250011];

void slow() {
    memset(D, 0x3f, sizeof (int) * N);
    D[0] = 0;
    REP (i, N) {
	int mi = P[i], ma = P[i];
	for (int j=i+1; j<N; j++) {
	    amin(mi, P[j]);
	    amax(ma, P[j]);

	    if ((P[i] == mi && P[j] == ma) || (P[i] == ma && P[j] == mi)) {
		amin(D[j], D[i] + 1);
	    }
	}
    }
    rprintf("%d", D, D+N);
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", P+i);

    // slow();

    VI dec, inc;
    VI v(N);
    RMQ<int> rmq1(v);
    RMQ<int> rmq2(v);
    inc.push_back(0);
    dec.push_back(0);

    for (int i=1; i<N; i++) {
	while (!dec.empty() && P[dec.back()] < P[i]) dec.pop_back();
	while (!inc.empty() && P[inc.back()] > P[i]) inc.pop_back();

	int tmp = 1<<29;

	if (dec.size()) {
	    int left = (inc.empty()? -1: inc.back());
	    int k = upper_bound(dec.begin(), dec.end(), left) - dec.begin();
	    if (k < (int)dec.size()) {
		amin(tmp, rmq1.min_v(k, dec.size()) + 1);
	    }
	}

	if (inc.size()) {
	    int left = (dec.empty()? -1: dec.back());
	    int k = upper_bound(inc.begin(), inc.end(), left) - inc.begin();
	    if (k < (int)inc.size()) {
		amin(tmp, rmq2.min_v(k, inc.size()) + 1);
	    }
	}

	D[i] = tmp;

	rmq2.modify(inc.size(), tmp);
	rmq1.modify(dec.size(), tmp);
	inc.push_back(i);
	dec.push_back(i);
    }

    // rprintf("%d", D, D+N);
    printf("%d\n", D[N-1]);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}