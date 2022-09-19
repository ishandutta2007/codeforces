#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i <n ; i++) cin >> a[i];
    bool ok = true;
    for (int i = 1; i < n; i++) if (a[i] != a[0]) ok = false;
    if (ok) {
        cout << n << "\n";
    } else {
        cout << 1 << "\n";
    };
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