#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int s = 0;
    for (int i = 0; i  < n; i++) {
        s += a[i];
    }
    if (s == x) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    s = 0;
    for (int i = 0; i < n; i++) {
        if (s + a[i] != x) {
            cout << a[i] << " ";
            s += a[i];
        } else {
            cout << a[i + 1] << " " << a[i] << " ";
            s += a[i] + a[i + 1];
            i++;
        }
    }
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