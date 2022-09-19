#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int c=300005;
ll n, sum, t[c], fakt[c], inv[c], dp[c], gy[c], mod=1e9+7, f, udb;
map<int, int> m;
ll po(ll a, ll b) {
    ll ans=1;
    while (b) {
        if (b%2) ans=ans*a%mod;
        a=a*a%mod, b/=2;
    }
    return ans;
}
ll oszt(ll a) {
    return po(a, mod-2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> sum >> n;
    fakt[0]=1, inv[0]=1;
    for (int i=1; i<=sum; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
    }
    for (int i=1; i<=sum; i++) {
        int x;
        cin >> x;
        (x==-1 ? udb++ : m[x]++);
    }
    dp[0]=n-1;
    for (int i=1; i<sum; i++) {
        ll pl=sum-i, mi=i*(n-1)%mod, ne=((n-1)*sum-pl-mi)%mod;
        mi*=oszt(pl), mi%=mod, ne*=oszt(pl), ne%=mod;
        dp[i]=(mi+mi*dp[i-1]+ne+1)%mod;
    }
    for (int i=sum-1; i>=0; i--) dp[i]+=dp[i+1], dp[i]%=mod;
    for (int i=0; i<=udb; i++) gy[i]=fakt[udb]*inv[i]%mod*inv[udb-i]%mod*po(n-1, udb-i)%mod;
    for (auto x:m) t[x.second]++;
    t[0]=n-m.size();
    for (int i=0; i<=sum; i++) {
        if (!t[i]) continue;
        for (int s=0; s<=udb; s++) {
            f+=t[i]*gy[s]%mod*dp[i+s]%mod;
        }
    }
    f=f%mod*oszt(po(n, udb))%mod;
    cout << (f-(n-1)*dp[0]+mod*mod)%mod*oszt(n-1)%mod;
    return 0;
}