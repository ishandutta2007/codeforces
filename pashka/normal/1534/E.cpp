#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    int z = 0;
    if (n % 2 == 1 && k % 2 == 0) {
        cout << -1;
        return 0;
    }
    while ((z * k < n) || ((z * k) % 2 != n % 2) || (n * (z + (z % 2) - 1) < k * z)) {
        z++;
    }
    vector<int> a(n, 1);
    int s = n;
    for (int i = 0; i < n; i++) {
        while (s < z * k && a[i] + 2 <= z) {
            s += 2;
            a[i] += 2;
        }
    }
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++) b[i] = {a[i], i};
    long res = 0;
    for (int t = 0; t < s / k; t++) {
        sort(b.rbegin(), b.rend());
        cout << "?";
        for (int i = 0; i < k; i++) {
            cout << " " << (b[i].second + 1);
            b[i].first--;
        }
        cout << endl;
        long x;
        cin >> x;
        res ^= x;
    }
    cout << "! " << res << "\n";

    return 0;
}