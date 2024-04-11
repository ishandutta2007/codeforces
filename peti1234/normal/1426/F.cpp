#include <bits/stdc++.h>

using namespace std;
const int c=300005;
long long mod=1e9+7, h=1, ie, ik, ih, sum, n, k, ea[c], ek[c], uc[c], uk[c];
string s;
long long oszt(long long a) {
    long long p=mod-2, ans=1;
    while(p) {
        if (p%2) ans*=a, ans%=mod;
        a*=a, a%=mod, p/=2;
    }
    return ans;
}
int main()
{
    cin >> n >> s;
    for (int i=0; i<n; i++) {
        if (s[i]=='?') k++, h*=3, h%=mod, ek[i]++, uk[i]++;
        if (s[i]=='a') ea[i]++;
        if (s[i]=='c') uc[i]++;
    }
    for (int i=1; i<n; i++) ek[i]+=ek[i-1], ea[i]+=ea[i-1];
    for (int i=n-2; i>=0; i--) uc[i]+=uc[i+1], uk[i]+=uk[i+1];
    ie=oszt(3), ik=oszt(9), ih=oszt(27);
    for (int i=1; i<n-1; i++) {
        if (s[i]=='b') {
            sum+=ea[i-1]*uc[i+1]%mod;
            sum+=ea[i-1]*uk[i+1]%mod*ie%mod;
            sum+=ek[i-1]*uc[i+1]%mod*ie%mod;
            sum+=ek[i-1]*uk[i+1]%mod*ik%mod;
        }
        if (s[i]=='?') {
            sum+=ea[i-1]*uc[i+1]%mod*ie%mod;
            sum+=ea[i-1]*uk[i+1]%mod*ik%mod;
            sum+=ek[i-1]*uc[i+1]%mod*ik%mod;
            sum+=ek[i-1]*uk[i+1]%mod*ih%mod;
        }
        sum%=mod;
    }
    cout << sum*h%mod << "\n";
    return 0;
}