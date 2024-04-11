#include<map>
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
template<class T>
struct Fenwick : vector<T> {
    typedef vector<T> S;
    int N;
    Fenwick(int N_=0): S(N_, 1), N(N_) {}
    void add(int i, T x) {
	for (; i<N; i|=i+1) S::operator[](i) *= x;
    }
    T sum(int r) {
	T s = 1;
	for (; r; r&=r-1) s *= S::operator[](r-1);
	return s;
    }
    // T sum(int l, int r) {
    // 	if (l==0) {
    // 	    T s = 1;
    // 	    for (; r; r&=r-1) s *= S::operator[](r-1);
    // 	    return s;
    // 	} else {
    // 	    return sum(0, r) - sum(0, l);
    // 	}
    // }
};
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


// const LL MOD = 1000000007;
const int MAX = 1000100;
LL inv[MAX+1], fact[MAX+1], fact_inv[MAX+1];

void init() {
    inv[1] = 1;
    for (int i=2; i<=MAX; i++) inv[i] = inv[MOD%i] * (MOD-MOD/i) % MOD;

    fact[0] = fact_inv[0] = 1;
    for (int i=1; i<=MAX; i++) {
	fact[i] = fact[i-1] * i % MOD;
	fact_inv[i] = fact_inv[i-1] * inv[i] % MOD;
    }
}

// const int MAX = 10000000;
int min_factor[MAX+1];
vector<int>prime;
void make_prime() {
    for (int i=2; i<=MAX; i+=2) min_factor[i] = 2;
    for (int i=3; i<=MAX; i+=3) if (!min_factor[i]) min_factor[i] = 3;
    for (int i=5, d=2; i*i<=MAX; ) {
	if (!min_factor[i]) {
	    min_factor[i] = i;
	    for (int j=i*i; j<=MAX; j+=i)
		if (!min_factor[j]) min_factor[j] = i;
	}
	i += d; d = 6 - d;
    }
    for (int i=2; i<=MAX; i++) {
	if (min_factor[i]==0) min_factor[i] = i;
	if (min_factor[i]==i) prime.push_back(i);
    }
}


// map<LL, int> prime_factor(LL n) {
//     map<LL, int>r;
//     for (int i=0; (LL)prime[i]*prime[i]<=n; i++) {
// 	int cnt = 0;
// 	while (n%prime[i] == 0) n/=prime[i], cnt++;
// 	if (cnt) r[prime[i]] = cnt;
//     }
//     if (n>1) r[n] = 1;
//     return r;
// }

map<LL, int> fast_prime_factor(int n) { // n<=MAX
    map<LL, int>r;
    while (n > 1) {
	int t = min_factor[n], cnt = 0;
	while (n%t == 0) { n /= t, cnt++; }
	r[t] = cnt;
    }
    return r;
}

int N;
int A[200111];
int Q;

struct Data {
    int l, r, i;
    bool operator<(const Data &y) const {
	return r < y.r;
    }
} D[200111];

int last[MAX];
int ans[200111];


int main() {
    init();
    make_prime();
    
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    scanf("%d", &Q);
    REP (i, Q) {
	scanf("%d%d", &D[i].l, &D[i].r);
	D[i].l--;
	D[i].i = i;
    }

    REP (i, MAX) last[i] = N;
    
    sort(D, D+Q);
    Fenwick<Mint> F(N+10);

    for (int i=0, j=0; i<Q; i++) {

	while (j < D[i].r) {
	    map<LL, int> g = fast_prime_factor(A[j]);
	    EACH (e, g) {
		int pr = e->first;
		int pos = last[pr];

		F.add(pos, Mint(inv[pr - 1]) * pr);
		F.add(j, Mint(pr - 1) * Mint(pr).pow(e->second - 1));

		last[pr] = j;
	    }
	    j++;
	}

	Mint l = F.sum(D[i].l), r = F.sum(D[i].r);
	r *= l.inv();
	ans[D[i].i] = r.getInt();
    }

    REP (i, Q) printf("%d\n", ans[i]);
    return 0;
}