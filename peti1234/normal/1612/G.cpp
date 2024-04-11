#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
long long n, fakt[c], db[c], ans, cnt=1, sum, s[2], mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    fakt[0]=1;
    for (int i=1; i<=n; i++) fakt[i]=fakt[i-1]*i%mod;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        sum+=x;
        db[x]++;
    }
    for (int i=1e6; i>=1; i--) {
        s[i%2]+=db[i];
        long long p=s[i%2];
        cnt=cnt*fakt[p]%mod*(i>1 ? fakt[p] : 1)%mod;
        ans+=(sum%mod*p%mod-p*p%mod+mod)*(i-1)%mod;
        sum-=2*p;
    }
    cout << ans%mod << " " << cnt << "\n";
    return 0;
}