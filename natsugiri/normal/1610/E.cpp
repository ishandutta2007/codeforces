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
LL A[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", A+i);
    vector<pair<LL, int> > X = sort_count(A, N);

    int ans = N;
    REP (i, X.size()) {
	int cnt = X[i].second;
	int j = i+1;
	while (j < (int)X.size()) {
	    cnt++;
	    LL nxt = X[j].first * 2 - X[i].first;
	    j = lower_bound(X.begin(), X.end(), make_pair(nxt, 0)) - X.begin();
	}

	amin(ans, N - cnt);
    }
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}