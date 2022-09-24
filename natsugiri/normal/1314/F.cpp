#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
#include<unordered_map>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<random>

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

using ULL = unsigned long long;

namespace NIMBER {

using ULL = unsigned long long;

ULL mul_pow2_table[64][64]; // table[i][j] := mul(1<<i, 1<<j);
unsigned mul_8bit_table[256][256]; // table[x][y] := mul(x, y);

ULL build_mul(ULL x, ULL y);
ULL build_mul_pow2(int i, int j);

ULL build_mul(ULL x, ULL y) {
    ULL ret = 0;
    REP (i, 64) if (x>>i&1) {
	REP (j, 64) if (y>>j&1) {
	    ret ^= build_mul_pow2(i, j);
	}
    }
    return ret;
}

ULL build_mul_pow2(int i, int j) {
    if (mul_pow2_table[i][j]) return mul_pow2_table[i][j];
    if (i == 0) return mul_pow2_table[i][j] = 1ULL<<j;
    if (j == 0) return mul_pow2_table[i][j] = 1ULL<<i;
    int t = 32;
    while (i < t && j < t) t /= 2;
    ULL ret;
    if (t <= i && t <= j) {
	ret = build_mul(3ULL<<(t-1), build_mul_pow2(i-t, j-t));
    } else if (t <= i) {
	ret = build_mul_pow2(i-t, j) << t;
    } else {
	ret = build_mul_pow2(i, j-t) << t;
    }
    return mul_pow2_table[i][j] = ret;
}

// Automatically initilized;
void _init() {
    assert(mul_pow2_table[0][0] == 0u);

    REP (i, 64) REP (j, 64) build_mul_pow2(i, j);

    REP (x, 256) REP (i, 8) if (x>>i&1) {
        REP (y, 256) REP (j, 8) if (y>>j&1) {
            mul_8bit_table[x][y] ^= mul_pow2_table[i][j];
        }
    }
}
struct _AutoInit { _AutoInit() { _init(); } } _auto_init;

unsigned karatsuba_16(unsigned x, unsigned y) {
    unsigned x1 = x>>8;
    unsigned x0 = x & 255u;
    unsigned y1 = y>>8;
    unsigned y0 = y & 255u;
    unsigned z0 = mul_8bit_table[x0][y0];
    unsigned z1 = mul_8bit_table[x0^x1][y0^y1];
    unsigned z2 = mul_8bit_table[x1][y1];
    return z0 ^ ((z0 ^ z1) << 8) ^ mul_8bit_table[1u<<7][z2];
}

unsigned karatsuba_32(unsigned x, unsigned y) {
    unsigned x1 = x>>16;
    unsigned x0 = x & 65535u;
    unsigned y1 = y>>16;
    unsigned y0 = y & 65535u;
    unsigned z0 = karatsuba_16(x0, y0);
    unsigned z1 = karatsuba_16(x0^x1, y0^y1);
    unsigned z2 = karatsuba_16(x1, y1);
    return z0 ^ ((z0 ^ z1) << 16) ^ karatsuba_16(1u<<15, z2);
}

ULL karatsuba_64(ULL x, ULL y) {
    unsigned x1 = x>>32;
    unsigned x0 = x;
    unsigned y1 = y>>32;
    unsigned y0 = y;
    unsigned z0 = karatsuba_32(x0, y0);
    unsigned z1 = karatsuba_32(x0^x1, y0^y1);
    unsigned z2 = karatsuba_32(x1, y1);
    return z0 ^ ((ULL)(z0 ^ z1) << 32) ^ karatsuba_32(1u<<31, z2);
}

ULL slow_mul(ULL x, ULL y) {
    ULL ret = 0;
    REP (i, 64) if (x>>i&1) {
	REP (j, 64) if (y>>j&1) {
	    ret ^= mul_pow2_table[i][j];
	}
    }
    return ret;
}

ULL fast_mul(ULL x, ULL y) {
    return karatsuba_64(x, y);
}

unsigned pow_32(unsigned x, unsigned y) {
    unsigned ret = 1;
    for (; y; y>>=1) {
	if (y&1) ret = karatsuba_32(ret, x);
	x = karatsuba_32(x, x);
    }
    return ret;
}

ULL pow_64(ULL x, ULL y) {
    ULL ret = 1;
    for (; y; y>>=1) {
	if (y&1) ret = karatsuba_64(ret, x);
	x = karatsuba_64(x, x);
    }
    return ret;
}

// assert x != 0;
// mul(x, inverse(x)) == 1u;
unsigned inverse_32(unsigned x) {
    assert(x);
    return pow_32(x, -2u);
}

ULL inverse_64(ULL x) {
    assert(x);
    if (x>>32) return pow_64(x, -2ULL);
    return pow_32(x, -2u);
}

}; // namespace NIMBER;

