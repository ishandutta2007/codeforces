#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve() {
        string s;
        cin >> s;
        int n = s.size();
        int res = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                res++;
                s[i] = '?';
            } else if (i >= 2 && s[i] == s[i - 2]) {
                res++;
                s[i] = '?';
            }
        }
        cout << res << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test t;
        t.solve();
    }

    return 0;
}