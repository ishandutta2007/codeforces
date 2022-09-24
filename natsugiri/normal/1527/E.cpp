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

using Type = LL;
Type INF = 0x3f3f3f3f3f3f3f3fLL;
const int MAXN = 35011;
const int MAXK = 111;
int N, K;

int A[35011];

Type dp[MAXK][MAXN];
Type *cur, *nxt;
// cost [i, j);

Deque<int> dq[35011];
int eval(int a) {
    if (dq[a].empty()) return 0;
    return dq[a].back() - dq[a].front();
}

LL total;
int LEFT, RIGHT;

Type cost(int i, int j) {
    if (i == j) return INF;
    while (i < LEFT) {
	LEFT--;
	int a = A[LEFT];
	total -= eval(a);
	dq[a].push_front(LEFT);
	total += eval(a);
    }
    while (RIGHT < j) {
	int a = A[RIGHT];
	total -= eval(a);
	dq[a].push_back(RIGHT);
	total += eval(a);
	RIGHT++;
    }
    while (j < RIGHT) {
	RIGHT--;
	int a = A[RIGHT];
	total -= eval(a);
	assert(dq[a].back() == RIGHT);
	dq[a].pop_back();
	total += eval(a);
    }
    while (LEFT < i) {
	int a = A[LEFT];
	total -= eval(a);
	assert(dq[a].front() == LEFT);
	dq[a].pop_front();
	total += eval(a);
	LEFT++;
    }
    return total;
}


// calc nxt[x] ... nxt[y] (inclusive);
void rec(int x, int y, int optL, int optR) {
    if (x > y) {
	return;
    }
    int mid = (x + y) / 2;
    Type best = INF;
    int best_i = -1;
    for (int i=optL; i<=min(mid, optR); i++) {
	Type c = cur[i] + cost(i, mid);
	if (best > c) {
	    best = c;
	    best_i = i;
	}
    }
    nxt[mid] = best;
    rec(x, mid-1, optL, best_i);
    rec(mid+1, y, best_i, optR);
}

Type quick() {
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    REP (t, K) {
	cur = dp[t];
	nxt = dp[t+1];
	rec(0, N, 0, N);
    }
    return dp[K][N];
}


void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", A+i);

    printf("%lld\n", quick());

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}