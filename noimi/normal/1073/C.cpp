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
ll dx[4]={(ll)0,(ll)1,(ll)0,(ll)-1};
ll dy[4]={(ll)1,(ll)0,(ll)-1,(ll)0};
main(){
    ll n;cin>>n;
    string s;cin>>s;
    ll a,b;cin>>a>>b;
    if((s.size()^((a+b)%2+2))%2){
        cout<<-1;return 0;
    }
    if(abs(a)+abs(b)>n){
        cout<<-1;return 0;
    }
    ll x=0,y=0;
    ll t[N];
    rep(i,n){
        if(s[i]=='U')t[i]=0;
        if(s[i]=='R')t[i]=1;
        if(s[i]=='D')t[i]=2;
        if(s[i]=='L')t[i]=3;
    }
    rep(i,n){
        x+=dx[t[i]];
        y+=dy[t[i]];
    }
    if(x==a&&y==b){cout<<0;return 0;}
    int l=0,r=1;
    x-=dx[t[l]];
    y-=dy[t[l]];
    int ans=INF;
    while(r<=n){        
        while(r<=n&&r-l<abs(a-x)+abs(b-y)){
            x-=dx[t[r]];
            y-=dy[t[r]];
            r++;
        }
        if(r<=n)
        ans=min(ans,r-l);
        x+=dx[t[l]];
        y+=dy[t[l]];
        l++;
    }
    cout<<ans;
}