#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int N = 1e5 + 5;
const int M = 100 + 5;

template <typename T>
vector<int> LPS(const T& t, int n) {
    vector<int> lps(n);
    int len = 0, i = 1;
    lps[0] = 0;

    while (i < n) {
        if (t[i] == t[len]) {
            len += 1;
            lps[i] = len;
            i += 1;
        } else if (len != 0) {
            len = lps[len - 1];
        } else {
            lps[i] = 0;
            i += 1;
        }
    }
    return lps;
}

int n;
string s, s_rev;

bool check(string& t) {
    int m = t.length();
    vector<int> lps = LPS(t, m);

    vector<int> pref(n, -1);
    {
        int i = 0, j = 0;
        while (i < n) {
            if (s[i] == t[j]) {
                pref[i] = max(pref[i], j);
                i++;
                j++;
            }
            if (j == m) {
                j = lps[j - 1];
            } else if (i < n and s[i] != t[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else i++;
            }
        }
        for (i = 1; i < n; i++) {
            pref[i] = max(pref[i], pref[i - 1]);
        }
    }

    reverse(t.begin(), t.end());
    lps = LPS(t, m);
    vector<int> suf(n, -1);
    {
        int i = 0, j = 0;
        while (i < n) {
            if (s_rev[i] == t[j]) {
                suf[i] = max(suf[i], j);
                i++;
                j++;
            }
            if (j == m) {
                j = lps[j - 1];
            } else if (i < n and s_rev[i] != t[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else i++;
            }
        }
        for (i = 1; i < n; i++) {
            suf[i] = max(suf[i], suf[i - 1]);
        }
        reverse(suf.begin(), suf.end());
    }
    for (int i = 1; i < n; i++) {
        if (pref[i - 1] + 1 + suf[i] + 1 >= m) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s; s_rev = s;
    n = s.length();

    reverse(s_rev.begin(), s_rev.end());

    int m, ans = 0;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string t;
        cin >> t;
        if (t.length() > 1) {
            ans += check(t);
        }
    }
    cout << ans << '\n';
    return 0;
}