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
#define INF 1e9+7
#define N 310000
#define MAX_V 400010
#define vec vector<int>
using namespace std;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
#define umap unordered_map<ll,int,custom_hash>
struct pair_hash
{
    template<class T1,class T2>
    size_t operator() (const pair<T1,T2> &p)const{
        return hash<T1>()(p.first)^hash<T2>()(p.second);
    }
};
//0-indexed
ll bit[N*2];
ll sum(int i){
    ll s=0;
    while(i>=0){
        s+=bit[i];
        i-=(i+1)&-(i+1);
    }
    return s;
}
void add(int i,ll x){
    while(i<=N+1){
        bit[i]+=x;
        i+=(i+1)&-(i+1);
    }
}
ll bit2[N*2];
ll sum2(int i){
    ll s=0;
    while(i>=0){
        s+=bit2[i];
        i-=(i+1)&-(i+1);
    }
    return s;
}
void add2(int i,ll x){
    while(i<=N+1){
        bit2[i]+=x;
        i+=(i+1)&-(i+1);
    }
}
ll n,t;
main(){
    cin>>n>>t;
    ll a[N];
    rep(i,n){
        scanf("%lld",&a[i]);
        add(i,a[i]);
        add2(i,1);
    }
    ll ans=0;
    int pos=0;
    while(1){
        ll s=sum(n-1);
        ll num=sum2(n-1);
        if(s<t){
            ans+=num*(t/s);
            t%=s;
        }
        int l=pos-1,r=l+n+1;

        while(l<r-1){
            int mid=(l+r)/2;
            ll p;
            if(mid>n-1){
                mid%=n;
                p=sum(n-1)+sum(mid)-sum(pos-1);
            }
            else{
                p=sum(mid)-sum(pos-1);
            }
            if(p>t)r=(l+r)/2;
            else l=(l+r)/2;
        }
        if(l>n-1){
            l%=n;
            t-=sum(n-1)+sum(l)-sum(pos-1);
            ans+=sum2(n-1)+sum2(l)-sum2(pos-1);
        }
        else{
            t-=sum(l)-sum(pos-1);
            ans+=sum2(l)-sum2(pos-1);            
        }
        add(r%n,-a[r%n]);
        add2(r%n,-1);
        pos=(r+1)%n;
        if(sum2(n-1)==0)break;
    }
    cout<<ans;
}