#include <bits/stdc++.h>

#define rep(i, s, t) for (int i = s; i < t; i++)
#define per(i, s, t) for (int i = s; i >= t; i--)
#define sz(x) ((int)x.size())
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;

bool is_eq(const string &s) {
    bool eq = true;
    int n = sz(s);
    rep(i, 1, n) eq &= s[i] == s[0];
    return eq;
}

bool is_pal(const string &s) {
    string rs = s;
    reverse(rs.begin(), rs.end());
    return rs == s;
}

int main() {
    string s;
    cin >> s;
    int n = sz(s);
    if (is_eq(s)) {
        cout << "Impossible\n";
        return 0;
    }
    rep(i, 1, n) {
        string a = s.substr(0, i);
        string b = s.substr(i, n - i);
        if (b + a != s && is_pal(b + a)) {
            cout << "1\n";
            return 0;
        }
    }
    rep(i, 1, (n - 1) / 2 + 1) {
        string a = s.substr(0, i);
        string b = s.substr(i, n - 2 * i);
        string c = s.substr(n - i, i);
        if (c + b + a != s && is_pal(c + b + a)) {
            cout << "2\n";
            return 0;
        }
    }
    if (n % 2 == 0) {
        cout << "3\n";
    } else {
        if (is_eq(s.substr(0, n / 2))) {
            cout << "Impossible\n";
            return 0;
        }
        cout << "4\n";
        return 0;
    }
    return 0;
}