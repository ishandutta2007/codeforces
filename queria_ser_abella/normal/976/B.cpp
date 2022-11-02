#include <bits/stdc++.h>
#define maxn 300300
using namespace std;
#define pb push_back
#define pii pair<ll,ll>
#define pip pair<ll,pii>
#define debug
#define ll long long
#define move ouehfri
#define left cjsbsoiyafg

main(){
    ll n,m,k;
    cin >> n >> m >> k;
    if(k <= n-1){
        printf("%lld 1\n",k+1);
        return 0;
    }
    k -= n;
    ll u = k / ((m-1)*2);
    
    ll x = n - 2*u;
    k %= (m-1)*2;
    
    
    debug("%lld %lld %lld\n",x,k,u);
    
    if(k <= m-2){
        printf("%lld %lld\n",x,2+k);
        return 0;
    }
    debug("!%lld %lld\n",k,m);
    k -= m-1;
    printf("%lld %lld\n",x-1,m-k);
}