#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep3(i,a,b) for(int i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll MOD=1e9+7;
#define INF 1e9+7
#define N 400001
#define MAX_V 400010
#define vec vector<int>
#define ALL(c) (c).begin(),(c).end()
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
template<typename A, size_t NNN, typename T>
void Fill(A (&array)[NNN], const T &val){
    fill( (T*)array, (T*)(array+NNN), val );
}
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

vector<pll> G[N];
ll ans[N],w[N];
ll s;
ll dfs(int t,int p){
    ll temp1=w[t],temp2=0;
    rep(i,G[t].size()){
        if(G[t][i].first==p)continue;
        temp2=max(temp2,dfs(G[t][i].first,t)+w[t]-G[t][i].second);
        if(temp2>temp1)swap(temp1,temp2);
    }
    s=max(s,temp1+temp2-w[t]);
    return temp1;
}
main(){
    ll n=lin();
    rep2(i,1,n)w[i]=lin();
    rep2(i,1,n){
        ans[i]=w[i];
    }
    rep(i,n-1){
        ll u=lin(),v=lin(),c=lin();
        G[u].pb({v,c});
        G[v].pb({u,c});    
    }
    s=max(s,dfs(1,0));
    rep2(i,1,n)s=max(s,w[i]);
    cout<<s;
}