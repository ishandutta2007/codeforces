#include <bits/stdc++.h>

using namespace std;
long long n, mod=1000000007, fakt[200002], sum;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while(p) {
        if (p%2) ans*=a, ans%=mod;
        a*=a, a%=mod, p/=2;
    }
    return ans;
}
int main()
{
    cin >> n, fakt[0]=1;
    for (int i=1; i<=2*n; i++) fakt[i]=fakt[i-1]*i%mod;
    sum=fakt[2*n-1]*oszt(fakt[n-1])%mod*oszt(fakt[n])%mod*2;
    cout << (sum+mod-n)%mod << "\n";
    return 0;
}