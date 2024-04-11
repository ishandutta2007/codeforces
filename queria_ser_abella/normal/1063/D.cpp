#include <bits/stdc++.h>
#define pii pair<int,int>
#define pip pair<int,pii>
#define maxn 2020
#define debug 
typedef long long ll;
using namespace std;

const int maxc = 1000000000;

int main(){
    
    ll n,k,l,r;
    scanf("%lld%lld%lld%lld",&n,&l,&r,&k);
    
    ll d = r-l+1;
    if(l > r){
        d = n-l+1+r;
    }

    if(d == n){
        
        ll ans = -1;
        for(ll i=1;i*i<=k+1;i++){
            if(k%i == 0){
                if(i >= n && i <= 2*n) ans = max(ans,i-n);
                if(k/i >= n && k/i <= 2*n) ans = max(ans,k/i-n);
            }
            if((k+1)%i == 0){
                if(i > n && i <= 2*n) ans = max(ans,i-n);
                if((k+1)/i > n && (k+1)/i <= 2*n) ans = max(ans,(k+1)/i-n);
            }
        }
        
        printf("%lld\n",ans);
        return 0;
        
    }
    
    if(n < 3e7){
        
        ll ans = -1;
        for(int i=0;i<=n;i++){
            
            ll res = k % (n+i);
            if(res < d) continue;
            if(res > 2*d) continue;
            ll u = res-d;
            if(u > i) continue;
            ll uu = i-u;
            if(n-d < uu-1) continue;
            ans = i;
            
        }
        printf("%lld\n",ans);
        return 0;
    }
    
    ll best = -1;
    for(int cyc=0;cyc<5000;cyc++){
        
            ll l = -1, r = 1e12;
            ll lo = 0, hi = n+1;
            while(lo != hi){
                ll mid = (lo+hi)/2;
                int ok = 1;
                if( k / (n + mid) > cyc) ok = 0;
                ll res = k - (ll) cyc * (n+mid);
                if(res > 2*d) ok = 0;
                if(res > d + mid) ok = 0;
                
                
                if(ok)
                    hi = mid;
                else
                    lo = mid+1;
            }
            l = lo;
             lo = -1, hi = n+1;
            while(lo != hi){
                ll mid = (lo+hi+1)/2;
                int ok = 1;
                if( k / (n + mid) < cyc) ok = 0;
                ll res = k - (ll) cyc * (n+mid);
                if(res < d) ok = 0;
                ll need = max(0ll,mid - (n-d)-1);
                if(cyc == 0 && mid == 5) debug("! %lld %lld\n",need,res);
                if(res < d + need) ok = 0;
                
                if(ok)
                    lo = mid;
                else
                    hi = mid-1;
            }
            r = lo;
            if(l == n+1 || k < (ll) cyc * n) r = -1;
            debug("cyc %d l %lld r %lld\n",cyc,l,r);
            if(l > r) continue;
            best = max(best,r);;
            
        
    }
    printf("%lld\n",best);
}