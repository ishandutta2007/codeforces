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

template<class Mint, int SIZE> struct MintArrBase {
    Mint d[SIZE];

    MintArrBase() { clear(); }
    MintArrBase(const MintArrBase &y) { memcpy(d, y.d, sizeof d); }
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
    MintMatBase(const MintMatBase &y) { memcpy(d, y.d, sizeof d); }
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

const int BLOCK = 1<<9;
const int SIZE = BLOCK+1;
const int ROW = SIZE;
const int COL = SIZE;

typedef MintArrBase<Mint, COL> Arr;
typedef MintMatBase<Mint, ROW, COL> Mat;

struct MintGaussianElimination {
    // R * A == D;
    // R : Elementary matrices from left;
    // D : Upper triangle;
    struct Elem {
	char op;
	int dst, src;
	Mint coeff;
	Elem(){}
	Elem(char op_, int dst_, int src_, Mint coeff_) {
	    op = op_;
	    dst = dst_;
	    src = src_;
	    coeff = coeff_;
	}
    };

    Mat D;
    vector<Elem> R;
    int row, col;

    MintGaussianElimination() {}

    MintGaussianElimination(const Mat &A) : D(A) {
	row = 0, col = 0;
	while (col<COL) {
	    int p = -1;
	    for (int i=row; i<ROW; i++) if (D[i][col] != Mint(0)) {
		p = i;
		break;
	    }
	    if (p == -1) { col++; continue; }
	    if (p != row) {
		R.emplace_back('S', row, p, 0);
		for (int j=0; j<COL; j++) swap(D[row][j], D[p][j]);
	    }
	    if (D[row][col] != Mint(1)) {
		Mint coeff = D[row][col].inv();
		R.emplace_back('M', row, -1, coeff);
		for (int j=col; j<COL; j++) D[row][j] *= coeff;
	    }
	    for (int i=0; i<ROW; i++) if (i != row && D[i][col] != Mint(0)) {
		Mint coeff = -D[i][col];
		R.emplace_back('A', i, row, coeff);
		for (int j=col; j<COL; j++) D.add(i, j, D[row][j] * coeff);
	    }
	    row++; col++;
	}
    }

    // find an Arr x on A * x == b;
    // ret : is there a solution?
    bool solve(const MintArrBase<Mint, ROW> &b, Arr &x) const {
	// Dx == Rb == y;
	MintArrBase<Mint, ROW> y(b);
	for (int i=0; i<(int)R.size(); i++) {
	    if (R[i].op == 'S') {
		Mint tmp = y[R[i].src];
		y[R[i].src] = y[R[i].dst];
		y[R[i].dst] = tmp;
	    } else if (R[i].op == 'M') {
		y[R[i].dst] *= R[i].coeff;
	    } else if (R[i].op == 'A') {
		y[R[i].dst] += y[R[i].src] * R[i].coeff;
	    } else {
		assert(false && "Unknown op");
	    }
	}
	x = Arr();
	for (int i=ROW-1; i>=0; i--) {
	    if (y[i] != Mint(0)) {
		int c = -1;
		for (int j=i; j<COL; j++) if (D[i][j] != Mint(0)) {
		    c = j;
		    break;
		}
		if (c < 0) return false;
		x[c] = y[i] / D[i][c];
	    }
	}
	return true;
    }
};

template<class T> void sort_unique(vector<T> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

int N, M;
VI G[100011];
VI H[100011];
int nim[100011];
int deg[100011];

int C[100011];
// prob: C[i] / N
// nim ^= i;
Mat mat;


void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[y].push_back(x);
	deg[x]++;
    }

    VI que;
    REP (i, N) if (deg[i] == 0) que.push_back(i);

    REP (i, N) {
	int v = que[i];

	sort_unique(H[v]);
	H[v].push_back(-1);
	nim[v] = 0;
	REP (j, H[v].size()) if (H[v][j] != j) {
	    nim[v] = j;
	    C[j]++;
	    break;
	}

	EACH (e, G[v]) {
	    H[*e].push_back(nim[v]);
	    deg[*e]--;
	    if (deg[*e] == 0) {
		que.push_back(*e);
	    }
	}
    }

    const Mint INV = Mint(1) / (N+1);

    REP (i, BLOCK) if (C[i]) {
	REP (x, BLOCK) {
	    assert((x^i) < BLOCK);
	    mat.add(x^i, x, -C[i] * INV);
	}
    }

    mat.add(BLOCK, 0, -INV);
    REP (i, SIZE) mat.add(i, i, 1);

    MintGaussianElimination GE(mat);

    Arr arr, x;
    arr.add(0, 1);
    bool b = GE.solve(arr, x);

    Mint ans = 1-x.get(BLOCK);
    printf("%d\n", ans.geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}