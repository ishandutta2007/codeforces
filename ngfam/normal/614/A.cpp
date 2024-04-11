#define ll long long
#include <bits/stdc++.h>
using namespace std;
const ll ff=1e18;
ifstream fi("TEST.INP");
ofstream fo("TEST.OUT");
inline ll lt(ll k,ll x){
    if(x==0)return 1;
    if(x==1)return k;
    ll f=lt(k,x/2);
    if(x%2==0)return f*f;
    return f*f*k;
}
ll getlog(ll x,int k){
    if(x<k)return 0;
    return 1+getlog(x/k,k);
}

int main(){
    ll l,r,k,m,n;
    cin>>l>>r>>k;
    m=getlog(l,k);
    n=lt(k,m);
    if(n<l && ff/k<n){
        cout<<-1;
        return 0;
    }
    while(n<l && n<=ff/k)n*=k;
    
    if(n>r){
        cout<<-1;
        return 0;
    }
    while(n<=r){
        cout<<n<<" ";
        if(n>r/k)break;
        n*=k;
    }
    return 0;
}