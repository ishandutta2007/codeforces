#include<stack>
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

template<unsigned MOD> struct ModInt {
    static const unsigned static_MOD = MOD;
    unsigned x;
    void undef() { x = (unsigned)-1; }
    bool isnan() const { return x == (unsigned)-1; }
    inline int geti() const { return (int)x; }
    ModInt() { x = 0; }
    ModInt(const ModInt &y) { x = y.x; }
    ModInt(int y) { if (y<0 || (int)MOD<=y) y %= (int)MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned y) { if (MOD<=y) x = y % MOD; else x = y; }
    ModInt(long long y) { if (y<0 || MOD<=y) y %= MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned long long y) { if (MOD<=y) x = y % MOD; else x = y; }
    ModInt &operator+=(const ModInt y) { if ((x += y.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(const ModInt y) { if ((x -= y.x) & (1u<<31)) x += MOD; return *this; }
    ModInt &operator*=(const ModInt y) { x = (unsigned long long)x * y.x % MOD; return *this; }
    ModInt &operator/=(const ModInt y) { x = (unsigned long long)x * y.inv().x % MOD; return *this; }
    ModInt operator-() const { return (x ? MOD-x: 0); }

    ModInt inv() const {
	unsigned a = MOD, b = x; int u = 0, v = 1;
	while (b) {
	    int t = a / b;
	    a -= t * b; swap(a, b);
	    u -= t * v; swap(u, v);
	}
	if (u < 0) u += MOD;
	return ModInt(u);
    }
    ModInt pow(long long y) const {
	ModInt b = *this, r = 1;
	if (y < 0) { b = b.inv(); y = -y; }
	for (; y; y>>=1) {
	    if (y&1) r *= b;
	    b *= b;
	}
	return r;
    }
    friend ModInt operator+(ModInt x, const ModInt y) { return x += y; }
    friend ModInt operator-(ModInt x, const ModInt y) { return x -= y; }
    friend ModInt operator*(ModInt x, const ModInt y) { return x *= y; }
    friend ModInt operator/(ModInt x, const ModInt y) { return x *= y.inv(); }
    friend bool operator<(const ModInt x, const ModInt y) { return x.x < y.x; }
    friend bool operator==(const ModInt x, const ModInt y) { return x.x == y.x; }
    friend bool operator!=(const ModInt x, const ModInt y) { return x.x != y.x; }
};

const LL MOD = 1000000007;
typedef ModInt<MOD> Mint;

const int MAXN = 100011;
int N;
VI G[MAXN];

int iter[MAXN];
VI ord;
int par[MAXN];
void dfs() {
    ord.reserve(N*4);
    stack<int> st;
    st.push(0);
    par[0] = 0;
    while (!st.empty()) {
	int v = st.top();
	if (ord.empty() || ord.back() != v) {
	    ord.push_back(v);
	}

	if (iter[v] == (int)G[v].size()) {
	    st.pop();
	} else {
	    int w = G[v][iter[v]++];
	    if (w == par[v]) {
		// NOTHING;
	    } else {
		par[w] = v;
		st.push(w);
	    }
	}
    }
}

int K, M, R;
int A[MAXN];
VI H[MAXN];

Mint dp[311];

void MAIN() {
    int Q;
    scanf("%d%d", &N, &Q);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    dfs();

    int len = ord.size();
    REP (i, len-1) {
	H[ord[i]].push_back(i);
    }
    REP (i, ord.size()) {
	H[ord[i]].push_back(i+len-1);
    }

    REP ($, Q) {
	scanf("%d%d%d", &K, &M, &R);
	R--;
	REP (i, K) scanf("%d", A+i), A[i]--;
	
	int left = H[R][0];
	int right = left + len - 1;
	vector<pair<int, int> > ps;
	REP (i, K) {
	    int v = A[i];
	    int a = *lower_bound(H[v].begin(), H[v].end(), left);
	    int b = *prev(upper_bound(H[v].begin(), H[v].end(), right));
	    ps.emplace_back(a, b);
	}
	sort(ps.begin(), ps.end());

	memset(dp, 0, sizeof (Mint) * (M+1));
	dp[0] = 1;
	stack<pair<int, int> > st;
	REP (i, K) {
	    while (!st.empty() && (ps[i].second < st.top().first || st.top().second < ps[i].first)) {
		st.pop();
	    }
	    for (int m=M; m>=(int)st.size(); m--) {
		if (m < M) dp[m+1] += dp[m];
		dp[m] *= m - (int)st.size();
	    }
	    st.push(ps[i]);
	}

	Mint ans = 0;
	REP (m, M+1) ans += dp[m];
	printf("%d\n", ans.geti());
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}