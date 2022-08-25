#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c[40],pmin[40];
ll chkmin(ll &a,ll b){return a>b?a=b,1:0;}
ll Get_min(ll l){
    if(!l)return 0;
    ll i;
    for(i=30;~i&&(1<<i)>l;--i);
    return min(pmin[i+1],c[i]+Get_min(l-(1<<i)));
}
int main(){
    ll n,l;
    scanf("%I64d%I64d",&n,&l);
    for(ll i=0;i<n;++i){
        scanf("%I64d",c+i);
        if(i)chkmin(c[i],c[i-1]<<1);
    }
    c[n]=c[n-1]<<1;
    pmin[n]=c[n];
    for(ll i=n-1;~i;--i)pmin[i]=min(c[i],pmin[i+1]);
    --n;
    ll ans=(l>>n)*c[n];
    l=l&((1<<n)-1);
    printf("%I64d\n",ans+Get_min(l));
    return 0;
}