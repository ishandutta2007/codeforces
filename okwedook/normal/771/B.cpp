#include <bits/stdc++.h>

using namespace std;

int main() {
    string names[] = { "Aa", "Ab", "Ac", "Ad", "Ae", "Af", "Ag", "Ah", "Ai", "Aj", "Ak", "Al", "Am", "An", "Ao", "Ap", "Aq", "Ar", "As", "At", "Au", "Av", "Aw", "Ax", "Ay", "Az", "Ba", "Bb", "Bc", "Bd", "Be", "Bf", "Bg", "Bh", "Bi", "Bj", "Bk", "Bl", "Bm", "Bn", "Bo", "Bp", "Bq", "Br", "Bs", "Bt", "Bu", "Bv", "Bw", "Bx", "By", "Bz" };
    int n, k;
    cin >> n >> k;
    int sz = n - k + 1;
    string s;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i)
        ans[i] = i;
    for (int i = 0; i < sz; ++i) {
        cin >> s;
        if (s == "NO") ans[i + k - 1] = ans[i];
    }
    for (auto i : ans) cout << names[i] << ' ';
    return 0;
}