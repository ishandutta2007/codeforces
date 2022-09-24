#include<bitset>
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

// NEVER USE moved rvalue; Re-assign it;
template<int SIZE> struct MatBase {
    typedef bitset<SIZE> Arr;

    Arr *d;
    MatBase() : d(new Arr[SIZE]()) {}
    MatBase(const MatBase &y) : d(new Arr[SIZE]()) { for (int i=0; i<SIZE; i++) d[i]=y.d[i]; }
    MatBase(MatBase &&y) : d(nullptr) { swap(*this, y); }
    ~MatBase() { if (d) { delete[] d; d = nullptr; } }
    friend void swap(MatBase &x, MatBase &y) { swap(x.d, y.d); }
    MatBase& operator=(MatBase y) { swap(*this, y); return *this; }


    const Arr& operator[](int r) const { return d[r]; }
    Arr& operator[](int r) { return d[r]; }
    const Arr get(int r) const { return d[r]; }
    bool get(int r, int c) const { return d[r][c]; }
    typename Arr::reference get(int r, int c) { return d[r][c]; }
    const Arr* pointer(int r) const { return d + r; }

    MatBase& operator|=(const MatBase &y) { for (int i=0; i<SIZE; i++) d[i] |= y.d[i]; return *this; }
    MatBase& operator&=(const MatBase &y) { for (int i=0; i<SIZE; i++) d[i] &= y.d[i]; return *this; }
    MatBase& operator*=(const MatBase &y) { return *this = *this * y; }

    MatBase operator|(const MatBase &y) const { return move(MatBase(*this) |= y); }
    MatBase operator&(const MatBase &y) const { return move(MatBase(*this) &= y); }
    MatBase operator*(const MatBase &y) const {
	MatBase r;
	static MatBase t;
	for (int i=0; i<SIZE; i++) for (int j=0; j<SIZE; j++) t[j][i] = y[i][j];
	for (int i=0; i<SIZE; i++) for (int j=0; j<SIZE; j++)
	    if ((d[i] & t[j]).any()) r.d[i].set(j);

//	for (int i=0; i<SIZE; i++) for (int k=0; k<SIZE; k++)
//	    if (d[i][k]) r.d[i] |= y.d[k];
	return move(r);
    }

    Arr operator*(const Arr &y) const {
	Arr r;
	for (int i=0; i<SIZE; i++) if ((d[i] & y).any()) r[i] = true;
	return move(r);
    }

    MatBase pow(unsigned long long y) const {
	MatBase x(*this), r = I();
	for (; y; y>>=1) {
	    if (y&1) r *= x;
	    x *= x;
	}
	return move(r);
    }

    Arr powmul(unsigned long long y, Arr z) const {
	MatBase x(*this);
	for (; y; y>>=1) {
	    if (y&1) z = x * z;
	    x *= x;
	}
	return move(z);
    }

    static MatBase I() {
	static MatBase I_;
	if (!I_[0][0]) for (int i=0; i<SIZE; i++) I_[i][i] = true;
	return I_;
    }
};

// Multiple of 64 for SIZE is recommended.
const int SIZE = 512;

typedef bitset<SIZE> Arr;
typedef MatBase<SIZE> Mat;

// reversed string
string to_arrstr(const Arr &x) {
    string s = x.to_string();
    reverse(s.begin(), s.end());
    return s;
}

int N, M;

const int LIMIT = 64;
Mat X[LIMIT], Y[LIMIT];
Arr cur, nxt;

int main() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int x, y, c;
	scanf("%d%d%d", &x, &y, &c);
	x--; y--;
	if (c == 0) {
	    X[0][y][x] = true;
	} else {
	    Y[0][y][x] = true;
	}
    }

    REP (i, LIMIT-1) {
	X[i+1] = Y[i] * X[i];
	Y[i+1] = X[i] * Y[i];
    }

    cur[0] = true;
    bool flip = false;
    unsigned long long ans = 0;

    for (int i=LIMIT; i--; ) {
	nxt = (flip ? Y[i] : X[i]) * cur;
	if (nxt.any()) {
	    ans |= 1LLU << i;
	    cur = nxt;
	    flip = !flip;
	}
    }

    const unsigned long long INF = 1e18;
    if (ans > INF) puts("-1");
    else printf("%llu\n", ans);

    return 0;
}