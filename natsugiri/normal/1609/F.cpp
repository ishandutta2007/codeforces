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

int pc(LL x) {
    return __builtin_popcountll(x);
}

int N;
LL A[1000011];

void slow() {
    int ans = 0;
    REP (l, N) {
	LL mi = A[l], ma = A[l];
	for (int r=l+1; r<=N; r++) {
	    if (pc(mi) == pc(ma)) {
		ans++;
	    }
	    amin(mi, A[r]);
	    amax(ma, A[r]);
	}
    }
    printf("%d slow\n", ans);
}

int sumsS[1000011];
VI vLma[60];
VI vLmi[60];

LL ans;
vector<LL> Lma, Lmi;

void rec(int left, int right) {
    if (left == right) return;

    int mid = (right + left) / 2;
    Lma.clear();
    Lmi.clear();

    Lma.push_back(A[mid]);
    Lmi.push_back(A[mid]);
    for (int i=mid-1; i>=left; i--) {
	Lma.push_back(max(A[i], Lma.back()));
	Lmi.push_back(min(A[i], Lmi.back()));
    }

    REP (t, 60) {
	vLma[t].clear();
	vLmi[t].clear();
    }
    
    REP (i, Lma.size()) {
	sumsS[i+1] = sumsS[i];
	if (pc(Lma[i]) == pc(Lmi[i])) sumsS[i+1]++;

	vLma[pc(Lma[i])].push_back(i);
	vLmi[pc(Lmi[i])].push_back(i);
    }

    LL Rma = A[mid];
    LL Rmi = A[mid];
    int x = 0, y = 0;

    for (int i=mid; i<right; i++) {
	amax(Rma, A[i]);
	amin(Rmi, A[i]);

	int pcRma = pc(Rma);
	int pcRmi = pc(Rmi);

	while (x < (int)Lma.size() && Lma[x] < Rma) x++;
	while (y < (int)Lmi.size() && Lmi[y] > Rmi) y++;

	// [0, min(x, y));
	if (pcRma == pcRmi) {
	    ans += min(x, y);
	}

	// [min(x, y), max(x, y));
	if (x < y) {
	    // [x, y);
	    ans += lower_bound(vLma[pcRmi].begin(), vLma[pcRmi].end(), y)
		- lower_bound(vLma[pcRmi].begin(), vLma[pcRmi].end(), x);
	} else {
	    // [y, x);
	    ans += lower_bound(vLmi[pcRma].begin(), vLmi[pcRma].end(), x)
		- lower_bound(vLmi[pcRma].begin(), vLmi[pcRma].end(), y);
	}

	// [max(x, y), len);
	int m = max(x, y);
	ans += sumsS[Lma.size()] - sumsS[m];
    }

    rec(left, mid);
    rec(mid+1, right);
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", A+i);

    // slow();
    rec(0, N);
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}