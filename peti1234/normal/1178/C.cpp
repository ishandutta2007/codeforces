#include <bits/stdc++.h>

using namespace std;
int a, b, ans=1, mod=998244353;
int main()
{
    cin >> a >> b;
    for (int i=1; i<=a+b; i++) {
        ans=2*ans%mod;
    }
    cout << ans << "\n";
    return 0;
}