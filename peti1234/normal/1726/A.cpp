#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, t[2005];
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    int ans=t[n]-t[1];
    for (int i=1; i<n; i++) {
        ans=max(ans, t[i]-t[i+1]);
    }
    for (int i=1; i<n; i++) {
        ans=max(ans, t[n]-t[i]);
    }
    for (int i=2; i<=n; i++) {
        ans=max(ans, t[i]-t[1]);
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