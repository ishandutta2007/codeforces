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

struct AddMinimum {
    typedef long long T;
    static const T INF = 1LL<<60;
    int N, M;
    vector<T> data, part;
    AddMinimum(int N_=1): N(N_), M(2<<__lg(max(1, N))), data(2*M), part(2*M) {}
    AddMinimum(const vector<T> &A): N(A.size()), M(2<<__lg(max(1, N))), data(2*M), part(2*M) {
	for (int i=0; i<N; i++) data[i+M] = A[i];
	for (int i=M; --i;) data[i] = min(data[2*i], data[2*i+1]);
    }
    void add(int x, int y, const T &v) { add(x, y, 1, 0, M, v); }
    void add(int x, int y, int k, int l, int r, const T &v) {
	if (x <= l && r <= y) part[k] += v;
	else if (x < r && l < y) {
	    add(x, y, k*2, l, (l+r)/2, v); add(x, y, k*2+1, (l+r)/2, r, v);
	    data[k] = min(data[k*2] + part[k*2], data[k*2+1] + part[k*2+1]);
	}
    }
    T minimum(int x, int y) { return minimum(x, y, 1, 0, M); }
    T minimum(int x, int y, int k, int l, int r) {
	if (x <= l && r <= y) return data[k] + part[k];
	else if (y <= l || r <= x) return INF;
	else return min(minimum(x, y, k*2, l, (l+r)/2), minimum(x, y, k*2+1, (l+r)/2, r)) + part[k];
    }

    int query() { return query(0, 1, 0, M); }
    int query(int v, int k, int l, int r) {
	if (data[k] + part[k] >= v) return -1;
	if (l + 1 >= r) {
	    if (data[k] + part[k] < v) return l;
	    else return -1;
	}
	int tmp = query(v - part[k], k*2+1, (l+r)/2, r);
	if (tmp == -1) tmp = query(v - part[k], k*2, l, (l+r)/2);
	return tmp;
    }
};
const AddMinimum::T AddMinimum::INF;

int N;
int C[100111];

int main() {
    scanf("%d", &N);

    AddMinimum F(N);

    REP ($, N) {
	int P, T, X;
	scanf("%d%d", &P, &T);
	P--;

	if (T == 0) {
	    F.add(0, P+1, 1);
	} else {
	    scanf("%d", &X);
	    C[P] = X;
	    F.add(0, P+1, -1);
	}

	int pos = F.query();

	int ans;
	if (pos == -1) ans = -1;
	else ans = C[pos];
	printf("%d\n", ans);
    }


    return 0;
}