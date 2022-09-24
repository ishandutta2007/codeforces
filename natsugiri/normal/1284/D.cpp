#include<random>
#include<chrono>
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

using ULL = unsigned long long;

ULL gen_seed() {
    char *p = new char;
    return chrono::steady_clock::now().time_since_epoch().count() ^ (ULL) p;
}

mt19937_64 engine(gen_seed());

int N;

ULL Z[100011];
int idx[100011];

vector<ULL> build(pair<int, int> A[]) {
    vector<pair<int, int> > ri(N);
    vector<pair<int, int> > li(N);
    REP (i, N) {
	ri[i] = make_pair(A[i].second, i);
	li[i] = make_pair(A[i].first, i);
    }
    sort(ri.begin(), ri.end());
    sort(li.begin(), li.end());
    const int SIZE = N+10;
    Fenwick<ULL> F(SIZE);
    vector<ULL> ret(N);

    int pos = 0;
    REP (i, N) {
	while (pos < N && li[pos].first <= ri[i].first) {
	    int r = A[li[pos].second].second;
	    int k = lower_bound(ri.begin(), ri.end(), make_pair(r, -1)) - ri.begin();
	    F.add(k, Z[li[pos].second]);
	    pos++;
	}

	{
	    int l = A[ri[i].second].first;
	    int k = lower_bound(ri.begin(), ri.end(), make_pair(l, -1)) - ri.begin();
	    ret[ri[i].second] = F.sum(k, SIZE);
	}

    }
    // rprintf("%llu", ret.begin(), ret.end());
    return ret;
}

pair<int, int> A[100011];
pair<int, int> B[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d%d%d%d", &A[i].first, &A[i].second, &B[i].first, &B[i].second);

    REP (t, 10) engine();
    REP (i, N) Z[i] = engine();

    bool yes = (build(A) == build(B));
    puts(yes? "YES": "NO");

    // int cnt = 0;
    // REP (i, N) REP (j, i) {
    //     bool ag = max(A[i].first, A[j].first) <= min(A[i].second, A[j].second);
    //     bool bg = max(B[i].first, B[j].first) <= min(B[i].second, B[j].second);
    //     if (ag != bg) cnt++;
    // }
    // printf("%d\n", cnt);

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}