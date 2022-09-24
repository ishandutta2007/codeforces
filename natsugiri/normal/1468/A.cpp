#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>

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
    T at(int i) const {
	return A[i];
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

int N;
int A[500011];
pair<int, int> P[500011];

void MAIN() {
    scanf("%d", &N);
    A[0] = -1;
    REP (i, N) {
	scanf("%d", A+i+1);
    }

    N++;
    REP (i, N) {
	P[i] = make_pair(A[i], i);
    }
    sort(P, P+N);

    int ans = 0;

    priority_queue<pair<int, int> > Q;
    RXQ<int> rxq(VI(N, -(1<<29)));

    REP (i, N) {
	int idx = lower_bound(P, P+N, make_pair(A[i], i)) - P;
	assert(P[idx].second == i);

	int tmp = 1;
	if (idx == 0) {
	    tmp = 1;
	} else {
	    amax(tmp, rxq.max_v(0, idx) + 1);
	}

	amax(ans, tmp);
	rxq.modify(idx, tmp);

	while (!Q.empty() && -Q.top().first <= A[i]) {
	    int k = Q.top().second;
	    Q.pop();
	    tmp = rxq.at(k);
	    rxq.modify(k, tmp + 1);
	}

	Q.emplace(-A[i], idx);
    }

    printf("%d\n", ans - 1);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}