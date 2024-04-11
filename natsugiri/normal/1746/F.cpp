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

#include<random>
#include<chrono>
#include<memory>

uint64_t murmurhash3mixer(uint64_t x) {
    x ^= (x >> 33);
    x *= 0xff51afd7ed558ccdULL;
    x ^= (x >> 33);
    x *= 0xc4ceb9fe1a85ec53ULL;
    x ^= (x >> 33);
    return x;
}

seed_seq seq{
    (uint64_t) chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
	(uint64_t) __builtin_ia32_rdtsc(),
	(uint64_t) (uintptr_t) make_unique<char>().get(),
	murmurhash3mixer(random_device()()),
};

mt19937_64 engine(seq);
template<class T> vector<int> compress(const T* v, int n, vector<T> *unq=NULL) {
    vector<pair<T, int> > t(n);
    for (int i=0; i<n; i++) t[i] = make_pair(v[i], i);
    sort(t.begin(), t.end());
    vector<int> r(n);
    int cur = 0;
    for (int i=0, k=0; i<n; i++) {
	if (t[k].first < t[i].first) k = i, cur++;
	r[t[i].second] = cur;
    }
    if (unq) {
	unq->resize(cur+1);
	cur = 0;
	for (int i=0; i<n; i++)
	    if (i == 0 || t[i-1].first < t[i].first)
		(*unq)[cur++] = t[i].first;
    }
    return r;
}

template<class T> vector<int> compress(const vector<T> &v, vector<T> *unq=NULL) {
    return compress(v.data(), v.size(), unq);
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
    inline T sum(int r) const {
	T s = T();
	for (; r; r&=r-1) s += d[r-1];
	return s;
    }
    T sum(int l, int r) const {
	return sum(r) - sum(l);
    }
};

int N, Q;
int A[300011];

int TYPE[300011];
int OP[300011][3];
int ans[300011];
const int MAGIC = 28;

int sz;
int bk[300011];
LL H[600011];

void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, N) scanf("%d", A+i);

    REP (i, Q) {
	scanf("%d", TYPE+i);
	REP (t, TYPE[i] + 1) scanf("%d", OP[i]+t);
    }


    {
	VI X;
	REP (i, N) X.push_back(A[i]);
	REP (i, Q) {
	    if (TYPE[i] == 1) {
		X.push_back(OP[i][1]);
	    }
	}

	VI C = compress(X);
	sz = *max_element(C.begin(), C.end()) + 1;

	for (int i=Q; i--;) {
	    if (TYPE[i] == 1) {
		OP[i][1] = C.back();
		C.pop_back();
	    }
	}
	for (int i=N; i--;) {
	    A[i] = C.back();
	    C.pop_back();
	}
    }

    int idx = 0;
    REP (t, MAGIC) {
	idx = 0;

	REP (i, sz) H[i] = engine() % (1LL<<32);

	Fenwick<LL> F(N);
	REP (i, N) {
	    F.add(i, H[A[i]]);
	    bk[i] = A[i];
	}

	REP (i, Q) {
	    if (TYPE[i] == 1) {
		int pos = OP[i][0] - 1;
		LL from = H[A[pos]];
		LL to = H[OP[i][1]];

		F.add(pos, to - from);
		A[pos] = OP[i][1];
	    } else {
		int l = OP[i][0] - 1;
		int r = OP[i][1];
		int k = OP[i][2];

		LL sum = F.sum(l, r);
		if ((r-l) % k == 0 && sum % k == 0) {
		    ans[idx]++;
		}
		idx++;
	    }
	}

	REP (i, N) A[i] = bk[i];
    }

    REP (i, idx) {
	if (ans[i] == MAGIC) {
	    puts("YES");
	} else {
	    puts("NO");
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}