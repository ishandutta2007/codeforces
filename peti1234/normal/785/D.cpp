#include <bits/stdc++.h>

using namespace std;
string s;
long long fakt[200002], inv[200002], mod=1000000007, n, o, c, sum;
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
    cin >> s, n=s.size(), fakt[0]=1, inv[0]=1;
    for (long long i=1; i<=n; i++) fakt[i]=fakt[i-1]*i%mod, inv[i]=oszt(fakt[i]);
    for (int i=0; i<n; i++) c+=s[i]==')';
    for (int i=0; i<n; i++) {
        if (s[i]==')') c--;
        else {
            if (c) sum+=fakt[o+c]*inv[c-1]%mod*inv[o+1]%mod, sum%=mod,
            o++;
        }
    }
    cout << sum << "\n";
    return 0;
}