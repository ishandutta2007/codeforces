#include <bits/stdc++.h>

using namespace std;

bool check(int n, const string &s, int l, int r) {
    if (r - l > 25) return true;
    for (int i = l; i < r; ++i) {
        for (int k = 1; i + k + k < r; ++k) {
            if (s[i] == s[i + k] && s[i + k] == s[i + k + k]) {
                return true;
            }
        }
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    string s;
    cin >> s;
    int n = s.size();
    int p = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        while (p <= n && !check(n, s, i, p)) ++p;
        ans += n - p + 1;
    }
    cout << ans << '\n';
}