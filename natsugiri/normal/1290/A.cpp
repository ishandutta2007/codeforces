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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}
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

    struct iterator {
	using difference_type   = size_t;
	using value_type        = T;
	using pointer           = T*;
	using reference         = T&;
	using iterator_category = typename vector<T>::iterator::iterator_category;

	using sup_iter = typename vector<T>::iterator;

	sup_iter fr_it, bk_it;
	sup_iter fr_begin, bk_begin;

	iterator(sup_iter fr_it_, sup_iter bk_it_, sup_iter fr_begin_, sup_iter bk_begin_) {
	    fr_it = fr_it_;
	    bk_it = bk_it_;
	    fr_begin = fr_begin_;
	    bk_begin = bk_begin_;
	}

	iterator& operator=(const iterator &y) {
	    fr_it = y.fr_it;
	    bk_it = y.bk_it;
	    fr_begin = y.fr_begin;
	    bk_begin = y.bk_begin;
	    return *this;
	}

	iterator& operator++() {
	    if (fr_it == fr_begin) ++bk_it;
	    else --fr_it;
	    return *this;
	}

	iterator operator++(int) {
	    iterator tmp = *this;
	    ++*this;
	    return tmp;
	}

	iterator& operator--() {
	    if (bk_it == bk_begin) ++fr_it;
	    else --bk_it;
	    return *this;
	}

	iterator operator--(int) {
	    iterator tmp = *this;
	    --*this;
	    return tmp;
	}

	T& operator*() {
	    if (fr_it == fr_begin) return *bk_it;
	    else return *prev(fr_it);
	}

	T* operator->() {
	    if (fr_it == fr_begin) return bk_it;
	    else return prev(fr_it);
	}

	bool operator==(const iterator &y) const { return fr_it == y.fr_it && bk_it == y.bk_it; }
	bool operator!=(const iterator &y) const { return !(*this == y); }

	bool operator<(const iterator &y) const { return fr_it > y.fr_it || bk_it < y.bk_it; }
	bool operator>(const iterator &y) const { return y < *this; }
	bool operator<=(const iterator &y) const { return !(y < *this); }
	bool operator>=(const iterator &y) const { return !(*this < y); }

	size_t operator-(const iterator &y) const {
	    return (bk_it - y.bk_it) + (y.fr_it - fr_it);
	}

	iterator& operator+=(size_t k) {
	    size_t s = fr_it - fr_begin;
	    if (s >= k) {
		fr_it -= k;
	    } else {
		fr_it = fr_begin;
		bk_it += k-s;
	    }
	    return *this;
	}

	iterator operator+(size_t k) const {
	    iterator it = *this;
	    return it += k;
	}

	iterator& operator-=(size_t k) {
	    size_t s = bk_it - bk_begin;
	    if (s >= k) {
		bk_it -= k;
	    } else {
		bk_it = bk_begin;
		fr_it += k-s;
	    }
	    return *this;
	}

	iterator operator-(size_t k) const {
	    iterator it = *this;
	    return it -= k;
	}

    };

    iterator begin() {
	return iterator(fr.end(), bk.begin(), fr.begin(), bk.begin());
    }

    iterator end() {
	return iterator(fr.begin(), bk.end(), fr.begin(), bk.begin());
    }
};

int N, M, K;
int A[4011];

void MAIN() {
    scanf("%d%d%d", &N, &M, &K);
    REP (i, N) scanf("%d", A+i);

    int ans = 0;
    if (K >= M-1) {
	REP (i, M) {
	    amax(ans, A[i]);
	    amax(ans, A[N-1-i]);
	}
    } else {
	int D = N-M;
	VI v;
	REP (i, N-D) {
	    int t = max(A[i], A[i+D]);
	    v.push_back(t);
	}
	assert((int)v.size() == M);
	Deque<int> dq;
	REP (i, M-K) {
	    while (!dq.empty() && dq.back() > v[i]) dq.pop_back();
	    dq.push_back(v[i]);
	}
	amax(ans, dq.front());
	for (int i=M-K; i<M; i++) {
	    if (dq.front() == v[i-M+K]) dq.pop_front();
	    while (!dq.empty() && dq.back() > v[i]) dq.pop_back();
	    dq.push_back(v[i]);
	    amax(ans, dq.front());
	}
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}