#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, m;
int a[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n > m) {
        cout << 0 << endl;
        return 0;
    }
    int res = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            res = 1ll * res * abs(a[i] - a[j]) % m;
        }
    }
    cout << res << endl;
    return 0;
}