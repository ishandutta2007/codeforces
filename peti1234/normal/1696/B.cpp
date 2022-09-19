#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, kezd=0, veg=0, db=0, x;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x;
        if (x) {
            if (!kezd) kezd=i;
            veg=i;
            db++;
        }
    }
    if (!db) cout << 0 << "\n";
    else if (veg-kezd+1==db) {
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}