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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}
template<unsigned MOD_> struct ModInt {
    static const unsigned MOD = MOD_;
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

    ModInt extgcd() const {
	unsigned a = MOD, b = x; int u = 0, v = 1;
	while (b) {
	    int t = a / b;
	    a -= t * b; swap(a, b);
	    u -= t * v; swap(u, v);
	}
	if (u < 0) u += MOD;
	return ModInt(u);
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

int N, M;
int S[5011];
VI H[5011], L[5011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", S+i), S[i]--;
    REP (i, M) {
	int f, h;
	scanf("%d%d", &f, &h);
	f--;
	H[f].push_back(h);
    }

    REP (i, N) L[S[i]].push_back(i);

    int best_cnt = 0;
    Mint best_way = 0;
    REP (sep, N+1) {
	if (sep < N && H[S[sep]].empty()) continue;

	int cnt = 0;
	Mint way = 1;

	REP (f, N) {
	    int left = 0, right = 0, both = 0;
	    int both_just = 0, right_just = 0;
	    bool sep_val = (sep < N && S[sep] == f);

	    EACH (e, H[f]) {
		int h = *e;
		if (h <= (int)L[f].size()) {
		    bool l = false, r = false;
		    if (L[f][h-1] < sep) l = true;
		    if (sep <= L[f].rbegin()[h-1]) r = true;

		    if (l && r) {
			if (sep_val && L[f].rbegin()[h-1] == sep) both_just++;
			else both++;
		    } else if (l) {
			left++;
		    } else if (r) {
			if (sep_val && L[f].rbegin()[h-1] == sep) right_just++;
			else right++;
		    }
		}
	    }

	    if (sep_val && both_just + right_just == 0) {
		cnt = -1;
		way = 0;
		break;
	    }

	    if (sep_val) {
		right = 0;
		left += both; both = 0;

		if ((right_just >= 1 && left+both_just >= 1) ||
			(both_just >= 1 && left+both_just-1 >= 1)) {
		    cnt += 2;
		    Mint nxt = 0;

		    if (right_just >= 1 && left+both_just >= 1)
			nxt += way * right_just * (left+both_just);

		    if (both_just >= 1 && left+both_just-1 >= 1)
			nxt += way * both_just * (left+both_just-1);

		    way = nxt;
		} else {
		    assert(left == 0);
		    cnt += 1;
		    way *= right_just + both_just;
		}
	    } else {
		if (left+both >= 1 && right+both >= 1 && left+right+both >= 2) {
		    cnt += 2;
		    way = way*left*(right + both) + way*both*(right+both-1);
		} else if (left+right+both >= 1) {
		    cnt += 1;
		    way = way*left + way*right + way*both*2;
		}
	    }
	}


	if (cnt > best_cnt) {
	    best_cnt = cnt;
	    best_way = 0;
	}
	if (cnt == best_cnt) {
	    best_way += way;
	}
    }

    printf("%d %d\n", best_cnt, best_way.geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}