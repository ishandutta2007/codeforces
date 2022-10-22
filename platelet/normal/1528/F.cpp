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
using uint = unsigned int;
using ull = unsigned long long;

const int N = 1e5 + 5;

int n, K;
uint fac[N], ifac[N];

const uint M = 998244353, iM = 288737297;

int lim = 8, rev[1 << 18];
__m256i a[1 << 15], w[1 << 15], iw[1 << 15], b[1 << 15];

const auto W = (uint*)w, iW = (uint*)iw;
const auto A = (uint*)a, B = (uint*)b;

uint Pow(uint a, int n, uint r = 1) {
    if(n < 0) n += M - 1;
    for(; n; n >>= 1, a = (ull)a * a % M)
    if(n & 1) r = (ull)r * a % M;
    return r;
}
void NTT(__m256i a[], int t) {
    const auto _M = _mm256_set1_epi32(M);
    auto A = (uint*)a;
    for(int i = 0; i < lim; i++) if(rev[i] < i) swap(A[i], A[rev[i]]);
    uint tmp, x, y;
    for(int j = 0; j < lim; j += 2) {
        x = A[j + 0], tmp = y = (ull)A[j + 1] * W[1] % M;
        y = x - y, x += tmp;
        A[j + 0] = x < M ? x : x - M, A[j + 1] = y < M ? y : y + M;
    }
    for(int j = 0; j < lim; j += 4) {
        x = A[j + 0], tmp = y = (ull)A[j + 2] * W[2] % M;
        y = x - y, x += tmp;
        A[j + 0] = x < M ? x : x - M, A[j + 2] = y < M ? y : y + M;
        x = A[j + 1], tmp = y = (ull)A[j + 3] * W[3] % M;
        y = x - y, x += tmp;
        A[j + 1] = x < M ? x : x - M, A[j + 3] = y < M ? y : y + M;
    }
    for(int j = 0; j < lim; j += 8) {
        x = A[j + 0], tmp = y = (ull)A[j + 4] * W[4] % M;
        y = x - y, x += tmp;
        A[j + 0] = x < M ? x : x - M, A[j + 4] = y < M ? y : y + M;
        x = A[j + 1], tmp = y = (ull)A[j + 5] * W[5] % M;
        y = x - y, x += tmp;
        A[j + 1] = x < M ? x : x - M, A[j + 5] = y < M ? y : y + M;
        x = A[j + 2], tmp = y = (ull)A[j + 6] * W[6] % M;
        y = x - y, x += tmp;
        A[j + 2] = x < M ? x : x - M, A[j + 6] = y < M ? y : y + M;
        x = A[j + 3], tmp = y = (ull)A[j + 7] * W[7] % M;
        y = x - y, x += tmp;
        A[j + 3] = x < M ? x : x - M, A[j + 7] = y < M ? y : y + M;
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
                #define Mulhi(a, b) _mm256_blend_epi32(Flip(_mm256_mul_epu32(a, b)), _mm256_mul_epu32(Flip(a), Flip(b)), 0xaa)
                y = Sub(Mullo(y, w[i + k1 - j]), Mullo(Mulhi(y, z), _M));
                y = Min(y, Add(y, _M));
                a[k2] = Sub(x, y), a[k2] = Min(a[k2], Add(a[k2], _M));
                x = Add(x, y), x = Min(x, Sub(x, _M));
            }
    lim <<= 3;
    if(!t) return;
    reverse(A + 1, A + lim);
    ull inv = Pow(lim, M - 2);
    for(int i = 0; i < lim; i++) A[i] = A[i] * inv % M;
}

int main() {
    cin >> n >> K;
    rep(i, 0, K) fac[i] = i ? (ull)fac[i - 1] * i % M : 1;
    per(i, K + 1, 1) ifac[i - 1] = i > K ? Pow(fac[K], -1) : (ull)ifac[i] * i % M;
    rep(i, 0, K) A[i] = (ull)Pow(i, K) * ifac[i] % M, B[i] = i & 1 ? M - ifac[i] : ifac[i];
    while(lim <= K * 2) lim <<= 1;
    for(int i = 1; i < lim; i <<= 1) {
        ull wn = Pow(3, M / 2 / i);
        For(j, 0, i) W[i + j] = j ? W[i + j - 1] * wn % M : 1;
    }
    For(i, 0, lim) {
        rev[i] = rev[i >> 1] >> 1 | (i & 1 ? lim >> 1 : 0);
        iW[i] = (ull)W[i] * iM + 67108863 >> 26;
    }
    NTT(a, 0), NTT(b, 0);
    For(i, 0, lim) A[i] = (ull)A[i] * B[i] % M;
    NTT(a, 1);
    ull p = 1, ans = 0;
    rep(i, 1, K) (p *= n - i + 1) %= M, (ans += A[i] * p % M * Pow(n + 1, n - i)) %= M;
    cout << ans;
}