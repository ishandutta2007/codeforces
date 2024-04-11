#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int c = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] + a[i-1] < k) {
            c += k - a[i-1] - a[i];
            a[i] = k - a[i-1];
        }
    }

    cout << c << "\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}