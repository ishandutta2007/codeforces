#include <bits/stdc++.h>

using namespace std;
const int c=1000002;
long long ans[c], db[c], sum, n, mod=998244353;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=i; j<=n; j+=i) {
            db[j]++;
        }
        ans[i]=(sum+db[i])%mod;
        sum=(sum+ans[i])%mod;
    }
    cout << ans[n] << "\n";
    return 0;
}