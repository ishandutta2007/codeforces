#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    map<char, int> cnt;
    int n;
    cin >> n; 
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ++cnt[s[0]];
    }
    int ans = 0;
    for (auto [kek, c]: cnt) {
        int a = c / 2;
        int b = c - a;
        ans += a * (a - 1) / 2;
        ans += b * (b - 1) / 2;
    }
    cout << ans << '\n';
}