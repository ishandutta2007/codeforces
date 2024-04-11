#include <bits/stdc++.h>

using namespace std;

int d, m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> d >> m;
        int len = log2(d);
        int res = 1;
        for (int i = 0; i < len; i++) {
            res = 1ll * res * (1 + (1 << i)) % m;
        }
        int num = d - (1 << len) + 1;
        res = 1ll * res * (num + 1) % m;
        res = (res + m - 1) % m;
        cout << res << '\n';
    }   
    return 0;
}