#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 3e5;
int arr[MAXN];
int os[MAXN];

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    if (n == 1) {
        cout << 1 << " " << 1 << endl;
        cout << -arr[0] << endl;
        for (int i = 0; i < 2; ++i) {
            cout << 1 << " " << 1 << endl;
            cout << 0 << endl;
        }
        return 0;
    }
    cout << 1 << " " << n << '\n';
    for (int i = 0; i < n; ++i) {
        int r = (arr[i] % n + n) % n;
        r = (n - r) % n;
        int k = (arr[i] + r) / n;
        cout << n * (r - k) << " ";
        os[i] = (n - 1) * (-r);
    }
    cout << '\n';
    cout << 1 << " " << n - 1 << '\n';
    for (int i = 0; i < n - 1; ++i) {
        cout << os[i] << " ";
    }
    cout << '\n';
    cout << 2 << " " << n << '\n';
    for (int i = 1; i < n; ++i) {
        if (i == n - 1) {
            cout << os[i] << " ";
        } else {
            cout << 0 << " ";
        }
    }
    return 0;
}