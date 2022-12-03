//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        while (!s.empty() && !t.empty() && s.back() == t.back()) {
            int cnt1 = 0, cnt2 = 0;
            char c = s.back();
            while (!s.empty() && s.back() == c) {
                s.pop_back();
                cnt1++;
            }
            while (!t.empty() && t.back() == c) {
                t.pop_back();
                cnt2++;
            }
            if (cnt2 < cnt1) {
                s += '?';
                break;
            }
        }
        if (s.empty() && t.empty()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}