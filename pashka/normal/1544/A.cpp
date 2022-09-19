#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve_test() {
        string s;
        cin >> s;
        int res = 0;
        for (char c : s) {
            res = max(res, (int)c - '0');
        }
        cout << res << "\n";
    }
};


int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test().solve_test();
    }

    return 0;
}