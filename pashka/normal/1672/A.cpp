#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka
struct test {
    void solve() {
        int n;
        cin >> n;
        int s = 0;
        for (int i = 0; i  < n; i++) {
            int x; cin >> x;
            s += x - 1;
        }
        if (s % 2 == 0) {
            cout << "maomao90\n";
        } else {
            cout << "errorgorn\n";
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