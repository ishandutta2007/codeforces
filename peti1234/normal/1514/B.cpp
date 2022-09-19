#include <bits/stdc++.h>

using namespace std;
int w;
long long n, k, ans, mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        ans=1;
        for (int i=1; i<=k; i++) {
            ans*=n;
            ans%=mod;
        }
        cout << ans << "\n";
    }
    return 0;
}