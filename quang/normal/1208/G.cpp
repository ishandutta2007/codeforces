#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int phi[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << 3 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        phi[i] += i;
        for (int j = i + i; j <= n; j += i) {
            phi[j] -= phi[i];
        }
    }
    sort(phi + 1, phi + n + 1);
    long long res = 0;
    for (int i = 1; i <= k + 2; i++) {
        res += phi[i];
    }
    cout << res << endl;
    return 0;
}