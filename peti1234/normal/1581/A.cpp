#include <bits/stdc++.h>

using namespace std;
long long w, n, ans, mod=1e9+7;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        ans=1;
        for (int i=3; i<=2*n; i++) {
            ans=ans*i%mod;
        }
        cout << ans << "\n";
    }
    return 0;
}