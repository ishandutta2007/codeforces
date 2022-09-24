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

template<class T> struct RangeTree {
    int m;
    int *sz;
    T **data, **sums;
    RangeTree() : m(0), sz(0), data(0), sums(0) {}
    template<class Iter> RangeTree(Iter begin, Iter end, bool enable_sums) : m(0), sz(0), data(0), sums(0) {
	int n = end - begin;
	int h;
	if (n <= 1) { h = 1; m = 1; }
	else { h = __lg(n-1) + 2; m = 1 << (h-1); }
	sz = new int[2*m]();
	data = new T*[2*m];
	T* data_p = data[0] = new T[n*h];
	for (int i=0; i<n; i++) {
	    sz[i+m] = 1;
	    data[i+m] = data_p;
	    *data_p = *begin;
	    data_p++; ++begin;
	}
	for (int i=m; --i;) {
	    sz[i] = sz[2*i] + sz[2*i+1];
	    data[i] = data_p;
	    data_p += sz[i];
	    merge(data[i*2], data[i*2] + sz[i*2], data[i*2+1], data[i*2+1] + sz[i*2+1], data[i]);
	}
	
	// build sums;
	if (enable_sums) {
	    sums = new T*[2*m];
	    data_p = sums[0] = new T[n*h+2*m];
	    for (int i=1; i<2*m; i++) {
		sums[i] = data_p;
		data_p += sz[i] + 1;
		for (int j=0; j<sz[i]; j++) sums[i][j+1] = sums[i][j] + data[i][j];
	    }
	}
    }

    ~RangeTree() {
	if (sz) {
	    delete[] sz; sz = 0;
	}
	if (data) {
	    delete[] data[0]; data[0] = 0;
	    delete[] data; data = 0;
	}
	if (sums) {
	    delete[] sums[0]; sums[0] = 0;
	    delete[] sums; sums = 0;
	}
    }

    // #[i | lo<=val(i)<hi and i<-[x,y)]
    int count(int x, int y, const T&lo, const T&hi) { return count(x, y, lo, hi, 1, 0, m); }
    int count(int x, int y, const T&lo, const T&hi, int k, int l, int r) {
	if (r<=x || y<=l) return 0;
	if (x<=l && r<=y) {
	    pair<T*, T*> p = find_range(data[k], data[k] + sz[k], lo, hi);
	    return p.second - p.first;
	}
	return count(x, y, lo, hi, k*2, l, (l+r)/2)+count(x, y, lo, hi, k*2+1, (l+r)/2, r);
    }

    // Returns index O(log^2 n);
    // [i | lo<=val(i)<hi and i<-[x,y)] ! n, or -1;
    int nth(int x, int y, const T&lo, const T&hi, int n) {
	return nth(x, y, lo, hi, n, 1, 0, m).first;
    }

    // (index, #);
    pair<int, int> nth(int x, int y, const T&lo, const T&hi, int n, int k, int l, int r) {
	if (r<=x || y<=l) return make_pair(-1, 0);
	if (x<=l && r<=y) {
	    if (r-l == 1) {
		if (lo <= *data[k] && *data[k] < hi) return make_pair(l, 1);
		else return make_pair(-1, 0);
	    }
	    pair<T*, T*> p = find_range(data[k], data[k] + sz[k], lo, hi);
	    int c = p.second - p.first;
	    if (c <= n) return make_pair(-1, c);
	}
	pair<int, int> a = nth(x, y, lo, hi, n, k*2, l, (l+r)/2);
	if (a.first != -1) return a;
	pair<int, int> b = nth(x, y, lo, hi, n-a.second, k*2+1, (l+r)/2, r);
	return make_pair(b.first, a.second + b.second);
    }

    T sum(int x, int y, const T&lo, const T&hi) {
	return sum(x, y, lo, hi, 1, 0, m);
    }

    T sum(int x, int y, const T&lo, const T&hi, int k, int l, int r) {
	if (r<=x || y<=l) return T();
	if (x<=l && r<=y) {
	    pair<T*, T*> p = find_range(data[k], data[k] + sz[k], lo, hi);
	    return sums[k][p.second - data[k]] - sums[k][p.first - data[k]];
	}
	return sum(x, y, lo, hi, k*2, l, (l+r)/2)+sum(x, y, lo, hi, k*2+1, (l+r)/2, r);
    }

private:
    template<class Iter> pair<Iter, Iter> find_range(Iter begin, Iter end, const T&lo, const T&hi) {
	int len = end - begin;
	while (len > 0) {
	    int half = len >> 1;
	    Iter mid = begin + half;
	    if (*mid < lo) {
		begin = mid + 1;
		len -= half + 1;
	    } else if (*mid < hi) {
		return make_pair(lower_bound(begin, mid, lo), lower_bound(mid, end, hi));
	    } else {
		end = mid;
		len = half;
	    }
	}
	return make_pair(begin, begin);
    }
};

int N, K, Q;
int A[100111];
VI ap[100111];
int B[100111];

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", A+i);

    REP (i, N) {
	if ((int)ap[A[i]].size() < K) {
	    B[i] = -1;
	} else {
	    B[i] = ap[A[i]].rbegin()[K-1];
	}
	ap[A[i]].push_back(i);
    }

    RangeTree<int> X(B, B+N, false);
//    rprintf("%d", B, B+N);
    scanf("%d", &Q);
    int last = 0;
    REP ($, Q) {
	int x, y;
	scanf("%d%d", &x, &y);
	int L = (x + last) % N + 1;
	int R = (y + last) % N + 1;
	if (L > R) swap(L, R);
	L--;

	last = X.count(L, R, -1, L);
	printf("%d\n", last);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}