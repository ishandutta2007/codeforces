#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long ans, n, a[c], b[c], mod=998244353;
int main()
{
    cin >> n;
    for (long long i=1; i<=n; i++) {
        cin >> a[i];
        a[i]*=i*(n-i+1);
    }
    for (int i=1; i<=n; i++) {
        cin >> b[i];
    }
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    reverse(b+1, b+n+1);
    for (int i=1; i<=n; i++) {
        ans=(ans+a[i]%mod*b[i]%mod)%mod;
    }
    cout << ans << "\n";
    return 0;
}