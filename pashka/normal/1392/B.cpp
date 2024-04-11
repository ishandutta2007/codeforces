#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int n;
    cin >> n;
    long k;
    cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (k > 2) { k = 2 + (k - 2) % 2; }
    for (int i = 0; i < k; i++) {
        int d = INT_MIN;
        for (int j = 0; j < n; j++) {
            d = max(d, a[j]);
        }
        for (int j = 0; j < n; j++) {
            a[j] = d - a[j];
        }
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
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