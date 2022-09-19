#include <bits/stdc++.h>

using namespace std;
int n, m, ans;
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int mini=1e9;
        for (int j=1; j<=m; j++) {
            int x;
            cin >> x;
            mini=min(x, mini);
        }
        ans=max(ans, mini);
    }
    cout << ans << "\n";
    return 0;
}