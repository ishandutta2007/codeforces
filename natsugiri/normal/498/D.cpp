#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0,i##_len=(n); i<i##_len; i++)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

struct Seg {
    int T[60];
    Seg() {}
};
Seg operator+(const Seg&x, const Seg&y) {
    Seg z;
    REP (i, 60) {
	int t = x.T[i];
	z.T[i] = t + y.T[(t+i) % 60];
    }
    return z;
}

Seg single(int a) {
    Seg s;
    if (a == -1) {
	memset(s.T, 0, sizeof s.T);
    } else {
	REP (i, 60) {
	    if (i % a == 0) s.T[i] = 2;
	    else s.T[i] = 1;
	}
    }
    return s;
}
    
struct SegTree {
    int n, m;
    vector<Seg>data;
    SegTree(int n) :n(n) {
	m=1;
	for (;m<n;) m*=2;
	data=vector<Seg>(m*2);
    }
    void update(int x, int a) {
	x += m;
	data[x] = single(a);
	for (x/=2; x; x/=2) data[x] = data[x*2] + data[x*2+1];
    }
    Seg query(int x, int y) { return query(x, y, 1, 0, m); }
    Seg query(int x, int y, int k, int l, int r) {
	if (r<=x || y<=l) return single(-1);
	if (x<=l && r<=y) return data[k];
	return query(x, y, k*2, l, (l+r)/2)+query(x, y, k*2+1, (l+r)/2, r);
    }
};


int N;
int Q;
char buf[99];
int X, Y;
int main() {
    scanf("%d", &N);
    SegTree S(N);
    REP (i, N) {
	int a;
	scanf("%d", &a);
	S.update(i, a);
    }

    scanf("%d", &Q);

    REP ($, Q) {
	scanf("%s%d%d", buf, &X, &Y);
	if (buf[0] == 'A') {
	    Seg seg = S.query(X-1, Y-1);
	    printf("%d\n", seg.T[0]);
	} else {
	    S.update(X-1, Y);
	}
    }

    return 0;
}