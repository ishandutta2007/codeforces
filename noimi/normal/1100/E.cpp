#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
#define MAX_V 400010
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define ALL(c) (c).begin(),(c).end()
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
template<typename A, size_t NNN, typename T>
void Fill(A (&array)[NNN], const T &val){
    fill( (T*)array, (T*)(array+NNN), val );
}
#define INF 1e9+7
#define LLINF 1e18+7
ll MOD=1e9+7;
#define N 205050

ll n,m;
ll p;
ll a[N];
ll b[N];
ll c[N];
vec G[N];
bool dfs(int u,vec &used,vec &order){
    used[u]=1;
    REP(e,G[u]){
        if(used[e]==1)return false;
        if(used[e]==2)continue;
        if(!dfs(e,used,order))return false;
    }
    order.pb(u);
    used[u]=2;return true;
}
bool tpsort(vec &order){
    vec used(n+1,0);
    rep2(i,1,n){
        if(!used[i]&&!dfs(i,used,order))return false;
    }
    reverse(ALL(order));
    return true;
}
struct query{
    int u,v,c,id;
};
ll tpn[N];
main(){
    n=in();m=in();
    vector<query> q;
    rep(i,m){
        q.pb(query{in(),in(),in(),(int)i+1});
    }
    sort(q.begin(),q.end(),[](query a,query b){
        return a.c<b.c;
    });
    int l=-1,r=INF;
    while(l<r-1){
        int mid=(l+r)/2;
        vector<ll> g(n+1,0);
        vec gg;
        rep2(i,1,n)G[i]=gg;
        rep(i,m){
            if(q[i].c<=mid)continue;
            G[q[i].u].pb(q[i].v);
        }
        if(tpsort(gg))r=mid;
        else l=mid;
    }
    cout<<r<<" ";
    vec gg;rep2(i,1,n)G[i]=gg;
    rep(i,m){
        if(q[i].c<=r)continue;
        G[q[i].u].pb(q[i].v);
    }
    vec topsort(n,0);
    tpsort(topsort);
    rep(i,n){
        tpn[topsort[i]]=i;
    }
    vec ans;
    rep(i,m){
        if(q[i].c>r)break;
        if(tpn[q[i].u]>tpn[q[i].v])ans.pb(q[i].id);
    }
    cout<<ans.size()<<endl;
    for(auto e:ans)cout<<e<<" ";
}