#include <bits/stdc++.h>

using namespace std;
bool solve() {
    int n, x, dif, ans=0, mini, maxi;
    cin >> n >> dif;
    cin >> x;
    mini=x, maxi=x;
    for (int i=1; i<n; i++) {
        cin >> x;
        mini=min(mini, x), maxi=max(maxi, x);
        if (maxi-mini>2*dif) {
            ans++;
            mini=x, maxi=x;
        }
    }
    cout << ans << "\n";
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