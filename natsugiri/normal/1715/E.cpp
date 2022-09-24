#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<deque>
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
template<class T> struct Deque {
    // deque { 0, 1, 2, 3, 4, 5,};
    // fr { 2, 1, 0 } | bk { 3, 4, 5 };
    vector<T> fr, bk;

    Deque() { }

    template<class Iter> Deque(Iter first, Iter last) : bk(first, last) {}

    size_t size() const {
	return fr.size() + bk.size();
    }

    bool empty() const {
	return fr.empty() && bk.empty();
    }

    void clear() {
	fr.clear();
	bk.clear();
    }

    T& operator[](size_t i) {
	if (i < fr.size()) return fr[fr.size() - 1 - i];
	return bk[i - fr.size()];
    }

    const T& operator[](size_t i) const {
	if (i < fr.size()) return fr[fr.size() - 1 - i];
	return bk[i - fr.size()];
    }

    T& back() {
	if (bk.empty()) return fr[0];
	return bk.back();
    }

    const T& back() const {
	if (bk.empty()) return fr[0];
	return bk.back();
    }

    void push_back(const T &t) {
	bk.push_back(t);
    }

    template<typename... Args>
    void emplace_back(Args&&... args) {
	bk.emplace_back(forward<Args>(args)...);
    }

    void pop_back() {
	if (bk.empty()) {
	    pop_back_helper(fr, bk);
	} else {
	    bk.pop_back();
	}
    }

    T& front() {
	if (fr.empty()) return bk[0];
	return fr.back();
    }

    const T& front() const {
	if (fr.empty()) return bk[0];
	return fr.back();
    }

    void push_front(const T &t) {
	fr.push_back(t);
    }

    template<typename... Args>
    void emplace_front(Args&&... args) {
	fr.emplace_back(forward<Args>(args)...);
    }

    void pop_front() {
	if (fr.empty()) {
	    pop_back_helper(bk, fr);
	} else {
	    fr.pop_back();
	}
    }

    void reverse() {
	swap(fr, bk);
    }

    static void pop_back_helper(vector<T> &fr, vector<T> &bk) {
	size_t s = fr.size();
	size_t t = (s-1)/2;
	bk.resize(t);
	for (size_t i=1; i<=t; i++) bk[t-i] = fr[i];
	for (size_t i=t+1; i<s; i++) fr[i-t-1] = fr[i];
	fr.resize(s-1-t);
    }

    template<bool IsConst>
    struct IteratorImpl {
	using difference_type   = size_t;
	using value_type        = T;
	using pointer           = typename conditional<IsConst, const value_type*, value_type*>::type;
	using reference         = typename conditional<IsConst, const value_type&, value_type&>::type;
	using iterator_category = typename vector<T>::iterator::iterator_category;

	using deque_ptr = typename conditional<IsConst, const Deque*, Deque*>::type;

	deque_ptr obj;
	int idx;

	IteratorImpl(deque_ptr obj_, int idx_): obj(obj_), idx(idx_) {}

	IteratorImpl& operator++() { idx++; return *this; }
	IteratorImpl& operator--() { idx--; return *this; }

	IteratorImpl operator++(int) { IteratorImpl tmp = *this; ++*this; return tmp; }
	IteratorImpl operator--(int) { IteratorImpl tmp = *this; --*this; return tmp; }

	reference operator*() { return (*obj)[idx]; }
	pointer operator->() { return &((*obj)[idx]); }

	bool operator==(const IteratorImpl &y) const { return obj == y.obj && idx == y.idx; }
	bool operator!=(const IteratorImpl &y) const { return !(*this == y); }

	bool operator<(const IteratorImpl &y) const { return idx < y.idx; }
	bool operator>(const IteratorImpl &y) const { return y < *this; }
	bool operator<=(const IteratorImpl &y) const { return !(y < *this); }
	bool operator>=(const IteratorImpl &y) const { return !(*this < y); }

	difference_type operator-(const IteratorImpl &y) const { return idx - y.idx; }

	IteratorImpl& operator+=(size_t k) { idx += k; return *this; }
	IteratorImpl& operator-=(size_t k) { idx -= k; return *this; }

	IteratorImpl operator+(size_t k) const { IteratorImpl it = *this; return it += k; }
	IteratorImpl operator-(size_t k) const { IteratorImpl it = *this; return it -= k; }
    };

    using iterator = IteratorImpl<false>;
    using const_iterator = IteratorImpl<true>;

    iterator begin() { return iterator(this, 0); }
    iterator end() { return iterator(this, size()); }
    const_iterator cbegin() const { return const_iterator(this, 0); }
    const_iterator cend() const { return const_iterator(this, size()); }
    const_iterator begin() const { return cbegin(); }
    const_iterator end() const { return cend(); }
};

template<class T> struct Line {
    T a, b;

    Line(): a(0), b(0) {}
    Line(const T a_, const T b_) : a(a_), b(b_) { }

    T eval(T x) const {
	return a * x + b;
    }

    struct Rat {
	T nu, de;
	Rat() {}
	Rat(T nu_, T de_): nu(nu_), de(de_) {
	    if (de < 0) {
		nu = -nu;
		de = -de;
	    }
	    // gcd
	}
    };

    // cross point y := line.eval(line.cross_point_x(other_line));
    Rat eval(const Rat &x) const {
	return Rat(a * x.nu + b * x.de, x.de);
    }

    Rat cross_point_x(const Line &q) const {
	// a must be differ;
	assert(a != q.a);
	return Rat(b - q.b, q.a - a);
    }
};

