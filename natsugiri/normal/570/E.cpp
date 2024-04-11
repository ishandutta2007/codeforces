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

template<int MOD>
struct ModInt {
    unsigned x;
    void undef() { x = -1; }
    bool isnan() { return x == -1; }
    template<class T> T get() const {return (T)x; }
    int mod() const { return MOD; }
    ModInt(int y=0) { if (y<0 || MOD<=y) y %= MOD; if (y<0) y += MOD; x=y; }
    ModInt(long long y) { if (y<0 || MOD<=y) y %= MOD; if (y<0) y += MOD; x=y; }
    ModInt &operator+=(ModInt y) { if((x += y.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(ModInt y) { if((x += MOD - y.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(ModInt y) { x = (unsigned long long)x * y.x % MOD; return *this; }
    ModInt operator+(ModInt y) const { return ModInt(*this) += y; }
    ModInt operator-(ModInt y) const { return ModInt(*this) -= y; }
    ModInt operator*(ModInt y) const { return ModInt(*this) *= y; }
    ModInt operator-() const { return (x > 0u? MOD-(int)x: 0); }
    bool operator<(ModInt y) const { return x < y.x; }
    bool operator==(ModInt y) const { return x == y.x; }
    bool operator!=(ModInt y) const { return x != y.x; }
    ModInt inv() const {
	int a = x, b = MOD, u = 1, v = 0;
	while(b) {
	    int t = a / b;
	    a -= t * b; swap(a, b);
	    u -= t * v; swap(u, v);
	}
	if(u < 0) u += MOD;
	return ModInt(u);
    }
    ModInt pow(long long y) const {
	ModInt x = *this;
	if (y < 0) { x = x.inv(); y = -y; }
	ModInt r = 1;
	for (; y; y>>=1) {
	    if (y&1) r *= x;
	    x *= x;
	}
	return r;
    }
};
typedef ModInt<(int)(1e9+7)> Mint;
Mint cur[511][511], nxt[511][511];

int N, M, L;
char S[511][511];

const int dy[] = { 0, 1, 0, -1 };
const int dx[] = { 1, 0, -1, 0 };

inline bool in(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

int main() {
    scanf("%d%d", &N, &M);
    // N = 500;
    // M = 500;
    // REP (i, N) REP (j, M) S[i][j] = 'a';
    REP (i, N) scanf("%s", S[i]);
    

    L = N+M-1;
    if (S[0][0] == S[N-1][M-1]) cur[0][N-1] = 1;

    for (int len=1; len<(L+1)/2; len++) {
	REP (i, min(len, N)) for (int j=i; j<N; j++) if (cur[i][j].x) {
	    ;		
	    int ix = len - i - 1;
	    int jx = M - (len - N+1+j);
	    
	    if (ix < 0 || M <= ix || jx < 0|| M <= jx) continue;

	    REP (t, 2) {
		int ni = i + dy[t];
		int nix = ix + dx[t];
		if (!in(ni, nix)) continue;
		REP (k, 2) {
		    int nj = j + dy[k+2];
		    int njx = jx + dx[k+2];
		    if (!in(nj, njx)) continue;
		    if (S[ni][nix] == S[nj][njx]) nxt[ni][nj] += cur[i][j];
		}
	    }
	}
	swap(nxt, cur);
	memset(nxt, 0, sizeof nxt);
    }

    Mint ans = 0;
    if (L % 2 == 0) {
	REP (i, N) ans += cur[i][i];
	REP (i, N-1) ans += cur[i][i+1];
    } else {
	REP (i, N) ans += cur[i][i];
    }
    printf("%d\n", ans.get<int>());
    
    return 0;
}