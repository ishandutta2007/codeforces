#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int KEY = 71;

int power(int n, int x) {
    if (x == 0) {
        return 1;
    }
    if (x & 1) {
        return (1ll * n * power(n, x - 1)) % MOD;
    }
    int res = power(n, x / 2);
    return (1ll * res * res) % MOD;
}

int transform(char a) {
    if ('a' <= a && a <= 'z') {
        return a - 'a' + 1;
    }
    if ('A' <= a && a <= 'Z') {
        return a - 'A' + 27;
    }
    if ('0' <= a && a <= '9') {
        return a - '0' + 53;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> suff, pref;

    for (int it = 1; it < n; it++) {
        string t;
        cin >> t;

        int len = min(s.size(), t.size());
        int sz = s.size();
        suff.resize(len + 2);
        pref.resize(len + 2);

        for (int i = 1; i <= len; i++) {
            suff[i] = (1ll * suff[i - 1] + 1ll * transform(s[sz - i]) * power(KEY, i - 1)) % MOD;
            pref[i] = (1ll * pref[i - 1] * KEY + transform(t[i - 1])) % MOD;
        }
        int mx = 0;
        for (int i = 1; i <= len; i++) {
            if (suff[i] == pref[i]) {
                mx = i;
            }
        }
        for (int i = mx; i < t.size(); i++) {
            s.push_back(t[i]);
        }
    }

    cout << s << "\n";
    return 0;
}