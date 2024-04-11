#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka
struct test {
    void solve() {
        string s;
        cin >> s;
        if (s[s.size() - 1] == 'A') {
            cout << "NO\n";
            return;
        }
        int x = 0;
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            if (s[i] == 'B') {
                x += 1;
            } else {
                x = max(x - 1, 0);
            }
        }
        if (x == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test().solve();
    }

    return 0;
}