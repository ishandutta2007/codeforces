#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int solve();
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    // T = 1;
    while (T--) solve();
    return 0;
}

int solve() {

    string s, h;
    cin >> s >> h;
    
    sort(s.begin(), s.end());
    for (int i = 0; i + s.size() - 1 < h.size(); i++) {
        string k(h.begin() + i, h.begin() + i + s.size());
        sort(k.begin(), k.end());
        if (s == k) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}