#include <bits/stdc++.h>

using namespace std;
int n, ans=1, mod=1e6+3;
int main()
{
    cin >> n;
    for (int i=1; i<n; i++) {
        ans*=3;
        ans%=mod;
    }
    cout << ans << "\n";
    return 0;
}