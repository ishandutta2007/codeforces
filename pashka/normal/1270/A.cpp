#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int mx1 = 0, mx2 = 0;
    for (int i = 0; i < k1; i++) {
        int x;
        cin >> x;
        mx1 = max(mx1, x);
    }
    for (int i = 0; i < k2; i++) {
        int x;
        cin >> x;
        mx2 = max(mx2, x);
    }
    cout << (mx1 > mx2 ? "YES" : "NO") << "\n";
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