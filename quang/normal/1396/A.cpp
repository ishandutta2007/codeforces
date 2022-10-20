#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 100010;

int n;
int a[N];

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 1 << ' ' << 1 << endl;
        cout << -a[1] << endl;
        cout << 1 << ' ' << 1 << endl;
        cout << 0 << endl;
        cout << 1 << ' ' << 1 << endl;
        cout << 0 << endl;
        return 0;
    }
    cout << 1 << ' ' << n - 1 << endl;
    for (int i = 1; i <= n - 1; i++) {
        cout << 1ll * a[i] * (n - 1) << ' ';
        a[i] += 1ll * a[i] * (n - 1);
    }
    cout << endl;
    cout << n << ' ' << n << endl;
    cout << -a[n] << endl;
    a[n] = 0;
    cout << 1 << ' ' << n << endl;
    for (int i = 1; i <= n; i++) {
        cout << -a[i] << ' ';
    }
    cout << endl;
    return 0;
}