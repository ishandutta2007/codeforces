#include <bits/stdc++.h>
#define maxn 300300
using namespace std;
#define pb push_back
#define pii pair<ll,ll>
#define pip pair<ll,pii>
#define debug 
#define ll long long
#define mod 1000000009

ll exp(ll a,ll b){
    if(b == 0)
        return 1;
    ll k = exp(a,b/2);
    k = (k*k)%mod;
    if(b&1)
        k = (k*a)%mod;
    return k;
}

ll inv(ll x){
    return exp(x%mod,mod-2);
}

main(){
    
    ll n,a,b,k;
    cin >> n >> a >> b >> k;
    ll ans = 0;
    ll r = (b * inv(a)) % mod;
    ll u = (n+1)/k;
    
    if(0){
        int y = 0;
        for(int i=0;i<k;i++){
            char ch;
            scanf(" %c",&ch);
            if(ch == '+') y++;
            else y--;
        }
        ans = u*y;
        ans %= mod;
        ans += mod;
        ans %= mod;
        ans *= exp(a,n);
        ans %= mod;
        cout << ans << endl;
        return 0;
    }
    
    for(int i=0;i<k;i++){
        char ch;
        scanf(" %c",&ch);
        ll s = exp(r,u*k) - 1;
        s *= inv(exp(r,k)-1);
        s %= mod;
        s += mod;
        s %= mod;
        if(exp(r,k) == 1)
            s = u;
        s *= exp(r,i);
        s %= mod;
        if(ch == '+')
            ans += s;
        else
            ans -= s;
        ans = (ans%mod+mod)%mod;
    }
    ans = ans * exp(a,n);
    ans %= mod;
    cout << ans << endl;
}