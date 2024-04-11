#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

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
    int lower_bound(const T &x) { // sum(ret) < x <= sum(ret+1);
	if (n == 0) return 0;
	int i = 0; T s = T();
	for (int k=1<<__lg(n); k; k>>=1) {
	    if (i+k <= n && s + d[i+k-1] < x) {
		i += k; s += d[i-1];
	    }
	}
	return i;
    }
    int upper_bound(const T &x) { // sum(ret) <= x < sum(ret+1);
	if (n == 0) return 0;
	int i = 0; T s = T();
	for (int k=1<<__lg(n); k; k>>=1) {
	    if (i+k <= n && !(x < s + d[i+k-1])) {
		i += k; s += d[i-1];
	    }
	}
	return i;
    }
};
template<class T> vector<int> compress(const vector<T> &v, vector<T> *unq=NULL) {
    int n = v.size();
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

int N;
int W;
int X[100111], V[100111];

struct Ra {
    LL nu, de;
    Ra() {};
    Ra(LL nu_, LL de_) {
	if (de_ < 0) {
	    nu = -nu_;
	    de = -de_;
	} else {
	    nu = nu_;
	    de = de_;
	}
    }

    bool operator<(const Ra &y) const {
	return nu * y.de < y.nu * de;
    }
};

struct ByFirst {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) const {
	return x.first < y.first;
    }
} byFirst;

struct BySecond {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) const {
	return x.second < y.second;
    }
} bySecond;

struct BySpecial {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) const {
	return x.second != y.second ? x.second < y.second : x.first > y.first;
    }
} bySpecial;

const int SIZE = 200011;
LL calc(vector<pair<int, int> > &ne) {
    sort(ne.begin(), ne.end(), bySpecial);
    LL ans = 0;
    Fenwick<int> F(SIZE);
    EACH (e, ne) {
	ans += F.sum(e->first, SIZE);
	F.add(e->first, 1);
    }

    return ans;
}

void MAIN() {
    scanf("%d%d", &N, &W);
    REP (i, N) scanf("%d%d", X+i, V+i);

    vector<Ra> ras;

    REP (i, N) {
	if (V[i] > 0) {
	    // --->
//	    eprintf("%f %f\n", (double)-X[i] / (V[i] + W), (double)-X[i] / (V[i] - W));
	    ras.emplace_back(-X[i], V[i] + W);
	    ras.emplace_back(-X[i], V[i] - W);
//	    ne.emplace_back(Ra(-X[i], V[i] - W), Ra(-X[i], V[i] + W));
	} else {
	    // <---
//	    eprintf("%f %f\n", (double)X[i] / -(V[i] - W), (double)X[i] / -(V[i] + W));
	    ras.emplace_back(X[i], -(V[i] - W));
	    ras.emplace_back(X[i], -(V[i] + W));
//	    po.emplace_back(Ra(X[i], -(V[i] + W)), Ra(X[i], -(V[i] - W)));
	}
    }

    VI rasi = compress(ras);
    vector<pair<int, int> > ne, po;

    {
	int cnt = 0;
	REP (i, N) {
	    pair<int, int> key;
	    key.first = rasi[cnt++];
	    key.second = rasi[cnt++];
	    if (V[i] > 0) {
		ne.push_back(key);
	    } else {
		po.push_back(key);
	    }
	}
    }

    LL ans = 0;
    sort(ne.begin(), ne.end(), bySecond);
    sort(po.begin(), po.end(), byFirst);
    {
	Fenwick<int> F(SIZE);
	int cnt = 0;
	EACH (e, ne) {
	    while (cnt < (int)po.size() && po[cnt].first <= e->second) {
		F.add(po[cnt].second, 1);
		cnt++;
	    }

	    ans += F.sum(e->first, SIZE);
	}
    }

    ans += calc(ne);
    ans += calc(po);

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}