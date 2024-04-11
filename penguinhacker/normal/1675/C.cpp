#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t; cin >> t;
 
    while (t--) {
        string s; cin >> s;
        int n = s.size();
 
        vector<bool> ones(n + 1), zeroes(n + 1);
        ones[0] = zeroes[n] = true;
        
        for (int i = 0; i < n; ++i) {
            ones[i + 1] = ones[i] && (s[i] == '1' || s[i] == '?');
        }
 
        for (int i = n; i > 0; --i) {
            zeroes[i - 1] = zeroes[i] && (s[i - 1] == '0' || s[i - 1] == '?');
        }
 
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (ones[i] && zeroes[i] || ones[i + 1] && zeroes[i + 1]);
        }
 
        cout << ans << "\n";
    }
}