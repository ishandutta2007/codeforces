#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6 + 10;
const int inf = 1e9;
const int MOD = 1e9 + 7;
int32_t main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    long long x = 1, lst = 0;
    cout << "? " << 1 << " " << 1 << endl;
    cin >> lst;
    for(int i = 29; i >= 0; i--) {
        long long y = x + (1<<i);
        if(y > inf) continue;
        cout << "? " << 1 << " " << y << endl;
        long long d;
        cin >> d;
        if(d == lst - (1<<i)) {
            x += (1<<i);
            lst = d;
        }
    }
    cout << "? " << 1 << " " << inf << endl;
    long long d;
    cin >> d;
    long long l = x, r = inf-(d-lst), u = lst+1;
    cout << "? " << inf << " " << x << endl;
    cin >> d;
    d = inf - d;
    cout << "! " << u << " " << l << " " << d << " " << r << endl;
    return 0;
}