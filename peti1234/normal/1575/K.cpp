#include <bits/stdc++.h>

using namespace std;
long long n, m, k, r, c, a1, b1, a2, b2, db, o, p, mod=1e9+7;
long long po(long long a, long long b) {
    long long ans=1;
    while (b) {
        if (b%2) ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}
int main()
{
    cin >> n >> m >> k >> r >> c >> a1 >> b1 >> a2 >> b2;
    long long ert=(a1==a2 && b1==b2 ? 0 : r*c);
    cout << po(k, n*m-ert) << "\n";
    return 0;
}