// VecLine = Deque<Lint<T> > or vector<Lint<T> >;
template<class T, class VecLine=deque<Line<T> > > struct ConvexHullTrickMaxLinear {
    using Line = ::Line<T>;

    // a 
    VecLine lines;

    bool empty() const {
	return lines.empty();
    }

    void insert(const T a, const T b) {
	if (lines.empty()) {
	    lines.emplace_back(a, b);
	} else if (lines.back().a <= a) {
	    if (lines.back().a == a) {
		if (lines.back().b >= b) return;
		else lines.pop_back();
	    }
	    lines.emplace_back(a, b);
	    int len = lines.size();
	    while (len >= 3 && cover(lines[len-3], lines[len-2], lines[len-1])) {
		lines[len-2] = lines.back();
		lines.pop_back();
		len--;
	    }
	} else {
	    assert(false);
	}
    }

    void insert_front(const T a, const T b) {
	// ConvexHullTrickMaxLinear<LL, Deque<Line<LL> > > cht; 
	if (lines.empty()) {
	    lines.emplace_back(a, b);
	} else if (a <= lines.front().a) {
	    if (lines.front().a == a) {
		if (lines.front().b >= b) return;
		else lines.pop_front();
	    }
	    lines.emplace_front(a, b);
	    while ((int)lines.size() >= 3 && cover(lines[0], lines[1], lines[2])) {
		lines[1] = lines[0];
		lines.pop_front();
	    }
	} else {
	    assert(false);
	}
    }

    // returns forall x: t(x) <= max(s(x), u(x));
    inline bool cover(const Line &s, const Line &t, const Line &u) const {
	if (s.a > t.a) return cover(u, t, s);
	assert(s.a < t.a);
	assert(t.a < u.a);
	return (s.b-t.b)*(u.a-t.a) >= (t.b-u.b)*(t.a-s.a);
    }

    int bisect_index_max(const T x) const {
	int lo = 0, hi = lines.size();
	while (hi - lo > 1) {
	    int m = (lo + hi) / 2;
	    if (lines[m-1].eval(x) < lines[m].eval(x)) lo = m;
	    else hi = m;
	}
	return lo;
    }

    Line bisect_max(const T x) const {
	return lines[bisect_index_max(x)];
    }

    int last_index = 0;

    Line linear_search_max(const T x) {
	amax(last_index, 0);
	amin(last_index, (int)lines.size()-1);
	while (last_index+1 < (int)lines.size() && lines[last_index].eval(x) < lines[last_index+1].eval(x)) 
	    last_index++;
	while (last_index && lines[last_index].eval(x) <= lines[last_index-1].eval(x)) 
	    last_index--;
	return lines[last_index];
    }
};



int N, M, K;
vector<pair<int, int> > G[100011];

LL buf[2][100011];
LL *cur = buf[0];
LL *nxt = buf[1];
LL ans[100011];

void MAIN() {
    scanf("%d%d%d", &N, &M, &K);
    REP (i, M) {
	int x, y, w;
	scanf("%d%d%d", &x, &y, &w);
	x--; y--;
	G[x].emplace_back(y, w);
	G[y].emplace_back(x, w);
    }

    memset(cur, 0x3f, sizeof (LL) * N);
    const LL INF = cur[0];
    cur[0] = 0;
    priority_queue<pair<LL, int> > Q;

    REP (k, K+1) {
	REP (i, N) {
	    if (cur[i] >= 0) Q.emplace(-cur[i], i);
	}
	while (!Q.empty()) {
	    int v = Q.top().second;
	    LL cst = -Q.top().first;
	    Q.pop();
	    if (cur[v] != cst) continue;
	    EACH (e, G[v]) {
		LL tmp = cst + e->second;
		if (cur[e->first] > tmp) {
		    cur[e->first] = tmp;
		    Q.emplace(-tmp, e->first);
		}
	    }
	}

	if (k == K) break;

	memcpy(nxt, cur, sizeof (LL) * N);
	{
	    ConvexHullTrickMaxLinear<__int128, vector<Line<__int128> > > cht;
	    REP (i, N) {
		if (i && !cht.empty()) {
		    __int128 tmp = -cht.linear_search_max(i).eval(i) + (LL)i*i;
		    if (nxt[i] > tmp) {
			nxt[i] = tmp;
		    }
		}
		if (cur[i] < INF) {
		    cht.insert(2LL * i, -cur[i] - (LL)i * i);
		}
	    }
	}

	{
	    ConvexHullTrickMaxLinear<__int128, Deque<Line<__int128> > > cht;
	    for (int i=N; i--;) {
		if (i+1 < N && !cht.empty()) {
		    __int128 tmp = -cht.linear_search_max(i).eval(i) + (LL)i*i;
		    if (nxt[i] > tmp) {
			nxt[i] = tmp;
		    }
		}
		if (cur[i] < INF) {
		    cht.insert_front(2LL * i, -cur[i] - (LL)i * i);
		}
	    }
	}
	swap(cur, nxt);
    }

    rprintf("%lld", cur, cur+N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}