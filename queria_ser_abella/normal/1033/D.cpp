#include <bits/stdc++.h>
#define maxn 200200
#define pb push_back
#define pii pair<int,int>
#define debug 
#define mod 998244353
typedef long long ll;
using namespace std;

ll gcdll(ll a,ll b){
    return b ? gcdll(b,a%b) : a;
}


int eq[maxn];
int ok[maxn];
ll v[maxn];

ll pr[maxn];

ll primes[maxn];

map<ll,int> mp;

ll fexp(ll a,ll b){
    ll r = 1;
    while(b--)
        r *= a;
    return r;
}


ll rt(ll a,ll u){
    ll x = pow(a,1.0/(double)u);
    x -= 4;
    x = max(x,1ll);
    while(fexp(x,u) < a) x++;
    return x;
}

int isp(ll x){
    for(ll a=2;a*a<=x;a++)
        if(x%a == 0) return 0;
    return 1;
}

int main(){
    int n;
    scanf("%d",&n);
    set<ll> S;
    for(int i=0;i<n;i++){
        scanf("%lld",v+i);
        for(int j=4;j>=2;j--){
            ll x = rt(v[i],j);
            if(fexp(x,j) != v[i]) continue;
           // if(!isp(x)) return 0;;
            ok[i] = 1;
            debug("%d %lld ^ %d\n",i,x,j);
            for(int k=0;k<j;k++)
                mp[x]++;
            S.insert(x);
            break;
        }
    }
    
    
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(!ok[i] && !ok[j])
                if(v[i] != v[j]) 
                S.insert(gcdll(v[i],v[j]));
                
                
                
    ll ans = 1;
    
    
    
    
    
    int sz = 0;
    for(set<ll> :: iterator it = S.begin(); it != S.end(); it++)
        if(*it != 1){
            primes[sz++] = *it;
            debug("+ %lld\n",*it);
            
        }
    for(int i=0;i<n;i++)
        if(!ok[i]){
            
            for(int j=0;j<sz;j++)
                if(v[i]%primes[j] == 0){
                    mp[primes[j]]++;
                    v[i] /= primes[j];
                    assert(v[i] != 1);
                    mp[v[i]]++;
                    v[i] = 1;
                    ok[i] = 1;
                }
            if(v[i] != 1){
                debug("%d 4\n",i);
               // ans *= 4;
            //    ans %= mod;
            }
        
        }
        
  //  for(int i=0;i<n;i++)
//        for(int j=i+1;j<n;j++)
 //           if(!ok[i] && v[i] != 1 && v[i] == v[j]) eq[i] = eq[j] = 1;
            
    for(int i=0;i<n;i++)
        if( !ok[i]){
            
            ok[i] = 1;
            int t = 1;
            for(int j=i+1;j<n;j++)
                if(v[j] == v[i]){
                    ok[j] = 1;
                    t++;
                }
            
            ans *= (t+1);
            ans %= mod;
             ans *= (t+1);
            ans %= mod;
        }
    
    
    for(map<ll,int> :: iterator it = mp.begin(); it != mp.end(); it++){
        debug("pr %lld %d\n",it->first,it->second);
        ans *= (1+it->second);
        ans %= mod;
    }
    
    printf("%lld\n",ans);
        
}