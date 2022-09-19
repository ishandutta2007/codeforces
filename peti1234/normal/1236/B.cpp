#include <bits/stdc++.h>

using namespace std;
long long a, b, mod=1e9+7;
long long po(long long x, long long y) {
    long long ans=1;
    while (y) {
        if (y%2) {
            ans=ans*x%mod;
        }
        x=x*x%mod;
        y/=2;
    }
    return ans;
}
int main()
{
    cin >> a >> b;
    long long s=(po(2, b)+mod-1)%mod;
    cout << po(s, a) << "\n";
    return 0;
}