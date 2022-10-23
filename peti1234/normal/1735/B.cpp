#include <bits/stdc++.h>

using namespace std;
int t[105];
void solve() {
    int n, x, mini=1e9;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        mini=min(mini, t[i]);
    }
    int ans=0;
    mini=2*mini-1;
    for (int i=1; i<=n; i++) {
        ans+=(t[i]-1)/mini;
    }
    cout << ans << "\n";
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