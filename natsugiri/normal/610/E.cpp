#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }
struct Seg {
    char l, r;
    int a[10][10];
    char lazy;
    Seg() {
	lazy = 1;
	// l = r = 0;
	// memset(a, 0, sizeof a);
	// lazy = 1;
    }
};
Seg operator+(const Seg &x, const Seg &y) {
    if (x.lazy == 1) return y;
    if (y.lazy == 1) return x;
    
    Seg z = Seg();
    REP (i, 10) REP (j, 10) z.a[i][j] = x.a[i][j] + y.a[i][j];
    z.a[x.r-'a'][y.l-'a'] += 1;
    z.l = x.l;
    z.r = y.r;
    z.lazy = 0;
    return z;
};
Seg seg_all(char c, int l) {
    Seg z = Seg();
    z.l = z.r = z.lazy = c;
    memset(z.a, 0, sizeof z.a);
    z.a[c-'a'][c-'a'] = l-1;
    return z;
}

const Seg unit = Seg();
const int SIZE = 1<<19;
Seg d[SIZE];
struct SegmentTree {
    int n, m;
    // vector<Seg> d;
    SegmentTree(int n): n(n) {
	m=1;
	for (;m<n;) m*=2;
	// d = vector<Seg>(m*2);
	for (int i=0; i<m*2; i++) d[i].lazy = 1;
    }
    // void modify(int x, const Seg &s) {
    // 	x += m;
    // 	d[x] = s;
    // 	for (x/=2; x; x/=2) d[x] = d[x*2] + d[x*2+1];
    // }
    void force(int k, int l) {
	if (k < m && (isalpha(d[k].lazy))) {
	    d[k*2] = d[k*2+1] = seg_all(d[k].lazy, l/2);
	    d[k].lazy = 0;
	}
    }
    void set(int x, int y, char c) { set(x, y, c, 1, 0, m); }
    void set(int x, int y, char c, int k, int l, int r) {
	if (r<=x || y<=l) return;
	force(k, r-l);
	if (x<=l && r<=y) {
	    d[k] = seg_all(c, r-l);
	    return;
	}
	set(x, y, c, k*2, l, (l+r)/2);
	set(x, y, c, k*2+1, (l+r)/2, r);
	d[k] = d[k*2] + d[k*2+1];
    }
    Seg query(int x, int y) { return query(x, y, 1, 0, m); }
    Seg query(int x, int y, int k, int l, int r) {
	if (r<=x || y<=l) return unit;
	force(k, r-l);
	if (x<=l && r<=y) return d[k];
	return query(x, y, k*2, l, (l+r)/2) + query(x, y, k*2+1, (l+r)/2, r);
    }
};

int N, M, K;
char S[200111];
char buf[99];
int main() {
    scanf("%d%d%d", &N, &M, &K);

    scanf("%s", S);
    SegmentTree X(N);
    REP (i, N) X.set(i, i+1, S[i]);

    REP ($, M) {
	    
	int op;
	scanf("%d", &op);
	if (op == 1) {
	    int l, r;
	    scanf("%d%d%s", &l, &r, buf);
	    l--;
	    X.set(l, r, buf[0]);
	} else {
	    scanf("%s", buf);
	    Seg seg = X.query(0, N);
	    int ans = N;
	    REP (r, K) REP (l, r) {
		ans -= seg.a[buf[l]-'a'][buf[r]-'a'];
	    }

	    printf("%d\n", ans);
	}
    }
    return 0;
}