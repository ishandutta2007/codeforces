#include <bits/stdc++.h>

using namespace std;
long long ans=6, po=16, n, mod=1e9+7;
int main()
{
    cin >> n;
    for (int i=1; i<n; i++) {
        ans=ans*po%mod;
        po=po*po%mod;
    }
    cout << ans << "\n";
    return 0;
}