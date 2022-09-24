#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<set>

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

template<class T> struct DiffSet {
    multiset<T> num, diff;

    DiffSet() { }

    // data is not a ref;
    DiffSet(vector<T> data) {
	sort(data.begin(), data.end());
	num = multiset<T>(data.begin(), data.end());
	if (data.size() >= 2u) {
	    for (int i=data.size()-2u; i>=0; i--) data[i+1] -= data[i];
	    diff = multiset<T>(data.begin()+1, data.end());
	}
    }

    // insert v if doesn't have;
    bool insert_unique(const T &v) {
	auto right = num.lower_bound(v);
	if (right != num.end() && *right == v) return false;

	if (right != num.begin()) {
	    auto left = prev(right);
	    if (right != num.end()) { diff.erase(diff.find(*right - *left)); }
	    diff.insert(v - *left);
	} 
	if (right != num.end()) { diff.insert(*right - v); }
	num.insert(v);
	return true;
    }

    // insert v anyway;
    bool insert_multi(const T &v) {
	auto right = num.lower_bound(v);
	if (right != num.begin()) {
	    auto left = prev(right);
	    if (right != num.end()) { diff.erase(diff.find(*right - *left)); }
	    diff.insert(v - *left);
	}
	if (right != num.end()) { diff.insert(*right - v); }
	num.insert(v);
	return true;
    }

    // erase single v if it has;
    bool erase_one(const T &v) {
	auto it = num.find(v);
	if (it == num.end()) return false;
	auto right = next(it);
	if (right != num.end()) { diff.erase(diff.find(*right - v)); }
	if (it != num.begin()) {
	    auto left = prev(it);
	    diff.erase(diff.find(v - *left));
	    if (right != num.end()) { diff.insert(*right - *left); }
	}
	num.erase(it);
	return true;
    }

    bool empty() const {
	return num.empty();
    }

    bool diff_empty() const {
	return diff.empty();
    }

    bool contains(const T &v) const {
	return num.find(v) != num.end();
    }

    bool diff_contains(const T &v) const {
	return diff.find(v) != diff.end();
    }

    T max_diff() const {
	assert(diff.size() >= 1u);
	return *diff.rbegin();
    }

    T min_diff() const {
	assert(diff.size() >= 1u);
	return *diff.begin();
    }
};


int N, Q;
int P[100011];

void MAIN() {

    scanf("%d%d", &N, &Q);
    REP (i, N) scanf("%d", P+i);

    sort(P, P+N);
    DiffSet<int> ds(VI(P, P+N));

    auto print = [&]() {
	int ans = 0;
	if (!ds.diff_empty()) {
	    ans = *ds.num.rbegin() - *ds.num.begin() - ds.max_diff();
	}

	printf("%d\n", ans);
    };
    
    print();

    REP ($, Q) {
	int t, x;
	scanf("%d%d", &t, &x);
	if (t == 0) {
	    ds.erase_one(x);
	} else {
	    ds.insert_multi(x);
	}

	print();
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}