#include <bits/stdc++.h>

using namespace std;
long long n, x, ert, ans, mod=998244353;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) {
            ans*=a, ans%=mod;
        }
        p/=2;
        a*=a, a%=mod;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    ert=1;
    for (int i=1; i<=n; i++) {
        cin >> x;
        ans+=ert, ans%=mod;
        ert*=x, ert%=mod;
        ert*=oszt(100), ert%=mod;
    }
    cout << (ans*oszt(ert))%mod << "\n";
    return 0;
}