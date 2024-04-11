#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        if(3*b<a) cout << b << '\n';
        else if(3*a < b) cout << a << '\n';
        else {
            cout << (a + b) / 4 << '\n';
        }
    }
}