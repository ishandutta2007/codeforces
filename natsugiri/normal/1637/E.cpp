#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<map>

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

// reorder a;
// ret[i].first == a[k];
// ret[i].second == # of a[k];
template<class T> vector<pair<T, int> > sort_count(T *a, int n) {
    sort(a, a+n);
    vector<pair<T, int> > ret;
    for (int i=0, j=0; i<n; i=j) {
	j = i+1;
	while (j < n && a[i] == a[j]) j++;
	ret.emplace_back(a[i], j-i);
    }
    return ret;
}

int N;
int M;
int A[300011];
int X[300011];
int Y[300011];

LL F[300011];

map<int, VI> mp;
vector<pair<int, int> > P, Q;

bool ok(LL mid) {
    LL way = 0;

    EACH (e, P) {
	LL x = e->first;
	LL cntx = e->second;

	if (4 * x * cntx >= mid) way--;

	EACH (f, mp) {
	    LL cnty = f->first;
	    const VI &v = f->second;

	    if (v.size() == 1u) {
		LL y = v[0];
		if ((cntx + cnty) * (x + y) >= mid) way++;
	    } else {
		if ((cntx + cnty) * (x + v[0]) >= mid) {
		    way += v.size();
		} else if ((cntx + cnty) * (x + v.back()) < mid) {
		    // nop;
		} else {
		    int small = partition_point(v.begin(), v.end(), [&](const int elem) -> bool {
			    return (cntx + cnty) * (x + elem) < mid;
			    }) - v.begin();
		    way += (int)v.size() - small;
		}
	    }
	}
    }

    way /= 2;
    int small = lower_bound(F, F+M, mid) - F;
    way -= M-small;

    return way >= 1;
}

void MAIN() {

    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", A+i);
    REP (i, M) scanf("%d%d", X+i, Y+i);


    P = sort_count(A, N);
    Q.clear();
    EACH (e, P) Q.emplace_back(e->second, e->first);
    sort(Q.begin(), Q.end());


    mp.clear();
    EACH (e, Q) mp[e->first].push_back(e->second);

    REP (i, M) {
	auto itx = lower_bound(P.begin(), P.end(), make_pair(X[i], -1));
	auto ity = lower_bound(P.begin(), P.end(), make_pair(Y[i], -1));
	assert(itx->first == X[i]);
	assert(ity->first == Y[i]);
	F[i] = (LL)(X[i] + Y[i]) * (itx->second + ity->second);
    }

    sort(F, F+M);
    LL lo = 0, hi = 1;
    while (ok(hi)) {
	lo = hi;
	hi += hi;
    }
    while (hi - lo > 1) {
	LL mid = (lo + hi) / 2;
	(ok(mid)? lo: hi) = mid;
    }
    printf("%lld\n", lo);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}