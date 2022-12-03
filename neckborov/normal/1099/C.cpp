//#pragma GCC optimize("O3", "no-stack-protector")
//#pragma GCC target("sse4", "avx", "popcnt", "lzcnt", "sse3", "sse4.1", "sse4.2", "sse2", "tune=native")
//#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using old = long double;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int k;
    cin >> k;
    int tot = 0;
    int kek = 0;
    for (char c : s) {
        if (c < 'a' || c > 'z') {
            ++tot;
        }
        if (c == '*') {
            ++kek;
        }
    }
    if ((int)s.length() - tot * 2 > k || (int)s.length() - tot < k && !kek) {
        cout << "Impossible";
        return 0;
    }
    string t;
    if (kek) {
        int topkek = k - ((int)s.length() - tot * 2);
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '?' || s[i] == '*') {
                continue;
            }
            if (i + 1 < s.length() && s[i + 1] == '*' && topkek > 0) {
                while (topkek) {
                    --topkek;
                    t += s[i];
                }
            }
            if (i + 1 < s.length() && (s[i + 1] == '?' || s[i + 1] == '*')) {
                continue;
            }
            t += s[i];
        }
    } else {
        int topkek = (int)s.length() - tot - k;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '?') {
                continue;
            }
            if (topkek > 0 && s[i + 1] == '?') {
                --topkek;
                continue;
            }
            t += s[i];
        }
    }
    cout << t;
    return 0;
}