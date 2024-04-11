#include <bits/stdc++.h>

#define long long long int

using namespace std;

// @author: pashka


void solve_test() {
    int n;
    cin >> n;
    int r, p, s;
    cin >> r >> p >> s;
    string q;
    cin >> q;
    string w;
    for (int i = 0; i < n; i++) w += "?";
    int win = 0;
    for (int i = 0; i < n; i++) {
        if (q[i] == 'R' && p > 0) {
            w[i] = 'P';
            p--;
            win++;
        }
        if (q[i] == 'P' && s > 0) {
            w[i] = 'S';
            s--;
            win++;
        }
        if (q[i] == 'S' && r > 0) {
            w[i] = 'R';
            r--;
            win++;
        }
    }
    if (win * 2 >= n) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            if (w[i] == '?') {
                if (r > 0) {
                    w[i] = 'R';
                    r--;
                } else if (p > 0) {
                    w[i] = 'P';
                    p--;
                } else if (s > 0) {
                    w[i] = 'S';
                    s--;
                }
            }
        }
        cout << w << "\n";
    } else {
        cout << "NO\n";
    }
}


int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve_test();
    }

    return 0;
}