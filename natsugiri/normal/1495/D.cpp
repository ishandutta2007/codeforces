#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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

template<unsigned MOD_> struct ModInt {
    static constexpr unsigned MOD = MOD_;
    unsigned x;
    void undef() { x = (unsigned)-1; }
    bool isnan() const { return x == (unsigned)-1; }
    inline int geti() const { return (int)x; }
    ModInt() { x = 0; }
    ModInt(int y) { if (y<0 || (int)MOD<=y) y %= (int)MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned y) { if (MOD<=y) x = y % MOD; else x = y; }
    ModInt(long long y) { if (y<0 || MOD<=y) y %= MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned long long y) { if (MOD<=y) x = y % MOD; else x = y; }
    ModInt &operator+=(const ModInt y) { if ((x += y.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(const ModInt y) { if ((x -= y.x) & (1u<<31)) x += MOD; return *this; }
    ModInt &operator*=(const ModInt y) { x = (unsigned long long)x * y.x % MOD; return *this; }
    ModInt &operator/=(const ModInt y) { x = (unsigned long long)x * y.inv().x % MOD; return *this; }
    ModInt operator-() const { return (x ? MOD-x: 0); }

    ModInt inv() const { return pow(MOD-2); }
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

constexpr LL MOD = 998244353;
using Mint = ModInt<MOD>;

int N;
int M;
VI G[411];


VI que;
void bfs(int s, int *d) {
    REP (i, N) d[i] = 1<<29;
    d[s] = 0;
    que.clear();
    que.push_back(s);
    REP (i, N) {
	int v = que[i];
	EACH (e, G[v]) {
	    if (d[*e] > d[v] + 1) {
		d[*e] = d[v] + 1;
		que.push_back(*e);
	    }
	}
    }
}

int D[411][411];
int A[411][411];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--;
	y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    REP (i, N) {
	bfs(i, D[i]);
    }

    VI X;

    REP (i, N) {

	Mint tmp = 1;
	REP (v, N) {
	    if (v == i) continue;
	    int cnt = 0;
	    EACH (e, G[v]) if (D[i][*e] + 1 == D[i][v]) {
		cnt++;
	    }
	    tmp *= cnt;
	}
	A[i][i] = tmp.geti();


	REP (j, i) {
	    bool yes = true;

	    int parity = D[i][j] & 1;
	    REP (k, N) {
		int test = (D[i][k]^D[j][k])&1;
		if (parity != test) {
		    yes = false;
		    break;
		}
	    }

	    // cycle;
	    if (yes) {
		X.clear();
		REP (k, N) {
		    if (D[i][k] + D[j][k] == D[i][j]) {
			X.push_back(D[i][k]);
		    }
		}
		sort(X.begin(), X.end());

		REP (k, (int)X.size()-1) {
		    if (X[k] == X[k+1]) {
			yes = false;
			break;
		    }
		}
	    }

	    if (yes) {

		tmp = 1;

		REP (v, N) {
		    if (D[i][v] + D[j][v] == D[i][j]) continue;

		    int cnt = 0;
		    EACH (e, G[v]) {
			if (D[i][*e] + 1 == D[i][v] && D[j][*e] + 1 == D[j][v]) {
			    cnt++;
			}

		    }
		    tmp *= cnt;
		    if (cnt == 0) break;
		}

		A[i][j] = A[j][i] = tmp.geti();
	    }
	}
    }

    REP (i, N) rprintf("%d", A[i], A[i] + N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}