#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int t[c], kezd[c], veg[c];
void solve() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) kezd[i]=max(kezd[i-1], t[i]);
    for (int i=n; i>=1; i--) veg[i]=max(veg[i+1], t[i]);
    bool jo=1;
    for (int i=1; i<=n; i++) {
        if (kezd[i-1]>t[i] && veg[i+1]>t[i]) {
            jo=0;
        }
    }
    cout << (jo ? "YES" : "NO") << "\n";
    for (int i=1; i<=n; i++) {
        t[i]=0, kezd[i]=0, veg[i]=0;
    }
}
int main()
{
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}