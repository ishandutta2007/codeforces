#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int a, b, c, r;
    cin >> a >> b >> c >> r;
    if (a > b) {
        swap(a, b);
    }
    // [a b] - [c-r, c+r]
    int res = b - a;
    int ll = max(a, c - r);
    int rr = min(b, c + r);
    if (rr > ll) {
        res -= rr - ll;
    }
    cout << res << "\n";
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