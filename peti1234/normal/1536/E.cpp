#include <bits/stdc++.h>

using namespace std;
int w, n, m, db;
long long ans, mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        db=0;
        for (int i=0; i<n*m; i++) {
            char c;
            cin >> c;
            if (c=='#') {
                db++;
            }
        }
        ans=1;
        for (int i=1; i<=db; i++) {
            ans*=2, ans%=mod;
        }
        if (db==n*m) {
            ans=(ans-1+mod)%mod;
        }
        cout << ans << "\n";
    }
    return 0;
}