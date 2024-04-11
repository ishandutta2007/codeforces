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
template<class T> void sort_unique(vector<T> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

int N, Q;
int A[100011];
LL sums[100011];
int xors[100011];
int nxt[100011][30];
int prv[100011][30];

void build() {
    REP (i, N) {
	sums[i+1] = sums[i] + A[i];
	xors[i+1] = xors[i] ^ A[i];
    }

    REP (t, 30) nxt[N][t] = N;
    for (int i=N; i--;) {
	REP (t, 30) {
	    nxt[i][t] = nxt[i+1][t];
	    if (A[i]>>t&1) {
		nxt[i][t] = i;
	    }
	}
    }

    REP (t, 30) prv[0][t] = -1;
    REP (i, N) {
	REP (t, 30) {
	    prv[i+1][t] = prv[i][t];
	    if (A[i]>>t&1) {
		prv[i+1][t] = i;
	    }
	}
    }
}

LL eval(int l, int r) {
    return (sums[r] - sums[l]) - (xors[r] ^ xors[l]);
}

void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, N) scanf("%d", A+i);

    build();

    VI Ls, Rs;
    REP ($, Q) {
	int L, R;
	scanf("%d%d", &L, &R);
	L--;

	Ls.clear();
	Rs.clear();
	Ls.push_back(L);
	Rs.push_back(R);
	int left = R-1;
	int right = L;

	REP (t, 30) {
	    int n1 = nxt[L][t];
	    int n2 = (n1 >= N? N: nxt[n1+1][t]);
	    amin(left, n2);
	    Ls.push_back(n1);
	    Ls.push_back(n2);

	    int p1 = prv[R][t];
	    int p2 = (p1 < 0? -1: prv[p1][t]);
	    amax(right, p2+1);
	    Rs.push_back(p1+1);
	    Rs.push_back(p2+1);
	}

	EACH (e, Ls) {
	    if (*e < L || left < *e) *e = -1;
	}
	EACH (e, Rs) {
	    if (R < *e || *e < right) *e = -1;
	}
	sort_unique(Ls);
	sort_unique(Rs);

	LL val = -1;
	int ans_l = -1, ans_r = -1;
	auto update = [&](int l, int r) {
	    assert(L <= l && l < r && r <= R);

	    LL tmp = eval(l, r);
	    if (val < tmp || (val == tmp && ans_r - ans_l > r - l)) {
		val = tmp;
		ans_l = l;
		ans_r = r;
	    }
	};

	update(L, L+1);
	REP (i, Ls.size()) {
	    if (Ls[i] == -1) continue;

	    REP (j, Rs.size()) {
		if (Rs[j] == -1) continue;

		if (Ls[i] < Rs[j]) {
		    update(Ls[i], Rs[j]);
		}
	    }
	}

	printf("%d %d\n", ans_l+1, ans_r);
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}