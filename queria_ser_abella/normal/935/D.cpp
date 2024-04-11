#include <bits/stdc++.h>
using namespace std;
#define sq(x) ((x)*(x))
#define double long double

int a[400400];
int b[400400];

#define ll long long 
#define mod 1000000007

ll exp(ll a,ll b){
    if(b == 0) return 1;
    ll m = exp(a,b/2);
    m = (m*m)%mod;
    if(b&1) m = (m*a)%mod;
    return m;
}

ll mul(ll a,ll b){
    a %= mod;
    b %= mod;
    return (a*b)%mod;
}

ll inv(ll a){
    return exp(a,mod-2);
}

main(){
   
    int n,m;
    scanf("%d%d",&n,&m);
    
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<n;i++)
        scanf("%d",b+i);
        
    long long esf = 1;
    long long ans = 0;
    
    for(int i=0;i<n;i++){
        
        if(a[i] != 0 && b[i] != 0){
            if(a[i] == b[i]) continue;
            if(a[i] < b[i]) esf = 0;
            if(a[i] > b[i]) { ans += esf; esf = 0; ans %= mod;}
        }
        
        if(a[i] == 0 && b[i] == 0){
            int pdif = mul(m-1,inv(2*m));
            int peq = inv(m);
            ans += mul(esf,pdif);
            esf *= peq;
            ans %= mod;
            esf %= mod;
        }
        
        if(a[i] == 0 && b[i] != 0){
            int pdif = mul(m-b[i],inv(m));
            int peq = inv(m);
            ans += mul(esf,pdif);
            esf *= peq;
            ans %= mod;
            esf %= mod;
        }
        
        if(a[i] != 0 && b[i] == 0){
            int pdif = mul(a[i]-1,inv(m));
            int peq = inv(m);
            ans += mul(esf,pdif);
            esf *= peq;
            ans %= mod;
            esf %= mod;
        }
        
    }
    
    printf("%d\n",(int)ans);
    
}