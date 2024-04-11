#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n;
        cin >> n;
        long long ans=1, mod=998244353;
        if (n%2) cout << 0 << "\n";
        else {
            for (long long i=1; i<=n/2; i++) {
                ans=ans*i*i%mod;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}