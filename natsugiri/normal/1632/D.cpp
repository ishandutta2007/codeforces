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
LL gcd(LL x_, LL y_) {
    typedef unsigned long long ULL;
    ULL x = abs(x_);
    ULL y = abs(y_);
    while (1) {
	if (x) y %= x; else return y;
	if (y) x %= y; else return x;
    }
}

struct Seg {
    int x;
    Seg() : x(0) {}
    Seg(int x_) : x(x_) {}
    static Seg IDENTITY;
};
Seg Seg::IDENTITY = Seg();
Seg operator+(const Seg &x, const Seg &y) {
    return Seg(gcd(x.x, y.x));
}

template<class Seg> struct SlidingWindow {
    // deque { 0, 1, 2, 3, 4, 5,};
    // fr { 2, 1, 0 } | bk { 3, 4, 5 };
    // pair<Seg, Seg>: first = elem; second = acc that contanis the elem;
    // Getters' second values are meaningless;
    vector<pair<Seg, Seg> > fr, bk;

    SlidingWindow() { }

    size_t size() const {
	return fr.size() + bk.size();
    }

    bool empty() const {
	return fr.empty() && bk.empty();
    }

    pair<Seg, Seg>& operator[](size_t i) {
	if (i < fr.size()) return fr[fr.size() - 1 - i];
	return bk[i - fr.size()];
    }

    const pair<Seg, Seg>& operator[](size_t i) const {
	if (i < fr.size()) return fr[fr.size() - 1 - i];
	return bk[i - fr.size()];
    }

    pair<Seg, Seg>& back() {
	if (bk.empty()) return fr[0];
	return bk.back();
    }

    const pair<Seg, Seg>& back() const {
	if (bk.empty()) return fr[0];
	return bk.back();
    }

    void push_back(const Seg &s) {
	if (bk.empty()) bk.emplace_back(s, s);
	else bk.emplace_back(s, bk.back().second + s);
    }

    void pop_back() {
	if (bk.empty()) {
	    pop_back_helper(fr, bk);
	    build_front();
	    build_back();
	} else {
	    bk.pop_back();
	}
    }

    pair<Seg, Seg>& front() {
	if (fr.empty()) return bk[0];
	return fr.back();
    }

    const pair<Seg, Seg>& front() const {
	if (fr.empty()) return bk[0];
	return fr.back();
    }

    void push_front(const Seg &s) {
	if (fr.empty()) fr.emplace_back(s, s);
	else fr.emplace_back(s, s + fr.back().second);
    }

    void pop_front() {
	if (fr.empty()) {
	    pop_back_helper(bk, fr);
	    build_front();
	    build_back();
	} else {
	    fr.pop_back();
	}
    }

    Seg query() const {
	if (empty()) return Seg::IDENTITY;
	if (fr.empty()) return bk.back().second;
	if (bk.empty()) return fr.back().second;
	return fr.back().second + bk.back().second;
    }

    // It requires Seg commutativity;
    // x + y == y + x;
    void reverse() {
	swap(fr, bk);
    }

    // O(n) times Seg appends;
    void slow_reverse() {
	swap(fr, bk);
	build_front();
	build_back();
    }

    static void pop_back_helper(vector<pair<Seg, Seg> > &fr, vector<pair<Seg, Seg> > &bk) {
	assert(bk.empty());
	size_t s = fr.size();
	size_t t = (s-1)/2;
	bk.resize(t);
	for (size_t i=1; i<=t; i++) bk[t-i] = fr[i];
	for (size_t i=t+1; i<s; i++) fr[i-t-1] = fr[i];
	fr.resize(s-1-t);
    }

    void build_front() {
	if (fr.empty()) return;
	fr[0].second = fr[0].first;
	for (size_t i=1; i<fr.size(); i++) fr[i].second = fr[i].first + fr[i-1].second;
    }

    void build_back() {
	if (bk.empty()) return;
	bk[0].second = bk[0].first;
	for (size_t i=1; i<bk.size(); i++) bk[i].second = bk[i-1].second + bk[i].first;
    }
};

int N;
int A[200011];
int ans[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    SlidingWindow<Seg> S;
    int cnt = 0;
    int left = 0;
    REP (i, N) {
	S.push_back(A[i]);
	while (S.query().x < i+1-left) {
	    left++;
	    S.pop_front();
	}
	if (S.query().x == i+1-left) {
	    cnt++;
	    left = i+1;
	    while (!S.empty()) S.pop_back();
	}
	ans[i] = cnt;
    }

    rprintf("%d", ans, ans+N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}