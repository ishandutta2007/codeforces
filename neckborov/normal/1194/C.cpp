//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int Q;
    cin >> Q;
    while (Q--) {
        string s, t, p;
        cin >> s >> t >> p;
        vector<int> kek(26);
        for (char c : t) {
            kek[c - 'a']++;
        }
        for (char c : s) {
            kek[c - 'a']--;
        }
        for (char c : p) {
            kek[c - 'a']--;
        }
        int j = 0;
        bool f = *max_element(kek.begin(), kek.end()) <= 0;
        for (int i = 0; i < s.length(); i++) {
            while (j < t.length() && s[i] != t[j]) {
                j++;
            }
            if (j == t.length()) {
                f = false;
                break;
            }
            j++;
        }
        if (f) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}