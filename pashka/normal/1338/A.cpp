#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long x = 0;
    for (int i = 1; i < n; i++) {
        x = max(x, 0ll + a[i - 1] - a[i]);
        a[i] = max(a[i], a[i - 1]);
    }
    int k = 0;
    while (x > 0) {
        k++;
        x >>= 1;
    }
    cout << k << "\n";
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