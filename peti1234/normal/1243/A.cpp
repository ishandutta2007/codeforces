#include <bits/stdc++.h>

using namespace std;
int w, n, t[1005];
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        int ans=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        sort(t+1, t+n+1), reverse(t+1, t+n+1);
        for (int i=1; i<=n; i++) {
            ans=max(ans, min(i, t[i]));
        }
        cout << ans << "\n";
    }
    return 0;
}