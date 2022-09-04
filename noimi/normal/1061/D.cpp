#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
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
#define N 200010
#define MAX_V 400010
#define vec vector<int>
#define ALL(c) (c).begin(),(c).end()

int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
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
vector<int> divisor(int n){
    vector<int> res;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            res.push_back(i);
            if(i!=n/i) res.push_back(n/i);
        }
    }
    return res;
}

main(){
    ll n,x,y;
    cin>>n>>x>>y;
    pll p[N];
    ll ans=0;
    rep(i,n){
        cin>>p[i*2].first;
        cin>>p[i*2+1].first;
        p[i*2].second=-(i+1);
        p[i*2+1].second=(i+1);
        ans+=x+y*(p[i*2+1].first-p[i*2].first)%MOD;
        ans%=MOD;
    }
    sort(p,p+(2*n));
    stack<int> s;
    rep(i,2*n){
        if(p[i].second<0&&s.empty())continue;
        if(p[i].second<0){
            if(x-y*(p[i].first-s.top())>0){
                ans=(ans+MOD-(x-y*(p[i].first-s.top())%MOD))%MOD;
                s.pop();
            }
        }
        else{
            s.push(p[i].first);
        }
    }
    cout<<ans;
}