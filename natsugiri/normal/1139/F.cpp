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

const int SIZE = 100011;
int N, M;
int P[SIZE], S[SIZE], B[SIZE];
int inc[SIZE], pref[SIZE];

VI Bs;

struct Seg {
    VI v;
    Fenwick<int> f;

    void build() {
	sort(v.begin(), v.end());
	f = Fenwick<int>(v.size());
    }

    void add(int x, int val) {
	int k = lower_bound(v.begin(), v.end(), x) - v.begin();;
	f.add(k, val);
    }

    int sum(int val) {
	int k = upper_bound(v.begin(), v.end(), val) - v.begin();;
	return f.sum(k);
    }
} seg[SIZE];

void clear() {
    REP (i, SIZE) seg[i].v.clear();
}

void SAdd(int i, int x) {
    for (; i<SIZE; i|=i+1) seg[i].v.push_back(x);
}
void SInc(int i, int x, int val) {
    for (; i<SIZE; i|=i+1) {
	seg[i].add(x, val);
    }
}

int query(int r, int val) {
    int s = 0;
    for (; r; r&=r-1) s += seg[r-1].sum(val);
    return s;
}

void build() {
    REP (i, SIZE) seg[i].build();
}

pair<int, int> EvP[SIZE];
pair<int, int> EvS[SIZE];
pair<int, int> EvI[SIZE];
int ans[SIZE];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", P+i);
    REP (i, N) scanf("%d", S+i);
    REP (i, N) scanf("%d", B+i);
    REP (i, M) scanf("%d", inc+i);
    REP (i, M) scanf("%d", pref+i);

    REP (i, N) {
	EvP[i] = make_pair(P[i], i);
	EvS[i] = make_pair(S[i], i);
    }
    sort(EvP, EvP+N);
    sort(EvS, EvS+N);
    REP (i, M) EvI[i] = make_pair(inc[i], i);
    sort(EvI, EvI+M);

    // B[i] < pref[j];
    // B[i] >= pref[j];
    REP (t, 2) {
	Bs.assign(B, B+N);
	sort(Bs.begin(), Bs.end());
	Bs.erase(unique(Bs.begin(), Bs.end()), Bs.end());

	clear();
	REP (i, N) {
	    int k = lower_bound(Bs.begin(), Bs.end(), B[i]) - Bs.begin();
	    SAdd(k, P[i] - B[i]);
	}
	build();

	int p_i = 0, s_i = 0;

	REP (i, M) {
	    int inc_ = EvI[i].first;
	    int pref_ = pref[EvI[i].second];
	    eprintf("find %d %d\n", inc_, pref_);

	    while (p_i < N && EvP[p_i].first <= inc_) {
		int id = EvP[p_i].second;
		eprintf("add %d %d %d\n", P[id], S[id], B[id]);
		int k = lower_bound(Bs.begin(), Bs.end(), B[id]) - Bs.begin();
		SInc(k, P[id] - B[id], 1);
		p_i++;
	    }
	    while (s_i < N && EvS[s_i].first < inc_) {
		int id = EvS[s_i].second;
		eprintf("del %d %d %d\n", P[id], S[id], B[id]);
		int k = lower_bound(Bs.begin(), Bs.end(), B[id]) - Bs.begin();
		SInc(k, P[id] - B[id], -1);
		s_i++;
	    }

	    {
		int k = lower_bound(Bs.begin(), Bs.end(), pref_+t) - Bs.begin();
		ans[EvI[i].second] += query(k, inc_ - pref_);
	    }
	}

	REP (i, N) B[i] = -B[i];
	REP (j, M) pref[j] = -pref[j];
    }

    rprintf("%d", ans, ans+M); 
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}