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

struct Seg {
    int len, idx;
    Seg() : len(0) {}
    Seg(int len_, int idx_): len(len_), idx(idx_) {}

    static const Seg IDENTITY;
};
const Seg Seg::IDENTITY = Seg();

Seg operator+(const Seg &x, const Seg &y) {
    if (x.len >= y.len) return x;
    else return y;
};

const LL INVALID = 1LL<<60;
struct Lazy {
    Seg overwrite;
    Lazy() : overwrite(-1, -1) {}
    // Lazy(LL val_) : overwrite(val_) {}

    Lazy& operator*=(const Lazy &y) {
	if (y.overwrite.len != -1) {
	    assert(y.overwrite.len > overwrite.len);
	    overwrite = y.overwrite;
	}
	return *this;
    }

    static const Lazy IDENTITY;
};
const Lazy Lazy::IDENTITY = Lazy();

Seg operator*(const Seg &x, const Lazy &y) {
    if (y.overwrite.len == -1) return x;
    return y.overwrite;
}

struct SegTreeLazy {
    int m;
    vector<Seg> d;
    vector<Lazy> lazy;

    SegTreeLazy(int n=1) {
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::IDENTITY);
	lazy.assign(m*2, Lazy::IDENTITY);
    }

    template<class Iter> SegTreeLazy(Iter begin, Iter end) {
	int n = end - begin;
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::IDENTITY);
	REP (i, n) d[i+m] = *(begin+i);
	for (int i=m; --i; ) d[i] = d[i*2] + d[i*2+1];
	lazy.assign(m*2, Lazy::IDENTITY);
    }

    void force_down(int x) {
	x += m;
	for (int i=__lg(x); i>=1; i--) {
	    int k = x >> i;
	    lazy[k*2] *= lazy[k];
	    lazy[k*2+1] *= lazy[k];
	    d[k] = eval(k*2) + eval(k*2+1);
	    lazy[k] = Lazy::IDENTITY;
	}
    }

    inline Seg eval(int k) {
	return d[k] * lazy[k];
    }

    Seg at(int x) {
	x += m;
	Seg s = d[x];
	for (; x; x>>=1) s = s * lazy[x];
	return s;
    }

    void modify(int x, const Seg &s) {
	force_down(x);
	x += m;
	d[x] = s;
	lazy[x] = Lazy::IDENTITY;
	for (x>>=1; x; x>>=1) d[x] = eval(x*2) + eval(x*2+1);
    }

    Seg query(int x, int y) {
	if (x >= y) return Seg::IDENTITY;
	force_down(x);
	if (x+1 < y) force_down(y-1);
	x += m; y += m;
	Seg ls = Seg::IDENTITY, rs = Seg::IDENTITY;
	for (; x < y; x>>=1, y>>=1) {
	    if (y & 1) rs = eval(--y) + rs;
	    if (x & 1) ls = ls + eval(x++);
	}
	return ls + rs;
    }

    void add(const int x, const int y, const Lazy &v) {
	if (x >= y) return;
	force_down(x);
	if (x+1 < y) force_down(y-1);
	int x0 = x + m, y0 = y + m;
	for (; x0 < y0; x0>>=1, y0>>=1) {
	    if (y0 & 1) lazy[--y0] *= v;
	    if (x0 & 1) lazy[x0++] *= v;
	}
	for (x0=(x+m)>>1; x0; x0>>=1)
	    d[x0] = eval(x0*2) + eval(x0*2+1);
	if (x+1 < y)
	    for (y0=(y+m-1)>>1; y0; y0>>=1)
		d[y0] = eval(y0*2) + eval(y0*2+1);
    }

    inline void force(int k) {
	if (k < m) { // Lazy down
	    lazy[k*2] *= lazy[k];
	    lazy[k*2+1] *= lazy[k];
	    d[k] = eval(k*2) + eval(k*2+1);
	    lazy[k] = Lazy::IDENTITY;
	}
    }

    Seg query_template(int x, int y) { return query_template(x, y, 1, 0, m); }

    Seg query_template(int x, int y, int k, int l, int r) {
	force(k);
	if (r<=x || y<=l) return Seg::IDENTITY;
	if (x<=l && r<=y) return eval(k);
	Seg left = query_template(x, y, k*2, l, (l+r)/2);
	Seg right = query_template(x, y, k*2+1, (l+r)/2, r);
	return left + right;
    }
};

int N, M;
vector<pair<int, int> > B[300011];

VI Xs;
int prv[300011];
bool use[300011];

void MAIN() {
    scanf("%d%d", &N, &M);

    REP (i, M) {
	int a, l, r;
	scanf("%d%d%d", &a, &l, &r);
	a--; l--;
	B[a].emplace_back(l, r);
	Xs.push_back(l);
	Xs.push_back(r);
    }
    Xs.push_back(0);
    Xs.push_back(1e9);
    sort_unique(Xs);

    SegTreeLazy tree(Xs.size());

    REP (i, N) {
	vector<pair<int, int> > &v = B[i];
	sort(v.begin(), v.end());

	int len = 0;
	REP (j, v.size()) {
	    if (j == 0) {
		len = 1;
	    } else if (v[j].first <= v[len-1].second) {
		amax(v[len-1].second, v[j].second);
	    } else {
		v[len] = v[j];
		len++;
	    }
	}
	v.resize(len);

	int best_len = -1;
	int best_prv = -1;

	EACH (e, v) {
	    int li = lower_bound(Xs.begin(), Xs.end(), e->first) - Xs.begin();
	    int ri = lower_bound(Xs.begin(), Xs.end(), e->second) - Xs.begin();
	    auto tmp = tree.query(li, ri);
	    if (best_len < tmp.len) {
		best_len = tmp.len;
		best_prv = tmp.idx;
	    }
	}

	prv[i] = best_prv;
	Lazy lazy;
	lazy.overwrite = Seg(best_len+1, i);

	EACH (e, v) {
	    int li = lower_bound(Xs.begin(), Xs.end(), e->first) - Xs.begin();
	    int ri = lower_bound(Xs.begin(), Xs.end(), e->second) - Xs.begin();
	    tree.add(li, ri, lazy);
	}
    }

    auto tmp = tree.query(0, Xs.size());
    int x = tmp.idx;
    REP (i, tmp.len) {
	use[x] = true;
	x = prv[x];
    }

    VI ans;
    REP (i, N) if (!use[i]) ans.push_back(i+1);
    printf("%d\n", (int)ans.size());
    rprintf("%d", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}