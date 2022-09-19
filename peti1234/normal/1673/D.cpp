#include <bits/stdc++.h>

using namespace std;
long long w, kezd, dif, veg, cnt, kezd2, veg2, dif2, cnt2, ans, mod=1e9+7;
bool f(long long x) {
    return (kezd<=x && x<=veg && (x-kezd)%dif==0);
}
void solve(long long k) {
    long long s=__gcd(dif, k);
    if (dif*k==dif2*s) {
        ans=(ans+(dif2/k)*(dif2/k))%mod;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> kezd >> dif >> cnt >> kezd2 >> dif2 >> cnt2;
        veg=kezd+(cnt-1)*dif, veg2=kezd2+(cnt2-1)*dif2;
        if (!f(kezd2) || !f(veg2) || !f(kezd2+dif2)) {
            cout << 0 << "\n";
            continue;
        }
        if (!f(kezd2-dif2) || !f(veg2+dif2)) {
            cout << -1 << "\n";
            continue;
        }
        for (long long i=1; i*i<=dif2; i++) {
            if (dif2%i==0) {
                solve(i);
            }
            if (i*i<dif2) {
                solve(dif2/i);
            }
        }
        cout << ans << "\n";
        ans=0;
    }
    return 0;
}