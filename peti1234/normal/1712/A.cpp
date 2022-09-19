#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, k, ans=0;
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (i<=k && x>k) ans++;
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