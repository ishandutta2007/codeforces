#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int b, k;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int res = 0;
    cin >> b >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }
    int cur = 1;
    for (int i = k; i; i--) {
        // cout << cur << " " << a[i] << " " << cur << endl;
        res ^= (1ll * cur * a[i]) % 2;
        cur = (1ll * cur * b) % 2;
    }
    cout << (res ? "odd" : "even") << endl;
    return 0;
}