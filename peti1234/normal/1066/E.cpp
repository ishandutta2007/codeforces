#include <bits/stdc++.h>

using namespace std;
long long ans, mod=998244353, ert=1, n, m, cnt;
string a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i=0; i<m; i++) {
        if (b[i]=='1') cnt++;
    }
    for (int i=0; i<n; i++) {
        if (a[i]=='1') ans=(ans+ert*cnt)%mod;
        ert=(2*ert)%mod;
        if (i<m && b[i]=='1') cnt--;
    }
    cout << ans << "\n";
    return 0;
}