#include <bits/stdc++.h>

using namespace std;
int w, n, t[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) cin >> t[i];
        int ans=0, len=1;
        while (len<n) {
            while (t[n-len]==t[n]) len++;
            if (len<n) len*=2, ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}