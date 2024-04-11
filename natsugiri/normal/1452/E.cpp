#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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

struct AddSum {
    typedef long long T;
    int N, M;
    vector<T> data, part;
    AddSum(int N_=1): N(N_), M(2<<__lg(max(1, N))), data(2*M), part(2*M) {}
    AddSum(const vector<T> &A): N(A.size()), M(2<<__lg(max(1, N))), data(2*M), part(2*M) {
	for (int i=0; i<N; i++) data[i+M] = A[i];
	for (int i=M; --i;) data[i] = data[2*i] + data[2*i+1];
    }
    void add(int x, int y, const T &v) { add(x, y, 1, 0, M, v); }
    void add(int x, int y, int k, int l, int r, const T &v) {
	if (x <= l && r <= y) part[k] += v;
	else if (x < r && l < y) {
	    data[k] += (min(y, r)-max(x, l)) * v;
	    add(x, y, k*2, l, (l+r)/2, v); add(x, y, k*2+1, (l+r)/2, r, v);
	}
    }
    T sum(int x, int y) { return sum(x, y, 1, 0, M); }
    T sum(int x, int y, int k, int l, int r) {
	if (x <= l && r <= y) return data[k] + part[k] * (r - l);
	else if (y <= l || r <= x) return T(0);
	else return sum(x, y, k*2, l, (l+r)/2) + sum(x, y, k*2+1, (l+r)/2, r) + (min(y, r)-max(x, l)) * part[k];
    }
};

int W(int l0, int r0, int l1, int r1) {
    int tmp = min(r0, r1) - max(l0, l1);
    return max(0, tmp);
}

int N;
int M, K;
int L[2011], R[2011];
VI H[2011];

void MAIN() {
    scanf("%d%d%d", &N, &M, &K);
    REP (i, M) scanf("%d%d", L+i, R+i), L[i]--;

    LL ans = 0;

    AddSum tree(N+1);

    for (int x=0; x+K <= N; x++) {
	REP (i, N+1) H[i].clear();
	LL base = 0;

	REP (i, M) {
	    int w = W(x, x+K, L[i], R[i]);

	    if (L[i] <= x) {
		base += w;
	    } else {
		H[R[i] - w].push_back(i);
		tree.add(L[i], R[i], 1);
	    }
	}

	int y;
	for (y=x; y+K <= N; y++) {
	    LL tmp = base + tree.sum(y, y+K);
	    amax(ans, tmp);

	    EACH (e, H[y]) {
		int i = *e;
		tree.add(L[i], R[i], -1);
		base += W(x, x+K, L[i], R[i]);
	    }
	}

	for (; y <= N; y++) {
	    EACH (e, H[y]) {
		int i = *e;
		tree.add(L[i], R[i], -1);
	    }
	}
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}