#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int s = 0;
    for (int x : a) s += x;
    sort(a.begin(), a.end());
    if (a[n - 1] > s - a[n - 1]) {
        cout << "T\n";
    } else {
        if (s % 2 == 1) {
            cout << "T\n";
        } else {
            cout << "HL\n";
        }
    }
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