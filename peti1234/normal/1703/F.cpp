#include <bits/stdc++.h>

using namespace std;
int t, n, a[200005], pref[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n;
        long long ans=0;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            pref[i]=pref[i-1]+(a[i]<i);
            if (a[i]<i) {
                ans+=pref[max(0, a[i]-1)];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}