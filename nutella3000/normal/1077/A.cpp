#include<bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // online submission
#endif

    int q, a, b, k;
    cin >> q;
    while(q--) {
        cin >> a >> b >> k;
        cout << (k + 1) / 2 * a - k / 2 * b << '\n';
    }
}