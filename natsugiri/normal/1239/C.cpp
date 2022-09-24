#include<set>
#include<queue>
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
template<class T> struct RMQ {
    static const int npos = -1;

    static int ceil_pow2(int n) {
	if (n <= 0) return 0;
	if (n == 1) return 1;
	return 2<<__lg(n-1);
    }

    int n, m;
    vector<T> d;
    RMQ() {}
    RMQ(int n_, const T init=T()) : n(n_), m(ceil_pow2(n)), d(2*m, init) {}

    template<class Iter> void build(Iter begin, Iter end, const T init=T()) {
	n = end - begin;
	m = ceil_pow2(n);
	d.resize(2*m);
	for (int i=0; begin!=end; ++begin, i++) d[i+m] = *begin;
	for (int i=n; i<m; i++) d[i+m] = init;
	for (int i=m; --i; ) d[i] = min(d[i*2+1], d[i*2]);
    };

    const T at(int i) const { return d[i+m]; }

    void modify(int i, const T v) {
	i += m; d[i] = v;
	for (i>>=1; i; i>>=1) d[i] = min(d[i*2+1], d[i*2]);
    }

    T min_v(int l, int r) const {
	l += m; r += m;
	T ret = d[l++];
	for (; l<r; l>>=1, r>>=1) {
	    if (l & 1) { amin(ret, d[l]); l++; }
	    if (r & 1) { r--; amin(ret, d[r]); }
	}
	return ret;
    }

    int min_i(int l, int r) const {
	return first_less_equal(l, min_v(l, r));
    }

    // for i in [l .. n-1]:
    //   if at(i) < v: return i;
    // return npos;
    int first_less_than(int l, const T v) const {
	int r = 2*m;
	for (l+=m; l<r; l>>=1, r>>=1) {
	    if (l & 1) {
		if (d[l] < v) break;
		l++;
	    }
	}
	if (l >= r) return npos;
	for (; l<m;) {
	    if (d[l*2] < v) l = l*2;
	    else l = l*2+1;
	}
	return l - m;
    }

    // for i in [l .. n-1]:
    //   if at(i) <= v: return i;
    // return npos;
    int first_less_equal(int l, const T v) const { 
	int r = 2*m;
	for (l+=m; l<r; l>>=1, r>>=1) {
	    if (l & 1) {
		if (d[l] <= v) break;
		l++;
	    }
	}
	if (l >= r) return npos;
	for (; l<m;) {
	    if (d[l*2] <= v) l = l*2;
	    else l = l*2+1;
	}
	return l - m;
    }
};

const LL INF = 1LL<<60;
int N;
LL P;
LL T[100011];
LL ans[100011];

void MAIN() {
    scanf("%d%lld", &N, &P);
    REP (i, N) scanf("%lld", T+i);

    RMQ<LL> rmq; rmq.build(T, T+N, INF);
    set<int> se;
    se.insert(N);
    queue<pair<int, LL> > qu;
    priority_queue<int, VI, greater<int> > pq;

    LL tm = 0;
    int cnt = 0;
    while (cnt < N) {
	if (!qu.empty() && qu.front().second <= tm) {
	    cnt++;
	    ans[qu.front().first] = qu.front().second;
	    se.erase(qu.front().first);
	    qu.pop();
	} else if (rmq.min_v(0, N) <= tm) {
	    int k = rmq.min_i(0, N);
	    pq.push(k);
	    rmq.modify(k, INF);
	} else if (!pq.empty() && pq.top() < *se.begin()) {
	    int k = pq.top(); pq.pop();
	    se.insert(k);
	    if (qu.empty()) {
		qu.emplace(k, tm + P);
	    } else {
		LL sz = qu.size();
		qu.emplace(k, qu.front().second + sz * P);
	    }
	} else {
	    LL a = (qu.empty()? INF: qu.front().second);
	    LL b = rmq.min_v(0, N);
	    tm = max(tm, min(a, b));
	}
    }
    rprintf("%lld", ans, ans+N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}