// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
int N, A[400005], S[2000005][20];
vector<map<int, int>> DP, MX;

inline int ask(int le, int ri) {
	// return 0;
    if (ri >= 3 * N || le >= 3 * N) return 1e17;
    int k = 63 - __builtin_clzll(ri - le + 1);
    return max(S[le][k], S[ri - (1 << k) + 1][k]);
}

int solve(int n, int mx) {
    if (n >= 3 * N) return 1e17;
    if (A[n] + A[n] < mx) return n;
    if (DP[n].find(mx) != DP[n].end()) return DP[n][mx];
    auto k = DP[n].upper_bound(mx);
    if (k != DP[n].end()) {
        // cout << (*k).se << "this\n";
        int res = solve((*k).se, max(mx, ask(n, (*k).se)));
        DP[n].erase(DP[n].upper_bound(mx));
        return DP[n][mx] = res;
    }
    return DP[n][mx] = solve(n + 1, max(mx, A[n + 1]));

}

int32_t main() {
    cin >> N;
    DP.resize(5 * N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i + N + N + N] = A[i + N + N] = A[i + N] = A[i];
        S[i + N + N + N][0] = S[i + N + N][0] = S[i + N][0] = S[i][0] = A[i];
        
    }
    for (int j = 1; j <= 19; j++) {
        for (int i = 0; i <= 4 * N; i++) {
            S[i][j] = max(S[i][j - 1], S[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 0; i < N; i++) {
        
        int ans = solve(i, A[i]);
        if (ans >= 1e17) cout << -1 << " ";
        else cout << ans - i << " ";
    }
    cout << "\n";
}