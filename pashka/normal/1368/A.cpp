#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int a, b, n;
    cin >> a >> b >> n;
    int t = 0;
    while (max(a, b) <= n) {
        t++;
        if (a < b) a += b; else b += a;
    }
    cout << t << "\n";
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