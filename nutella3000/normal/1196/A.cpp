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

    int q, a, b, c;
    cin >> q;
    while(q--) {
        cin >> a >> b >> c;
        cout << (a + b + c) / 2 << '\n';
    }
}