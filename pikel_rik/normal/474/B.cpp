#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    cin >> a[0];

    for (int i = 1; i < n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;

        cout << lower_bound(a.begin(), a.end(), q) - a.begin() + 1 << "\n";
    }
    return 0;
}