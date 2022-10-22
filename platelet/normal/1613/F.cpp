#include <bits/stdc++.h>
#include <immintrin.h>
#pragma GCC target("avx2")
#pragma GCC optimization("Ofast")
#pragma GCC optimization("unroll-loops")

#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

const int N = 2.5e5 + 5;
const uint M = 998244353, iM = 288737297;

int n, d[N], c[N], lim = 1, rev[1 << 18];
uint fac[N], ifac[N];
__m256i a[1 << 15], w[1 << 15], iw[1 << 15], b[1 << 15];

const auto A = (uint*)a, W = (uint*)w, iW = (uint*)iw, B = (uint*)b;

uint Pow(uint a, int n, uint r = 1) {
    for(; n; n >>= 1, a = (ull)a * a % M)
    if(n & 1) r = (ull)r * a % M;
    return r;
}
void NTT(__m256i a[], int t) {
    const auto _M = _mm256_set1_epi32(M);
    const auto _iM = _mm256_set1_epi32(iM);
    auto A = (uint*)a;
    for(int i = 0; i < lim; i++) if(rev[i] < i) swap(A[i], A[rev[i]]);
    uint x, y;
    for(int j = 0; j < lim; j += 2) {
        x = A[j + 0], y = (ull)A[j + 1] * W[1] % M;
        A[j + 0] = min(x + y, x + y - M);
        A[j + 1] = min(x - y, x - y + M);
        
    }
    
    for(int j = 0; j < lim; j += 4) {
        x = A[j + 0], y = (ull)A[j + 2] * W[2] % M;
        A[j + 0] = min(x + y, x + y - M);
        A[j + 2] = min(x - y, x - y + M);
        
        x = A[j + 1], y = (ull)A[j + 3] * W[3] % M;
        A[j + 1] = min(x + y, x + y - M);
        A[j + 3] = min(x - y, x - y + M);
        
    }
    
    for(int j = 0; j < lim; j += 8) {
        x = A[j + 0], y = (ull)A[j + 4] * W[4] % M;
        A[j + 0] = min(x + y, x + y - M);
        A[j + 4] = min(x - y, x - y + M);
        
        x = A[j + 1], y = (ull)A[j + 5] * W[5] % M;
        A[j + 1] = min(x + y, x + y - M);
        A[j + 5] = min(x - y, x - y + M);
        
        x = A[j + 2], y = (ull)A[j + 6] * W[6] % M;
        A[j + 2] = min(x + y, x + y - M);
        A[j + 6] = min(x - y, x - y + M);
        
        x = A[j + 3], y = (ull)A[j + 7] * W[7] % M;
        A[j + 3] = min(x + y, x + y - M);
        A[j + 7] = min(x - y, x - y + M);
        
    }
    
    lim >>= 3;
    for(int i = 1; i < lim; i <<= 1)
        for(int j = 0; j < lim; j += i << 1)
            for(int k1 = j, k2; k1 < j + i; k1++) {
                k2 = k1 + i;
                __m256i &x = a[k1], y = a[k2];
                const __m256i& z = iw[i + k1 - j];
                #define Min _mm256_min_epu32
                #define Add _mm256_add_epi32
                #define Sub _mm256_sub_epi32
                #define Flip(x) _mm256_shuffle_epi32(x, 0xb1)
                #define Mullo _mm256_mullo_epi32
                #define Mulhi64(a, b) _mm256_srli_epi64(_mm256_mul_epu32(a, b), 32)
                #define Mulhi(a, b) _mm256_blend_epi32(Mulhi64(a, b), Flip(Mulhi64(Flip(a), Flip(b))), 0xaa)
                y = Sub(Mullo(y, w[i + k1 - j]), Mullo(Mulhi(y, z), _M));
                y = Min(y, Add(y, _M));
                a[k2] = Sub(x, y), a[k2] = Min(a[k2], Add(a[k2], _M));
                x = Add(x, y), x = Min(x, Sub(x, _M));
            }
    lim <<= 3;
    if(!t) return;
    reverse(A + 1, A + lim);
    ull inv = Pow(lim, M - 2);
    For(i, 0, lim) A[i] = A[i] * inv % M;
}

int main() {
    cin >> n;
	rep(i, 0, n) fac[i] = i ? (ull)fac[i - 1] * i % M : 1;
	per(i, n + 1, 1) ifac[i - 1] = i > n ? Pow(fac[n], M - 2) : (ull)ifac[i] * i % M;
    int u, v;
    rep(i, 2, n) d[i]--, scanf("%d%d", &u, &v), d[u]++, d[v]++;
	rep(i, 1, n) c[d[i]]++;
	A[0] = 1;
	int m = 0;
	per(k, n, 1) if(c[k]) {
		m += c[k];
		if(lim <= max(m, 7)) {
            if(lim > 1) NTT(a, 1);
            while(lim <= max(m, 7)) lim <<= 1;
            for(int i = 1; i < lim; i <<= 1) {
                ull wn = Pow(3, M / 2 / i);
                For(j, 0, i) W[i + j] = j ? W[i + j - 1] * wn % M : 1;
            }
            For(i, 0, lim) {
                rev[i] = rev[i >> 1] >> 1 | (i & 1 ? lim >> 1 : 0);
                iW[i] = (ull)W[i] * iM + 67108863 >> 26;
            }
            NTT(a, 0);
		}
        ull p = 1;
        rep(i, 0, c[k]) B[i] = p * fac[c[k]] % M * ifac[i] % M * ifac[c[k] - i] % M, p = p * k % M;
        For(i, c[k] + 1, lim) B[i] = 0;
        NTT(b, 0);
        For(i, 0, lim) A[i] = (ull)A[i] * B[i] % M;
	}
    NTT(a, 1);
    ll ans = 0;
    rep(i, 0, n) (ans += (i & 1 ? -1 : 1) * (ll)A[i] * (ll)fac[n - i]) %= M;
    cout << (ans + M) % M;
}