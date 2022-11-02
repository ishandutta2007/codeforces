#include<bits/stdc++.h>

using namespace std;
#define int long long
const int max_n = 104;


signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // online submission
#endif
    int q;
    cin >> q;
    while(q--) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int k1 = (a + c - 1) / c;
        int k2 = (b + d - 1) / d;
        if (k1 + k2 > k) cout << -1 << '\n';
        else cout << k1 << " " << k - k1 << '\n';
    }
}