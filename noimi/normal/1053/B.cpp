#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll MOD=1e9+7;
#define INF 2*1e9
#define N 1000010
#define MAX_V 900010
using namespace std;
int count(ll x){
    int res=0;
    while(x){
        res+=x%2;
        x/=2;
    }
    return res;
}
main(){
    int n;
    cin>>n;
    ll a[N];
    a[0]=0;
    rep2(i,1,n)scanf("%lld",&a[i]);
    rep2(i,1,n)a[i]=count(a[i]);
    ll s[N];
    s[0]=0;
    rep2(i,1,n){
        s[i]=s[i-1]+a[i];
    }
    ll odd=0,even=0;
    rep(i,n+1){
        if(s[i]%2)odd++;
        else even++;
    }
    ll ans=0;
    ans=odd*(odd-1)/2+even*(even-1)/2;
    int t[N];
    t[0]=0;
    rep2(i,1,n){
        t[i]=t[i-1]+s[i]%2;
    }

    
    rep2(i,1,n){
        rep(j,n){
            if(i-j<1)break;
            int sum=s[i]-s[i-j-1];
            if(sum>=a[i]*2)break;
            int p=(lower_bound(s,s+(n+1),s[i-j-1]+a[i]*2)-s)-1;
            if(sum%2^s[i]%2)ans-=t[p]-t[i-1];
            else ans-=(p-i+1)-t[p]+t[i-1];
        }
    }
    cout<<ans;
}