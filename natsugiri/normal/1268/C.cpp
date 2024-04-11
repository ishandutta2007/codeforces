#include<queue>
#include<set>
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
    inline T sum(int r) {
	T s = T();
	for (; r; r&=r-1) s += d[r-1];
	return s;
    }
    T sum(int l, int r) {
	return sum(r) - sum(l);
    }
};
int N;
int A[200011];
pair<int, int> P[200011];
LL ans[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i), A[i]--;

    REP (i, N) P[i] = make_pair(A[i], i);
    sort(P, P+N);

    priority_queue<int> Lq;
    priority_queue<int, VI, greater<int> > Rq;
    Fenwick<int> F(N+11);
    LL Lsum = 0, Rsum = 0;
    LL inv_sum = 0;

    REP (i, N) {
	inv_sum += F.sum(P[i].second, N);

	int pos = P[i].second;
	F.add(P[i].second, 1);

	if (i % 2 == 1) {
	    Rq.push(pos);
	    Rsum += pos;
	} else {
	    Lq.push(pos);
	    Lsum += pos;
	}
	while (Lq.size() && Rq.size() && Lq.top() > Rq.top()) {
	    int x = Lq.top(); Lq.pop();
	    Lsum -= x;
	    int y = Rq.top(); Rq.pop();
	    Rsum -= y;

	    Lq.push(y);
	    Lsum += y;
	    Rq.push(x);
	    Rsum += x;
	}

	LL g = Lq.top();
	LL ls = Lq.size();
	LL rs = Rq.size();
	LL cost = 0;
	cost += (g*ls - Lsum) - ls*(ls-1)/2;
	cost += (Rsum - g*rs) - rs*(rs+1)/2;

	ans[i] = cost + inv_sum;
    }

    rprintf("%lld", ans, ans+N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}