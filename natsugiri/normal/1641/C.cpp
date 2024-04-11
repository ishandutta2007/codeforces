#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
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

int N, Q;
int op[200011];
int L[200011];
int R[200011];
int X[200011];

VI ADD[200011];
VI DEL[200011];

int status[200011];
#define time MY_TIME
int time[200011];
int sums[200011];
const int INF = 1<<29;

void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, Q) {
	scanf("%d", op+i);
	if (op[i] == 0) {
	    scanf("%d%d%d", L+i, R+i, X+i);
	    L[i]--;
	} else {
	    scanf("%d", L+i);
	    L[i]--;
	}
    }

    REP (i, Q) if (op[i] == 0 && X[i] == 0) {
	ADD[L[i]].push_back(i);
	DEL[R[i]].push_back(i);
    }

    set<int> se;
    REP (i, N) {
	EACH (e, DEL[i]) se.erase(*e);
	EACH (e, ADD[i]) se.insert(*e);
	if (!se.empty()) {
	    status[i] = 0;
	    time[i] = *se.begin();
	} else {
	    status[i] = -1;
	    time[i] = INF;
	}
    }
    REP (i, N) {
	sums[i+1] = sums[i];
	if (status[i] == 0) sums[i+1]++;
    }

    RXQ<int> rxq(VI(time, time+N));

    REP (i, Q) if (op[i] == 0 && X[i] == 1) {
	if (sums[R[i]] - sums[L[i]] == R[i] - L[i] - 1) {
	    int pos = rxq.max_i(L[i], R[i]);
	    status[pos] = 1;
	    rxq.modify(pos, i);
	    int t = rxq.max_v(L[i], R[i]);
	    amin(time[pos], t);
	    rxq.modify(pos, INF);
	}
    }


    REP (i, Q) if (op[i] == 1) {
	int pos = L[i];
	if (time[pos] <= i) {
	    if (status[pos] == 0) puts("NO");
	    else puts("YES");
	} else {
	    puts("N/A");
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}