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

template<unsigned MOD_> struct ModInt {
    static constexpr unsigned MOD = MOD_;
    unsigned x;
    void undef() { x = (unsigned)-1; }
    bool isnan() const { return x == (unsigned)-1; }
    inline int geti() const { return (int)x; }
    ModInt() { x = 0; }
    ModInt(int y) { if (y<0 || (int)MOD<=y) y %= (int)MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned y) { if (MOD<=y) x = y % MOD; else x = y; }
    ModInt(long long y) { if (y<0 || MOD<=y) y %= MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned long long y) { if (MOD<=y) x = y % MOD; else x = y; }
    ModInt &operator+=(const ModInt y) { if ((x += y.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(const ModInt y) { if ((x -= y.x) & (1u<<31)) x += MOD; return *this; }
    ModInt &operator*=(const ModInt y) { x = (unsigned long long)x * y.x % MOD; return *this; }
    ModInt &operator/=(const ModInt y) { x = (unsigned long long)x * y.inv().x % MOD; return *this; }
    ModInt operator-() const { return (x ? MOD-x: 0); }

    ModInt inv() const { return pow(MOD-2); }
    ModInt pow(long long y) const {
	ModInt b = *this, r = 1;
	if (y < 0) { b = b.inv(); y = -y; }
	for (; y; y>>=1) {
	    if (y&1) r *= b;
	    b *= b;
	}
	return r;
    }

    friend ModInt operator+(ModInt x, const ModInt y) { return x += y; }
    friend ModInt operator-(ModInt x, const ModInt y) { return x -= y; }
    friend ModInt operator*(ModInt x, const ModInt y) { return x *= y; }
    friend ModInt operator/(ModInt x, const ModInt y) { return x *= y.inv(); }
    friend bool operator<(const ModInt x, const ModInt y) { return x.x < y.x; }
    friend bool operator==(const ModInt x, const ModInt y) { return x.x == y.x; }
    friend bool operator!=(const ModInt x, const ModInt y) { return x.x != y.x; }
};

constexpr LL MOD = 998244353;
using Mint = ModInt<MOD>;

#define data MY_DATA
int L, R;
int M;
int X[400011];
int Y[400011];
int Q;

Mint pow2[400011];

struct Data {
    Mint ev, od;
    Deque<int> vers;
    Deque<int> ids;

    void flip() {
	if (ids.size() % 2 == 0) swap(ev, od);
	vers.reverse();
	ids.reverse();
    }
};

int data_i = 1;
Data data[400011];
int ptr[400011];

Mint total;
VI cycles;

void ADD(int i, int x, int y) {
    if (ptr[x] == 0 && ptr[y] == 0) {
	data[data_i].ev = pow2[i];
	data[data_i].od = 0;

	data[data_i].vers.push_back(x);
	data[data_i].vers.push_back(y);
	data[data_i].ids.push_back(i);

	ptr[x] = ptr[y] = data_i;
	data_i++;
	total += pow2[i];

    } else if (ptr[x] == ptr[y]) {
	// total += data[ptr[x]].ev;
	cycles.push_back(ptr[x]);
	ptr[x] = ptr[y] = 0;
	// cycle;
    } else if (ptr[x] && ptr[y]) {
	if (data[ptr[x]].vers.size() < data[ptr[y]].vers.size()) {
	    swap(x, y);
	}

	total -= data[ptr[x]].ev;
	total -= data[ptr[y]].ev;

	if (data[ptr[x]].vers.back() != x) data[ptr[x]].flip();
	if (data[ptr[y]].vers.front() != y) data[ptr[y]].flip();

	{
	    int a = data[ptr[x]].vers.front();
	    int b = data[ptr[y]].vers.back();

	    ptr[x] = ptr[y] = 0;
	    x = a;
	    y = b;
	}

	if (data[ptr[x]].ids.size() % 2 == 1) {
	    data[ptr[x]].ev += data[ptr[y]].ev;
	    data[ptr[x]].od += data[ptr[y]].od;
	    data[ptr[x]].od += pow2[i];
	} else {
	    data[ptr[x]].ev += data[ptr[y]].od;
	    data[ptr[x]].od += data[ptr[y]].ev;
	    data[ptr[x]].ev += pow2[i];
	}

	REP (k, data[ptr[y]].vers.size()) {
	    data[ptr[x]].vers.push_back(data[ptr[y]].vers[k]);
	}
	data[ptr[x]].ids.push_back(i);
	REP (k, data[ptr[y]].ids.size()) {
	    data[ptr[x]].ids.push_back(data[ptr[y]].ids[k]);
	}

	ptr[y] = ptr[x];
	total += data[ptr[x]].ev;

    } else {
	if (ptr[x] == 0) swap(x, y);
	assert(ptr[x]);
	assert(ptr[y] == 0);
	total -= data[ptr[x]].ev;

	if (data[ptr[x]].vers.back() != x) data[ptr[x]].flip();
	{
	    int a = data[ptr[x]].vers.front();
	    ptr[x] = 0;
	    x = a;
	}

	ptr[data[ptr[x]].vers.back()] = 0;

	if (data[ptr[x]].ids.size() % 2 == 1) {
	    data[ptr[x]].od += pow2[i];
	} else {
	    data[ptr[x]].ev += pow2[i];
	}
	data[ptr[x]].vers.push_back(y);
	data[ptr[x]].ids.push_back(i);
	ptr[y] = ptr[x];
	total += data[ptr[x]].ev;
    }
}

VI G[400011];

void OP1() {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    y += L;
    ADD(M+1, x, y);
    M++;

    printf("%d\n", total.geti());
    fflush(stdout);
}

VI ans;
void OP2() {

    ans.clear();

    EACH (e, cycles) {
	for (int i=0; i<(int)data[*e].ids.size(); i+=2) {
	    ans.push_back(data[*e].ids[i]);
	}
    }

    REP (v, L+R) if (ptr[v] && data[ptr[v]].vers[0] == v) {
	for (int i=0; i<(int)data[ptr[v]].ids.size(); i+=2) {
	    ans.push_back(data[ptr[v]].ids[i]);
	}
    }

    eprintf("<<<\n");
    printf("%d ", (int)ans.size());
    rprintf("%d", ans.begin(), ans.end());
    fflush(stdout);
    eprintf(">>>\n");
}

void MAIN() {
    pow2[0] =  1;
    REP (i, 400010) pow2[i+1] = pow2[i] * 2;

    scanf("%d%d%d", &L, &R, &M);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--;
	y--;
	y += L;
	X[i] = x;
	Y[i] = y;
	ADD(i+1, x, y);
    }

    scanf("%d", &Q);
    REP ($, Q) {
	int op;
	scanf("%d", &op);
	if (op == 1) {
	    OP1();
	} else {
	    OP2();
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}