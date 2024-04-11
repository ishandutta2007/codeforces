#include <bits/stdc++.h>

using namespace std;
long long mod=1e9+7;
long long w, n, es, mini, mindb, ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        cin >> es;
        mini=es, mindb=1;
        for (int i=2; i<=n; i++) {
            int x;
            cin >> x;
            es=(es&x);
            if (x<mini) {
                mindb=0;
                mini=x;
            }
            if (x==mini) {
                mindb++;
            }
        }
        ans=mindb*(mindb-1)%mod;
        for (int i=1; i<=n-2; i++) {
            ans*=i;
            ans%=mod;
        }
        if (es!=mini) {
            ans=0;
        }
        cout << ans << "\n";
    }
    return 0;
}