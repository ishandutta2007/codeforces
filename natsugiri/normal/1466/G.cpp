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

constexpr LL MOD = 1000000007;
using Mint = ModInt<MOD>;
vector<int>Z_Algorithm(const string&s) {
    int n=s.size();
    vector<int>z(n);
    int l = 0, r = 0;
    for (int i=1; i<n; i++) {
	if (i > r) {
	    l = r = i;
	    while (r<n && s[r-l] == s[r]) r++;
	    z[i] = r-l; r--;
	} else {
	    int k = i-l;
	    if (z[k] < r-i+1) z[i] = z[k];
	    else {
		l = i;
		while (r<n && s[r-l] == s[r]) r++;
		z[i] = r-l; r--;
	    }
	}
    }
    return z;
}


Mint pow2[100011];
Mint powInv2[100011];
void init() {
    pow2[0] = 1;
    powInv2[0] = 1;
    powInv2[1] = Mint(1)/2;

    REP (i, 100010) {
	pow2[i+1] = pow2[i] + pow2[i];
	powInv2[i+1] = powInv2[i] * powInv2[1];
    }
}

int N, Q;
char buf[1000011];
string S, T, Ws[100011];
string RecT;
int Ks[100011];
int idx[100011];
string X, revX;

Mint sums[26][100011];

void MAIN() {
    scanf("%d%d", &N, &Q);
    scanf("%s", buf);
    S = buf;
    const int Ssize = (int)S.size();
    scanf("%s", buf);
    T = buf;

    REP (c, 26) {
	REP (i, T.size()) {
	    sums[c][i+1] += sums[c][i];
	    if (T[i] == c + 'a') {
		sums[c][i+1] += pow2[(int)T.size() - 1 - i];
	    }
	}
    }

    VI L;
    string Front = S;
    string Back = S;
    reverse(Back.begin(), Back.end());
    REP (i, N) {
	L.push_back(Front.size());
	Front.push_back(T[i]);
	Front += Front;
	Front.pop_back();
	Back.push_back(T[i]);
	Back += Back;
	Back.pop_back();
	if ((int)Front.size() > 1000000) break;
    }
    L.push_back(Front.size());

    Front.push_back('$');
    Back.push_back('$');

    REP (i, Q) {
	int K;
	scanf("%d%s", &K, buf);
	Ks[i] = K;
	Ws[i] = buf;
	idx[i] = Front.size();
	Front += Ws[i];
	string tmp = Ws[i];
	reverse(tmp.begin(), tmp.end());
	Back += tmp;
    }
    idx[Q] = Front.size();

    VI ZFront = Z_Algorithm(Front);
    VI ZBack = Z_Algorithm(Back);

    REP (q, Q) {
	const string W = Ws[q];
	const int Wsize = W.size();
	Mint ans = 0;
	REP (j, Wsize) {
	    // [0, j) [j+1, Wsize);
	    int ma = max(j, Wsize - (j+1));
	    if (L.back() < ma) {

	    } else if (j+1 < Wsize && ZFront[idx[q] + j + 1] < Wsize - (j+1)) {
		// bad;
	    } else if (j && ZBack[idx[q+1] - j] < j) {
		// bad;
	    } else {
		int level = lower_bound(L.begin(), L.end(), ma) - L.begin();
		if (level < Ks[q]) {
		    Mint tmp = sums[W[j]-'a'][Ks[q]] - sums[W[j]-'a'][level];
		    tmp *= powInv2[N-Ks[q]];
		    ans += tmp;
		}
	    }
	}

	if (Wsize <= Ssize) {
	    VI H = Z_Algorithm(W + S);
	    for (int j=0; j+Wsize <= Ssize; j++) {
		if (H[Wsize + j] >= Wsize) {
		    ans += pow2[Ks[q]];
		}
	    }
	}

	printf("%d\n", ans.geti());
    }

}

int main() {
    init();
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}