#include <bits/stdc++.h>

using namespace std;
long long n, mod, sum;
long long fakt[250002];

int main()
{
    cin >> n >> mod;
    fakt[0]=1;
    for (long long i=1; i<=n; i++) fakt[i]=fakt[i-1]*i, fakt[i]%=mod;
    for (long long i=1; i<=n; i++) sum+=(n-i+1)*(n-i+1)%mod*fakt[i]%mod*fakt[n-i]%mod;
    cout << sum%mod << "\n";
    return 0;
}