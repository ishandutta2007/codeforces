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
template<class Key, class Value>
struct RangeMap {
    // [-INF, x0), [x0, x1), [x1, x2), ..., [xk, INF);
    // v0,         v1,       v2,       ..., v{k+1} = init_value;
    map<Key, Value> mp;
    Value init_value;

    RangeMap(): init_value() {}

    RangeMap(const Value &init_value_): init_value(init_value_) {}

    const Value& at(const Key &x) {
	auto it = mp.upper_bound(x);
	if (it == mp.end()) return init_value;
	else return it->second;
    }

    pair<Key, Key> equal_range(const Key &x, const Key &left_limit, const int &right_limit) {
	auto it = mp.upper_bound(x);
	return make_pair(
		it == mp.begin()? left_limit: prev(it)->first,
		it == mp.end()? right_limit: it->first);
    }

    void chop(const Key &pos) {
	auto it = mp.lower_bound(pos);
	if (it == mp.end()) {
	    mp.emplace(pos, init_value);
	} else if (pos < it->first) {
	    mp.emplace(pos, it->second);
	}
    }

    void join_if_same(const Key &pos) {
	auto it = mp.find(pos);
	if (it != mp.end() && it != mp.begin()) {
	    auto left = prev(it);
	    if (it->second == left->second) {
		mp.erase(left);
	    }
	}
    }

    // e.x.: fold_modify(10, 20, [&acc](Key l, Key r, Value v) { acc += v * (r-l); });
    template<class Func>
    void fold_overwrite(const Key &left, const Key &right, Func f, const Value &overwrite) {
	chop(left);
	chop(right);
	Key a = left;
	auto it = mp.upper_bound(a);
	while (it != mp.end() && it->first <= right) {
	    f(a, it->first, it->second);
	    a = it->first;
	    mp.erase(it++);
	}
	mp.emplace(right, overwrite);
	join_if_same(left);
	join_if_same(right);
    }

    // e.x.: fold_modify(10, 20, [&acc](Key l, Key r, Value &v) { acc += v * (r-l); });
    template<class Func>
    void fold_summary(const Key &left, const Key &right, Func f) {
	chop(left);
	chop(right);
	Key a = left;
	auto it = mp.upper_bound(a);
	auto bk = it;
	while (it != mp.end() && it->first <= right) {
	    f(a, it->first, it->second);
	    a = it->first;
	    it++;
	}
	it = bk;
	while (it != mp.end() && it->first <= right) {
	    if (it != mp.begin()) {
		auto it_left = prev(it);
		if (it->second == it_left->second) {
		    mp.erase(it_left);
		}
	    }
	    it++;
	}
    }
};

int N;
LL T;
LL G[200011];
LL C[200011];
LL D[200011];
LL sumD[200011];

LL cost[200011];
LL Start[200011];
LL End[200011];

void MAIN() {
    scanf("%d%lld", &N, &T);
    REP (i, N) scanf("%lld%lld", G+i, C+i);
    REP (i, N-1) {
	scanf("%lld", D+i);
	sumD[i+1] = D[i] + sumD[i];
    }
    
    // green [-C[i], G[i]-C[i]);
    // green [-C[i]-sumD[i], G[i]-C[i]-sumD[i]);
    RangeMap<LL, int> mp(N);

    for (int i=N; i--;) {

	Start[i] = G[i]-C[i]-sumD[i];
	Start[i] %= T;
	if (Start[i] < 0) Start[i] += T;

	LL r = T - G[i];
	End[i] = (Start[i]+r) % T;

	LL nxt = mp.at(End[i]);
	cost[i] = cost[nxt];
	if (nxt < N) {
	    if (End[i] < End[nxt]) {
		cost[i] += End[nxt] - End[i];
	    } else {
		cost[i] += End[nxt] - End[i] + T;
	    }
	}

	auto f = [](LL, LL, int) {};

	if (Start[i] <= End[i]) {
	    // [Start, Start + r);
	    mp.fold_overwrite(Start[i], End[i], f, i);
	} else {
	    // [0, (Start + r) % T);
	    // [Start, T);
	    mp.fold_overwrite(Start[i], T, f, i);
	    mp.fold_overwrite(0, End[i], f, i);
	}

    }

    LL ans = 1LL<<60;
    mp.fold_summary(0, T, [&ans](LL l, LL r, int idx) {
	    // eprintf("%lld %lld %d\n", l, r, idx);
	    if (idx == N) {
	        ans = 0;
	    } else {
	        LL cur = r - 1;
		if (cur < End[idx]) {
		    amin(ans, cost[idx] + End[idx] - cur);
		} else {
		    amin(ans, cost[idx] + End[idx] - cur + T);
		}
	    }
	    });

    printf("%lld\n", ans + sumD[N-1]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}