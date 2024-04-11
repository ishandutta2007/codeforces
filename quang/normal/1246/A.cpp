#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    for (int i = 0; i <= (int)1e7; i++) {
        long long now = n - 1ll * i * p;
        int num = __builtin_popcountll(now);
        if (num > i) continue;
        if (now >= i) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}