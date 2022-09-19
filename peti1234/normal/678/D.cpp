#include <bits/stdc++.h>

using namespace std;
long long ert, a, b, po, mod=1e9+7;
int main()
{
    cin >> a >> b >> po >> ert;
    while (po) {
        if (po%2) {
            ert=(ert*a+b)%mod;
        }
        b=(a*b+b)%mod;
        a=(a*a)%mod;
        po/=2;
    }
    cout << ert << "\n";
    return 0;
}