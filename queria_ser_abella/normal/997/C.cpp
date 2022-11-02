#include <bits/stdc++.h>
#define ll long long
#define maxn 3003000
#define mod 998244353
#define debug 

using namespace std;

ll fat[maxn];
ll ifat[maxn];

inline long long int fexp(long long base,long long power,long long M=0)
{
        long long result=1;
        while (power>0) 
        {
                if (power%2==1)         
                        result = (result*base)%mod;
                base = (base*base)%mod;
                power/=2;
        }
        return result;
}

/*ll fexp(ll a,ll b){
    if(b == 0)
        return 1;
    ll k = fexp(a,b/2);
    k = (k*k)%mod;
    if(b&1)
        k = (k*a)%mod;
    return k;
}*/

inline ll p3(ll a){
    return fexp(3,a);
}

inline ll inv (ll a){
    return fexp(a%mod,mod-2);
}

inline ll C(int n,int k){
    ll r = fat[n];
    r = (r*ifat[k]) % mod;
    r = (r*ifat[n-k]) % mod;
    debug("C %d %d = %lld\n",n,k,r);
    return r;
}

ll cni[maxn];

int main(){
    
    int n;
    scanf("%d",&n);
    
    fat[0] = ifat[0] = 1;
    for(int i=1;i<=n;i++){
        fat[i] = (fat[i-1]*i) % mod;
        ifat[i] = inv(fat[i]);
    }
    
    ll ans = 0;
    
    int s = -1;
    for(int i=1;i<=n;i++){
        s = -s;
        ll r = C(n,i);
        cni[i] = r;
        r = (r * p3(i) ) % mod;
        r = (r * p3( (ll) n * (n-i))) % mod;
        r *= s;
        ans += r;
        if(ans < 0) ans += mod;
        if(ans >= mod) ans -= mod;
    }
    debug("%lld\n",ans);
    s = -1;
    for(int i=1;i<=n;i++){
        s = -s;
        ll rdif = cni[i];
        ll req = rdif;
        
        req = (req*3) % mod;
        
        ll lin = p3(n-i) - 1;
        if(lin < 0) lin += mod;
        debug("lin %lld\n",lin);
        lin = fexp(lin,n);
        debug("-> %lld\n",lin);
        
        debug("Oi %lld\n",req);
        req = (req * lin) % mod;
        debug("req -> %lld\n",req);
        req *= s;
        ans += req;
        debug("+ %lld\n",req);
        if(ans < 0) ans += mod;
        if(ans >= mod) ans -= mod;
        
        if(i == 1) continue;
        
        ll col = p3(i) - 3;
        if(col < 0) col += mod;
        
        rdif = (rdif * col) % mod;
        rdif = (rdif * p3 ( (ll) n * (n-i))) % mod;
        rdif *= s;
        ans += rdif;
        debug("+ %lld\n",rdif);
        if(ans < 0) ans += mod;
        if(ans >= mod) ans -= mod;
        
    }    
        
    printf("%lld\n",ans);
        
}