#include <bits/stdc++.h>

using namespace std;
const int c=500005, k=62;
long long w, n, po[62], db[62], t[c], sum, mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    po[0]=1;
    for (int i=1; i<k; i++) {
        po[i]=2*po[i-1]%mod;
    }
    cin >> w;
    while(w-- ) {
        for (int i=0; i<k; i++) {
            db[i]=0;
        }
        cin >> n, sum=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            long long s=t[i];
            for (int j=0; s>0; j++) {
                if (s%2) {
                    db[j]++;
                }
                s/=2;
            }
        }
        for (int i=1; i<=n; i++) {
            long long a=0, b=0, s=t[i];
            for (int i=0; i<k; i++) {
                if (s%2) {
                    a+=db[i]*po[i]%mod;
                    b+=n*po[i]%mod;
                } else {
                    b+=db[i]*po[i]%mod;
                }
                s/=2, a%=mod, b%=mod;
            }
            sum+=a*b, sum%=mod;
        }
        cout << sum << "\n";
    }
}