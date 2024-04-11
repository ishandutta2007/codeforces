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

template<class Mint, int SIZE> struct MintArrBase {
    Mint d[SIZE];

    MintArrBase() { clear(); }
    void clear() { memset(d, 0, sizeof d); }

    Mint& operator[](int i) { return d[i]; }
    const Mint& operator[](int i) const { return d[i]; }
    Mint& get(int i) { return d[i]; }
    const Mint& get(int i) const { return d[i]; }
    void set(int i, const Mint &v) { d[i] = v; }
    void add(int i, const Mint &v) { d[i] += v; }

    MintArrBase& operator+=(const MintArrBase &y) {
	for (int i=0; i<SIZE; i++) d[i] += y.d[i];
	return *this;
    }
    MintArrBase& operator-=(const MintArrBase &y) {
	for (int i=0; i<SIZE; i++) d[i] -= y.d[i];
	return *this;
    }
    MintArrBase operator+(const MintArrBase &y) const { return MintArrBase(*this) += y; }
    MintArrBase operator-(const MintArrBase &y) const { return MintArrBase(*this) -= y; }

    bool operator==(const MintArrBase &y) const {
	for (int i=0; i<SIZE; i++) if (d[i] != y.d[i]) return false;
	return true;
    }
    bool operator!=(const MintArrBase &y) const { return !(*this == y); }

    friend string to_string(const MintArrBase &x) {
	string s;
	char buf[21];
	for (int i=0; i<SIZE; i++) {
	    sprintf(buf, "%d", x[i].geti());
	    s += buf;
	    if (i < SIZE-1) s += " ";
	}
	return s;
    }
};

template<class Mint, int ROW, int COL> struct MintMatBase {
    static const int SIZE = ROW * COL;
    typedef unsigned long long ULL;
    Mint d[SIZE];

    MintMatBase() { clear(); }
    void clear() { memset(d, 0, sizeof d); }

    Mint* operator[](int r) { return d+r*COL; }
    const Mint* operator[](int r) const { return d+r*COL; }
    Mint& get(int r, int c) { return d[r*COL+c]; }
    const Mint& get(int r, int c) const { return d[r*COL+c]; }
    void set(int r, int c, const Mint &v) { d[r*COL+c] = v; }
    void add(int r, int c, const Mint &v) { d[r*COL+c] += v; }

    MintMatBase& operator+=(const MintMatBase &y) {
	for (int i=0; i<SIZE; i++) d[i] += y.d[i];
	return *this;
    }
    MintMatBase& operator-=(const MintMatBase &y) {
	for (int i=0; i<SIZE; i++) d[i] -= y.d[i];
	return *this;
    }
    template<int COL2> MintMatBase<Mint, ROW, COL2>& operator*=(const MintMatBase<Mint, COL, COL2> &y) { return *this = *this * y; }
    MintMatBase operator+(const MintMatBase &y) const { return MintMatBase(*this) += y; }
    MintMatBase operator-(const MintMatBase &y) const { return MintMatBase(*this) -= y; }
    template<int COL2> MintMatBase<Mint, ROW, COL2> operator*(const MintMatBase<Mint, COL, COL2> &y) const {
	static MintMatBase r;
	static ULL buf[COL2];
	for (int i=0; i<ROW; i++) {
	    memset(buf, 0, sizeof buf);
	    int k = 0; 
	    for (; k<=COL-16; k+=16) {
		for (int k_=k; k_<k+16; k_++)
		    for (int j=0; j<COL2; j++)
			buf[j] += (ULL)d[i*COL+k_].x * y.d[k_*COL2+j].x;
		for (int j=0; j<COL2; j++) buf[j] %= (ULL)Mint::MOD;
	    }
	    for (; k<COL; k++)
		for (int j=0; j<COL2; j++)
		    buf[j] += (ULL)d[i*COL+k].x * y.d[k*COL2+j].x;
	    for (int j=0; j<COL2; j++) r.d[i*COL2+j] = Mint(buf[j]);
	}
	return r;
    }
    MintArrBase<Mint, ROW> operator*(const MintArrBase<Mint, COL> &y) const {
	static MintArrBase<Mint, ROW> r;
	for (int i=0; i<ROW; i++) {
	    ULL buf = 0;
	    int j = 0;
	    for (; j<=COL-16; j+=16) {
		for (int j_=j; j_<j+16; j_++) buf += (ULL)d[i*COL+j_].x * y.d[j_].x;
		buf %= Mint::MOD;
	    }
	    for (; j<COL; j++) buf += (ULL)d[i*COL+j].x * y.d[j].x;
	    r.d[i] = Mint(buf);
	}
	return r;
    }
    MintMatBase pow(unsigned long long y) const {
	static MintMatBase x, r;
	x = *this; r = I();
	for (; y; y>>=1) {
	    if (y&1) r = r * x;
	    x = x * x;
	}
	return r;
    }
    MintArrBase<Mint, ROW> powmul(unsigned long long y, MintArrBase<Mint, ROW> z) const {
	static_assert(ROW == COL, "");
	static MintMatBase x;
	x = *this;
	for (; y; y>>=1) {
	    if (y&1) z = x * z;
	    x = x * x;
	}
	return z;
    }

    bool operator==(const MintMatBase &y) const {
	for (int i=0; i<SIZE; i++) if (d[i] != y.d[i]) return false;
	return true;
    }
    bool operator!=(const MintMatBase &y) const { return !(*this == y); }

    static const MintMatBase I() {
	static MintMatBase I_ = MintMatBase();
	if (I_.d[0] == 0)
	    for (int i=0; i<min(ROW, COL); i++) I_.set(i, i, 1);
	return I_;
    }

    friend string to_string(const MintMatBase &x) {
	string s;
	char buf[21];
	for (int i=0; i<ROW; i++) {
	    for (int j=0; j<COL; j++) {
		sprintf(buf, "%d", x.get(i, j).geti());
		s += buf;
		s += " \n"[j==COL-1];
	    }
	}
	return s;
    }
    friend MintArrBase<Mint, COL> operator*(const MintArrBase<Mint, ROW> &x, const MintMatBase<Mint, ROW, COL> &y) {
	static MintArrBase<Mint, COL> r;
	static ULL buf[COL];
	memset(buf, 0, sizeof buf);
	int k = 0; 
	for (; k<=ROW-16; k+=16) {
	    for (int k_=k; k_<k+16; k_++)
		for (int j=0; j<COL; j++)
		    buf[j] += (ULL)x.d[k_].x * y.d[k_*COL+j].x;
	    for (int j=0; j<COL; j++) buf[j] %= (ULL)Mint::MOD;
	}
	for (; k<ROW; k++)
	    for (int j=0; j<COL; j++)
		buf[j] += (ULL)x.d[k].x * y.d[k*COL+j].x;
	for (int j=0; j<COL; j++) r.d[j] = Mint(buf[j]);
	return r;
    }
};


