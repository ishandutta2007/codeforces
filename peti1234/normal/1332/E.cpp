#include <bits/stdc++.h>

using namespace std;
long long a, b, c, d, o, e, m, x=1, y=0;
long long mod=998244353;
int main()
{
    cin >> a >> b >> c >> d;
    m=a*b;
    o=(d-c)/2;
    if (d%2 || c%2) o++;
    e=d-c-o+1;
    e%=mod, o%=mod;
    while(m) {
        if (m%2) {
            long long p=x, q=y;
            x=(p*e+q*o)%mod, y=(p*o+q*e)%mod;
        }
        m/=2;
        long long p=e, q=o;
        e=(p*p+q*q)%mod, o=(2*p*q)%mod;
    }
    if (a%2 && b%2) cout << (x+y)%mod << "\n";
    else cout << x << "\n";
    return 0;
}