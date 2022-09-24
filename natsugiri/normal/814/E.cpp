#include<tuple>
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

int N;
int D[55];

typedef tuple<int, int, int, int, Mint> Tuple;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", D+i);

    vector<Tuple> cur, nxt;
    int start;
    if (D[0] == 2) {
	start = 1;
	cur.push_back(Tuple(0, 1, 0, 0, 1));
    } else {
	start = 2;
	if (D[1] == 2) {
	    cur.push_back(Tuple(0, 1, 1, 0, 1));
	} else {
	    cur.push_back(Tuple(0, 1, 0, 1, 1));
	}
    }

    for (int i=start; i<N; i++) {
	nxt.clear();
	EACH (e, cur) {
	    int a1, a2, b1, b2;
	    Mint c;
	    tie(a1, a2, b1, b2, c) = *e;

	    if (D[i] == 2) {
		if (a1) nxt.emplace_back(a1-1, a2, b1+1, b2, c * a1);
		if (a2) nxt.emplace_back(a1+1, a2-1, b1+1, b2, c * a2);
		if (a1 && b1) nxt.emplace_back(a1-1, a2, b1-1, b2, c * a1 * b1);
		if (a1 && b2) nxt.emplace_back(a1-1, a2, b1+1, b2-1, c * a1 * b2);
		if (a2 && b1) nxt.emplace_back(a1+1, a2-1, b1-1, b2, c * a2 * b1);
		if (a2 && b2) nxt.emplace_back(a1+1, a2-1, b1+1, b2-1, c * a2 * b2);
	    } else {
		if (a1) nxt.emplace_back(a1-1, a2, b1, b2+1, c * a1);
		if (a2) nxt.emplace_back(a1+1, a2-1, b1, b2+1, c * a2);
		if (a1 && b1) nxt.emplace_back(a1-1, a2, b1, b2, c * a1 * b1);
		if (a1 && b2) nxt.emplace_back(a1-1, a2, b1+2, b2-1, c * a1 * b2);
		if (a2 && b1) nxt.emplace_back(a1+1, a2-1, b1, b2, c * a2 * b1);
		if (a2 && b2) nxt.emplace_back(a1+1, a2-1, b1+2, b2-1, c * a2 * b2);

		if (a1 && b1 >= 2) nxt.emplace_back(a1-1, a2, b1-2, b2, c * a1 * (b1*(b1-1)/2));
		if (a1 && b1 && b2) nxt.emplace_back(a1-1, a2, b1, b2-1, c * a1 * b1 * b2);
		if (a1 && b2 >= 2) nxt.emplace_back(a1-1, a2, b1+2, b2-2, c * a1 * (b2*(b2-1)/2));

		if (a2 && b1 >= 2) nxt.emplace_back(a1+1, a2-1, b1-2, b2, c * a2 * (b1*(b1-1)/2));
		if (a2 && b1 && b2) nxt.emplace_back(a1+1, a2-1, b1, b2-1, c * a2 * b1 * b2);
		if (a2 && b2 >= 2) nxt.emplace_back(a1+1, a2-1, b1+2, b2-2, c * a2 * (b2*(b2-1)/2));
	    }
	}

	EACH (e, nxt) {
	    int a1, a2, b1, b2;
	    Mint c;
	    tie(a1, a2, b1, b2, c) = *e;
	    if (a1 == 0 && a2 == 0) {
		*e = Tuple(b1, b2, 0, 0, c);
	    }
	}
	sort(nxt.begin(), nxt.end());
	for (int j=0; j<(int)nxt.size();) {
	    int a1, a2, b1, b2;
	    Mint c;
	    tie(a1, a2, b1, b2, c) = nxt[j];
	    int k = j+1;
	    while (k < (int)nxt.size()) {
		int x1, x2, y1, y2;
		Mint z;
		tie(x1, x2, y1, y2, z) = nxt[k];
		if (a1 == x1 && a2 == x2 && b1 == y1 && b2 == y2) {
		    get<4>(nxt[j]) += z;
		    nxt[k] = Tuple(-1, -1, -1, -1, 0);
		    k++;
		} else {
		    break;
		}
	    }
	    j = k;
	}

	nxt.erase(remove(nxt.begin(), nxt.end(), Tuple(-1, -1, -1, -1, 0)), nxt.end());
	swap(cur, nxt);
    }

    Mint ans = 0;
    EACH (e, cur) {
	int a1, a2, b1, b2;
	Mint c;
	tie(a1, a2, b1, b2, c) = *e;
	if (a1 == 0 && a2 == 0 && b1 == 0 && a2 == 0) ans += c;
    }

    printf("%d\n", ans.geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}