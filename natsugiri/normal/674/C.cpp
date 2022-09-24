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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

struct Seg {
    double a, b, s;
    Seg(): a(0), b(0), s(0) {}
    Seg(int t) {
	a = 1.0 / t;
	b = 1;
	s = t;
    }
};
Seg operator+(const Seg &x, const Seg &y) {
    Seg z;
    z.s = x.s + y.s;
    z.a = x.a + y.a;
    z.b = x.b + y.b + y.a * x.s;
//    z.val = min(x.val, y.val);
    return z;
};
Seg unit = Seg();


// Small Space
struct SegmentTree {
    int n;
    vector<Seg> d;
    SegmentTree(int n=0): n(n), d(2*n) { }
    SegmentTree(int n_, int *T): n(n_), d(2*n) {
	for (int i=0; i<n; i++) d[i+n] = Seg(T[i]);
	for (int i=n; --i; ) d[i] = d[i*2] + d[i*2+1];
    }
    SegmentTree(const vector<Seg> & d_): n(d_.size()), d(2*n) {
	for (int i=0; i<n; i++) d[i+n] = d_[i];
	for (int i=n; --i; ) d[i] = d[i*2] + d[i*2+1];
    }
    void modify(int i, const Seg &s) {
	i += n;
	d[i] = s;
	for (i/=2; i; i/=2) d[i] = d[i*2] + d[i*2+1];
    }
    Seg query(int x, int y) {
	x += n; y += n;
	Seg ls = Seg(), rs = Seg();
	for (; x < y; x>>=1, y>>=1) {
	    if (y & 1) rs = d[--y] + rs;
	    if (x & 1) ls = ls + d[x++];
	}
	return ls + rs;
    }
};

SegmentTree S;


int N, K, T[200111];

// dp[i][j] = min_{k<=j} dp[i-1][k] + C[k][j]
// minimum cosst of K-path of N elements
// O(KN log N) improved from O(KN*2)
// if you want to k<j, C[k][k] := INF

const double INF = 1e102;
double dp[55][200111];
// int cost[4011][4011]; // [k][j], from k to j
int pre_k = -1, pre_j = -1;
Seg pre_seg;
inline double cost(int k, int j) {
    if (k >= j) return INF;

    if (k == pre_k && j == pre_j + 1) {
	pre_seg = pre_seg + Seg(T[j-1]);
    } else if (k == pre_k - 1 && j == pre_j) {
	pre_seg = Seg(T[k]) + pre_seg;
    } else {
	pre_seg = S.query(k, j);
    }
    pre_k = k;
    pre_j = j;

    return pre_seg.b;
}

int slow() {
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0; // init state
    REP (t, K) REP (j, N) REP (k, j+1) {
	amin(dp[t+1][j], dp[t][k] + cost(k, j));
    }
    int ans = dp[K][N-1]; // last state
    return ans;
}


void rec(int t, int x, int y, int l, int r) { // calc dp[t][i] where i in [x .. y)
    if (l+1 == r) {
	for (int i=x; i<y; i++) {
	    amin(dp[t+1][i], dp[t][l] + cost(l, i));
	}
	return ;
    }

    int m = (x + y) / 2;
    int k = l;
    for (int i=min(r-1, m); i>=l; i--) {
	double c = cost(i, m);
	if (dp[t+1][m] > dp[t][i] + c) {
	    dp[t+1][m] = dp[t][i] + c;
	    k = i;
	}
    }
//    for (int i=l; i<r && i<=m; i++) {
//	double c = cost(i, m);
//	if (dp[t+1][m] > dp[t][i] + c) {
//	    dp[t+1][m] = dp[t][i] + c;
//	    k = i;
//	}
//    }

    if (x + 1 >= y) return ;

    rec(t, x, m, l, k+1);
    rec(t, m+1, y, k, r);
}

double solve() {
    REP (k, K+1) REP (i, N+1) dp[k][i] = INF;
    dp[0][0] = 0; // initial state
    // walk K times
    REP (t, K) rec(t, 0, N+1, 0, N+1);
//    double ans = dp[K][N-1]; // last state
    double ans = dp[K][N]; // last state
    return ans;
}

int main() {

    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", T+i);

    S = SegmentTree(N, T);
//    REP (i, N) S.modify(i, Seg(T[i]));

    double ans = solve();
    printf("%.9f\n", ans);

    return 0;
}