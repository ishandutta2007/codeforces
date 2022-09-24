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
    bool isnan() const { return x == -1; }
    inline int getInt() const { return (int)x; }
    template<class T> T get() const { return (T)x; }
    inline int mod() const { return MOD; }
    ModInt(int y=0) { if (y<0 || MOD<=y) y %= MOD; if (y<0) y += MOD; x=y; }
    ModInt(long long y) { if (y<0 || MOD<=y) y %= MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned long long y) { if (MOD<=y) x = y % MOD; else x = y; }
    ModInt &operator+=(const ModInt &y) { if ((x += y.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(const ModInt &y) { if ((x += MOD - y.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(const ModInt &y) { x = (unsigned long long)x * y.x % MOD; return *this; }
    ModInt &operator/=(const ModInt &y) { x = (unsigned long long)x * y.inv().x % MOD; return *this; }
    ModInt operator-() const { return (x ? MOD-x: 0); }
    ModInt inv() const {
	int a = MOD, b = x, u = 0, v = 1;
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
};
const LL MOD = 1000000007;
typedef ModInt<MOD> Mint;
Mint operator+(Mint x, const Mint &y) { if ((x.x += y.x) >= (unsigned)x.mod()) x.x -= x.mod(); return x; }
Mint operator-(Mint x, const Mint &y) { if ((x.x += x.mod() - y.x) >= (unsigned)x.mod()) x.x -= x.mod(); return x; }
Mint operator*(Mint x, const Mint &y) { x.x = (unsigned long long)x.x * y.x % x.mod(); return x; }
Mint operator/(Mint x, const Mint &y) { x.x = (unsigned long long)x.x * y.inv().x % x.mod(); return x; }
bool operator<(const Mint &x, const Mint &y) { return x.x < y.x; }
bool operator==(const Mint &x, const Mint &y) { return x.x == y.x; }
bool operator!=(const Mint &x, const Mint &y) { return x.x != y.x; }

template<class T>
struct Fenwick : vector<T> {
    typedef vector<T> S;
    int N;
    Fenwick(int N_=0): S(N_), N(N_) {}
    void add(int i, T x) {
	for (; i<N; i|=i+1) S::operator[](i) += x;
    }
    T sum(int l, int r) {
	if (l==0) {
	    T s = 0;
	    for (; r; r&=r-1) s += S::operator[](r-1);
	    return s;
	} else {
	    return sum(0, r) - sum(0, l);
	}
    }
};


int N, K;
LL L;
int A[1000011], As[1000011];

int main() {
    scanf("%d%lld%d", &N, &L, &K);
    REP (i, N) scanf("%d", A+i);

    REP (i, N) As[i] = A[i];
    sort(As, As+N);

    Mint ans = 0;

    if ((LL)N*K >= L) {
	Fenwick<Mint> F(N);
	REP (i, K) {
	    Fenwick<Mint> Fn(N);
	    REP (j, min<LL>(N, L)) {
		int p = upper_bound(As, As+N, A[j]) - As;
		Fn.add(p-1, F.sum(0, p)+1);
	    }
	    swap(Fn, F);
	    L -= N;
	    ans += F.sum(0, N);
	    if (L <= 0) break;
	}
    } else {
	// L % N
	if (L % N) {
	    Fenwick<Mint> F(N);
	    F.add(0, 1);
	    REP (i, K) {
		Fenwick<Mint> Fn(N);
		REP (j, L % N) {
		    int p = upper_bound(As, As+N, A[j]) - As;
		    Fn.add(p-1, F.sum(0, p));
		}
		ans += Fn.sum(0, N);

		for (int j=L%N; j<N; j++) {
		    int p = upper_bound(As, As+N, A[j]) - As;
		    Fn.add(p-1, F.sum(0, p));
		}
		swap(Fn, F);
	    }
	}

	// L/N
	{
	    Fenwick<Mint> F(N);
	    F.add(0, 1);
	    REP (i, K) {
		Fenwick<Mint> Fn(N);
		REP (j, N) {
		    int p = upper_bound(As, As+N, A[j]) - As;
		    Fn.add(p-1, F.sum(0, p));
		}
		swap(Fn, F);
		ans += F.sum(0, N) * (L/N - i);
	    }
	}
    }

    printf("%d\n", ans.getInt());
    return 0;
}