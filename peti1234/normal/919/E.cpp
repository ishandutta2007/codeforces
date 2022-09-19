#include <bits/stdc++.h>

using namespace std;
long long a, b, mod, sum, cel, x, po=1;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) {
            ans*=a, ans%=mod;
        }
        a*=a, a%=mod;
        p/=2;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> mod >> x;
    for (int i=1; i<mod; i++) {
        po*=a, po%=mod;
        cel=b*oszt(po)%mod;
        long long kezd=i+(i+mod-cel)%mod*(mod-1);
        if (kezd<=x) {
            sum+=(x-kezd)/(mod)/(mod-1)+1;
        }
    }
    cout << sum << "\n";
    return 0;
}