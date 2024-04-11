#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    long long w, n, k, po, ans, mod=1e9+7;
    cin >> w;
    while (w--) {
        cin >> n >> k;
        ans=0, po=1;
        while (k) {
            if (k%2) {
                ans+=po;
                ans%=mod;
            }
            po=po*n%mod;
            k/=2;
        }
        cout << ans << "\n";
    }
    return 0;
}