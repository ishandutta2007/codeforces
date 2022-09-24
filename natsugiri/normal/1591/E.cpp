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

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;

template<class T>
using TreeSet = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// iterator find_by_order(size_t index);
// size_type order_of_key(const T);
//
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
    inline T sum(int r) const {
	T s = T();
	for (; r; r&=r-1) s += d[r-1];
	return s;
    }
    T sum(int l, int r) const {
	return sum(r) - sum(l);
    }
};

const int MAXN = 1000011;

int N;
int A[MAXN];
VI G[MAXN];
int par[MAXN];

using Tuple = tuple<int, int, int>;
vector<Tuple> H[MAXN];

int ans[MAXN];

int counter[MAXN];
TreeSet<pair<int, int> > rev;
Fenwick<int> F;

void dfs() {
    vector<pair<int, int> > stk;
    stk.emplace_back(0, 0);
    while (!stk.empty()) {
	int v = stk.back().first;

	if (stk.back().second == 0) {
	    if (counter[A[v]]) {
		rev.erase(make_pair(counter[A[v]], A[v]));
		F.add(counter[A[v]], -1);
	    }
	    counter[A[v]]++;
	    rev.insert(make_pair(counter[A[v]], A[v]));
	    F.add(counter[A[v]], 1);

	    EACH (e, H[v]) {
		int l, k, i;
		tie(l, k, i) = *e;
		int small = F.sum(l);

		if (small + k > (int)rev.size()) {
		    ans[i] = -1;
		} else {
		    auto it = rev.find_by_order(small + k - 1);
		    ans[i] = it->second;
		}
	    }
	}

	if (stk.back().second == (int)G[v].size()) {
	    stk.pop_back();
	    F.add(counter[A[v]], -1);
	    rev.erase(make_pair(counter[A[v]], A[v]));
	    counter[A[v]]--;
	    if (counter[A[v]]) {
		rev.insert(make_pair(counter[A[v]], A[v]));
		F.add(counter[A[v]], 1);
	    }
	} else {

	    int w = G[v][stk.back().second++];
	    stk.emplace_back(w, 0);
	}
    }
}

// void dfs(int v) {
//     if (counter[A[v]]) {
// 	rev.erase(make_pair(counter[A[v]], A[v]));
// 	F.add(counter[A[v]], -1);
//     }
//     counter[A[v]]++;
//     rev.insert(make_pair(counter[A[v]], A[v]));
//     F.add(counter[A[v]], 1);
// 
//     EACH (e, H[v]) {
// 	int l, k, i;
// 	tie(l, k, i) = *e;
// 	int small = F.sum(l);
// 
// 	if (small + k > (int)rev.size()) {
// 	    ans[i] = -1;
// 	} else {
// 	    auto it = rev.find_by_order(small + k - 1);
// 	    ans[i] = it->second;
// 	}
//     }
//     EACH (e, G[v]) {
// 	dfs(*e);
//     }
// 
//     F.add(counter[A[v]], -1);
//     rev.erase(make_pair(counter[A[v]], A[v]));
//     counter[A[v]]--;
//     if (counter[A[v]]) {
// 	rev.insert(make_pair(counter[A[v]], A[v]));
// 	F.add(counter[A[v]], 1);
//     }
// }

void MAIN() {
    int Q;
    scanf("%d%d", &N, &Q);
    REP (i, N) {
	G[i].clear();
	H[i].clear();
    }
    memset(counter, 0, sizeof (int) * (N+1));
    rev.clear();
    F = Fenwick<int>(N+1);


    REP (i, N) scanf("%d", A+i);
    REP (i, N-1) {
	int p;
	scanf("%d", &p);
	p--;
	G[p].push_back(i+1);
	par[i+1] = p;
    }

    REP (i, Q) {
	int v, l, k;
	scanf("%d%d%d", &v, &l, &k);
	v--;
	H[v].emplace_back(l, k, i);
    }

    dfs();

    rprintf("%d", ans, ans+Q);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}