#pragma GCC optimize ("O3")
#pragma GCC target ("sse,sse2,sse3,ssse3,avx,avx2,fma,mmx,tune=native")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MOD = 1e9 + 7;

vector<int> s, k;

int solve() {
    lint X;
    cin >> X;
    s.clear();
    k.clear();
    string S;
    cin >> S;
    for (auto i : S) {
        s.emplace_back(i - '0');
    }
    lint N = s.size();
    
    for (int i = 0; i < X; i++) {
        if (s.empty()) break;
        k.clear();
        int cur = s.size();
        for (int k = 0; k < s[i] - 1; k++) {
            for (int j = i + 1; j < cur; j++) {
                if (s.size() < X + 10) {
                    s.emplace_back(s[j]);
                } else {
                    break;
                }
            }
        }
        N = (1ll * N + 1ll * (s[i] - 1) * ((N - i - 1))) % MOD;
        if (N >= MOD) N -= MOD;
        if (N < 0) N += MOD;
    }
    cout << N << "\n";

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    s.reserve(4000000);
    k.reserve(4000000);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}