const int SIZE = 90;
const int ROW = SIZE;
const int COL = SIZE;

typedef MintArrBase<Mint, COL> Arr;
typedef MintMatBase<Mint, ROW, COL> Mat;

int N, M;
string W[8];
char buf[11];
Mat mat;

using Tuple = tuple<int, int, int>;
vector<Tuple> X;

int id(int i, int a, int k) {
    auto it = lower_bound(X.begin(), X.end(), Tuple(i, a, k));
    assert(it != X.end());
    assert(*it == Tuple(i, a, k));
    return it - X.begin();
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) {
	scanf("%s", buf);
	W[i] = buf;
    }
    
    REP (k, 5) {
	X.emplace_back(-1, -1, k);
    }

    REP (i, N) {
	for (int a=1; a<(int)W[i].size(); a++) {
	    for (int k=0; k<a; k++) {
		X.emplace_back(i, a, k);
	    }
	}
    }
    sort(X.begin(), X.end());

    REP (i, N) {

	for (int a=0; a<(int)W[i].size(); a++) {
	    int from;
	    if (a == 0) from = 0;
	    else from = id(i, a, 0);

	    REP (j, N) {
		if (a == 0 && i < j) break;

		int s = min((int)W[j].size(), (int)W[i].size()-a);

		if (W[i].compare(a, s, W[j], 0, s) == 0) {
		    int to;
		    if (s == (int)W[j].size() && s == (int)W[i].size()-a) {
			to = id(-1, -1, s-1);
		    } else if (s == (int)W[j].size()) {
			to = id(i, a+s, s-1);
		    } else {
			to = id(j, s, s-1);
		    }

		    int ad;
		    if (a == 0 && i != j) ad = 2;
		    else ad = 1;

		    mat.add(to, from, ad);
		}
	    }
	}

//	int len = W[i].size();
//	REP (j, N) {
//	    if (W[i].size() < W[j].size()) {
//		for (int k=0; k+len <= (int)W[j].size(); k++) {
//		    if (W[i].compare(0, len, W[j], k, len) == 0) {
//			if (k == 0) {
//			    mat.add(
//				    id(j, len, len-1),
//				    0,
//				    2);
//			} else if (k+len == (int)W[j].size()) {
//			    mat.add(
//				    id(-1, -1, len-1),
//				    id(j, k, 0),
//				    1);
//			} else {
//			    mat.add(
//				    id(j, k+len, len-1),
//				    id(j, k, 0),
//				    1);
//			}
//		    }
//		}
//	    }
//	}
//
//
//	mat.add(
//		id(-1, -1, len-1),
//		0,
//		1);
    }

    REP (from, X.size()) {
	int i, a, k;
	tie(i, a, k) = X[from];
	if (k) {
	    int to = id(i, a, k-1);
	    mat.add(to, from, 1);
	}
    }

    Arr arr;
    arr.add(0, 1);
    Arr y = mat.powmul(M, arr);
    Mint ans = y.get(0);
    printf("%d\n", ans.geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}