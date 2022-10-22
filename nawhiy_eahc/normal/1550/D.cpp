#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll fact[200002], invfact[200002];

const ll mod = 1e9 + 7;
ll pow(ll x, ll y)
{
    ll ans = 1; int k = 0;
    while((1LL << k) <= y)
    {
        if((1LL << k) & y)
        {
            ans = (ans * x)%mod;
        }
        x = (x * x)%mod;
        k++;
    }
    return ans;
}

ll comb(int n, int k)
{
    if(k < 0 || n < k) return 0;
    ll ans = (fact[n] * invfact[k])%mod;
    return (ans * invfact[n-k])%mod;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    fact[0] = 1;
    for(int i=1;i<=200000;i++) fact[i] = (fact[i-1] * i)%mod;
    invfact[200000] = pow(fact[200000], mod - 2);
    for(int i=199999;i>=0;i--) invfact[i] = (invfact[i+1] * (i+1))%mod;
    while(t--){
        int n, l, r; cin >> n >> l >> r;
        ll ans = (((n%2) + 1) * comb(n, n/2) * min(1-l, r-n))%mod;
        int d = abs(1-l - (r-n));
        int nown = n, nowk = n/2, oddk = n - n/2;
        for(int i=1;i<=d;i++)
        {
            nown--;
            ans += comb(nown, nowk)%mod;
            ans%= mod;
            if(n%2) ans += comb(nown, oddk)%mod;
            ans %= mod;
            if(nown < 0) break;
        }

        while(nown >= 0)
        {
            nown -= 2;
            nowk--;
            oddk--;

            ans += comb(nown, nowk)%mod;
            ans %= mod;
            if(n%2) ans += comb(nown, oddk)%mod;
            ans %= mod;
        }

        cout << ans << "\n";
    }
}