// xs + yt = gcd(x, y), xu + yv = 0
// abs(s) < abs(y / gcd(x, y));
// abs(t) < abs(x / gcd(x, y));
LL ext_gcd(LL x, LL y, LL&s, LL&t) {
    for (LL u=t=1, v=s=0; x; ) {
	LL q = y / x;
	swap(s -= q * u, u);
	swap(t -= q * v, v);
	swap(y -= q * x, x);
    }
    return y;
}

LL inv_mod(LL a, LL mod) {
    LL x, y;
    if (ext_gcd(a, mod, x, y) == 1) return (x + mod) % mod;
    return 0; // unsolvable
}
// if mod == 0, find x >= 0 s.t. x % m[i] == a[i];
// otherwise find x % mod;
// requires m[i] * mod < 2^64; m[i] < 2^32;
// O(n^2 + n log m);
ULL garner(const vector<LL> &a, const vector<LL> &m, ULL mod=0) {
    assert(a.size() == m.size());
    vector<LL> x(a.size());
    REP (i, a.size()) {
	assert(0 <= a[i] && a[i] < m[i]);
	LL M = 1, tmp = 0;
	for (int j=i; j--;) {
	    tmp = (tmp * m[j] + x[j]) % m[i];
	    M = M * m[j] % m[i];
	}
	x[i] = (a[i] - tmp) * inv_mod(M, m[i]) % m[i];
	if (x[i] < 0) x[i] += m[i];
    }
    ULL ret = 0;
    for (int i=a.size(); i--;) {
	ret = ret * (ULL)m[i] + (ULL)x[i];
	if (mod) ret %= mod;
    }
    return ret;
}

const ULL F = ~0ULL;
const LL E[] = {
    3, 5, 17, 257, 641, 65537, 6700417,
};

ULL A[100011];
 
void MAIN() {
    using namespace NIMBER;

    ULL a, b;
    scanf("%llu%llu", &a, &b);

    bool yes = true;
    vector<LL> va, vm;

    REP (t, 7) {
	const ULL a1 = pow_64(a, F/E[t]);
	const ULL b1 = pow_64(b, F/E[t]);
	if (a1 == 1) {
	    if (b1 == 1) {
		continue;
	    } else {
		yes = false; break;
	    }
	}
	A[0] = 1;
	int len = 0;
	while (1) {
	    A[len+1] = karatsuba_64(A[len], a1);
	    len++;
	    if (len * len > E[t]) break;
	}
	unordered_map<ULL, int> as;
	REP (i, len+1) as[A[i]] = i;
	ULL d = pow_64(A[len], F-1);
	ULL b2 = b1;
	int y = -1;
	REP (i, len+1) {
	    // a^x == b * a^(-len*i);
	    auto it = as.find(b2);
	    if (it != as.end()) {
		y = (it->second + (LL)i*len) % E[t];
		break;
	    }
	    b2 = karatsuba_64(b2, d);
	}
	if (y < 0) {
	    yes = false;
	    break;
	}
	yes = true;
	vm.push_back(E[t]);
	va.push_back(y);
	//eprintf("%lld %lld\n", (LL)y, (LL)E[t]);
    }
    if (yes) {
	ULL ans = garner(va, vm);
	printf("%llu\n", ans);
    } else {
	puts("-1");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    REP (i, t) MAIN();
    return 0;
}