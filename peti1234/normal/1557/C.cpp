#include <bits/stdc++.h>

using namespace std;
long long w, n, k, po[200005], mod=1e9+7;
int main()
{
    po[0]=1;
    for (int i=1; i<200005; i++) {
        po[i]=po[i-1]*2%mod;
    }
    cin >> w;
    while (w--) {
        cin >> n >> k;
        if (n%2) {
            long long ans=1;
            for (int i=1; i<=k; i++) {
                ans*=(po[n-1]+1), ans%=mod;
            }
            cout << ans << "\n";
        } else {
            long long ans1=1, ans2=0;
            for (int i=1; i<=k; i++) {
                ans2=(ans2*po[n]+ans1)%mod;
                ans1=ans1*(po[n-1]-1)%mod;
            }
            cout << (ans1+ans2)%mod << "\n";
        }
    }
    return 0;
}