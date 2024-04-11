#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    string s;
    cin >> s;
    int n = s.size();
    string res;
    res += s[0];
    int c = 0;
    for (int i = 1; i < n; i++) {
        char x = s[i];
        if (res[c + 1] == x) {
            c++;
        } else {
            if (c > 0 && res[c - 1] == x) {
                c--;
            } else {
                if (c == 0) {
                    res = x + res;
                    c = 0;
                } else if (c == res.size() - 1) {
                    res += x;
                    c++;
                } else {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    vector<bool> z(26);
    for (char x : res) {
        if (z[x - 'a']) {
            cout << "NO\n";
            return;
        }
        z[x - 'a'] = true;
    }
    for (int i = 0; i < 26; i++) {
        if (!z[i]) res += (char)('a' + i);
    }
    cout << "YES\n" << res << "\n";
    return;
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve_test();
    }

    return 0;
}