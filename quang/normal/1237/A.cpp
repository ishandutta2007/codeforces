#include <bits/stdc++.h>

using namespace std;

int getCeil(int u, int v) {
    if (u > 0) return (u - 1) / v + 1;
    return -(-u / v);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &u : a) cin >> u;
    vector<int> b(n);
    int sum = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] % 2 == 0) {
            b[i] = a[i] / 2;
        } else {
            b[i] = getCeil(a[i], 2);
        }
        sum += b[i];
    }
    for (int i = 0; i < b.size(); i++) {
        if (a[i] % 2 == 0) continue;
        if (sum > 0) {
            sum--;
            b[i]--;
        }
    }
    for (int i = 0; i < b.size(); i++) cout << b[i] << '\n';
    return 0;
}