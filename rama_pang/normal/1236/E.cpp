#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    lint N, M; scanf("%lld %lld", &N, &M);
    unordered_map<lint, lint> L, R;
    L.reserve(N + M + M), R.reserve(N + M + M);
    for (int i = 1; i <= N; i++) {
        L[max(1ll, i - 1ll)]++;
        R[min(N, i + 1ll)]++;
    }
    for (int i = 0; i < M; i++) {
        int a; scanf("%d", &a);
        L[a + 1 + i] += L[a + i]; L[a + i] = 0;
        R[a - 1 - i] += R[a - i]; R[a - i] = 0;
    }
    lint ans = 0;
    for (auto i : R) ans += min(N, i.first + M) * i.second;
    for (auto i : L) ans -= max(0ll, i.first - M - 1) * i.second;
    ans = ((N == 1ll)? 0ll : ans);
    printf("%lld\n", ans);
}