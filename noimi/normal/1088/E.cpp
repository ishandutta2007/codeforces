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


vec G[N];
ll a[N];
pair<ll,ll> mem[N];
vector<ll> v;
pair<ll,ll> dfs(int x,int p){
    ll sum=0;
    ll f=-1;
    rep(i,G[x].size()){
        if(G[x][i]==p)continue;
        pll temp=dfs(G[x][i],x);
        if(temp.first>(ll)0){
            sum+=temp.first;
        }
        f=max(f,temp.second);
    }
    if(sum+a[x]>0){
        if(sum+a[x]>f){
            v.pb(sum+a[x]);
            f=sum+a[x];
        }
        return mem[x]={sum+a[x],f};
    }
    return {0,0};
}
main(){
    int n=in();
    bool flag=false;
    rep2(i,1,n){
        a[i]=lin();
        if(a[i]>0)flag=1;
    }

    rep(i,n-1){
        ll c=lin(),d=lin();
            G[c].pb(d);
            G[d].pb(c);
    }
        if(!flag){
        ll m=-2000000000;
        rep2(i,1,n){
            m=max(m,a[i]);
        }
        ll count=0;
        rep2(i,1,n){
            if(m==a[i])count++;
        }
        cout<<count*m<<" "<<count;
        return 0;
    }
    dfs(1,0);
    ll ans=0;
    ll m=0;
    rep(i,v.size()){
        m=max(m,v[i]);
    }
    rep(i,v.size()){
        if(m==v[i])ans++;
    }
    cout<<ans*m<<" "<<ans;
}