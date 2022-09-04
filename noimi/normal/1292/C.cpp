#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define vec2(a,b) vector<vec>(a,vec(b))
#define vec2ll(a,b) vector<vec>(a,vecll(b))
#define vec3(a,b,c) vector<vector<vec>>(a,vec2(b,c))
#define vec3ll(a,b,c) vector<vector<vecll>>(a,vec2ll(b,c))
#define fi first
#define se second
#define endl "\n"
#define all(c) begin(c),end(c)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))
#define MM " "
using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {ll x;cin>>x;return x;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline void print(pair<T,T> p){cout<<"("<<p.first<<","<<p.second<<") ";}
template<class T> inline void print(vector<pair<T,T>> v){for(auto e:v)print(e); cout<<endl;}
template<class T> inline void print(T v){for(auto e:v)cout<<e<<" ";cout<<endl;}

vector<vec> g;
struct node{
    int x,par,d;
};
struct line{
    int l,r,len,lnext,rnext,cnt;
};
vector<line> mem;
int sz[3100],n;
void DFS(int x,int p){
    for(auto e:g[x]){
        if(e==p)continue;
        DFS(e,x);
        sz[x]+=sz[e];
    }
    sz[x]++;
}
vector<node> dfs(int x,int p){
    vector<node> v;
    vector<pair<int,vector<node>>> vv;
    for(auto e:g[x]){
        if(e==p)continue;
        vector<node> w=dfs(e,x);
        for(auto a:v){
            for(auto b:w){
                mem.eb(line{a.x , b.x , a.d+b.d , a.par , b.par , sz[a.x]*sz[b.x] });
            }
        }
        vv.eb(e,w);
        for(auto a:w){
            v.eb(node{a.x,a.par,a.d+1});
            mem.eb(line{a.x,x,a.d,a.par,e,sz[a.x]*(n-sz[e])});
        }
    }
    if(x)
    v.eb(node{x,p,1});
    return v;
}
ll dp[3100][3100];

main(){
    ios
    n=in();
    g.resize(n);
    rep(i,n-1){
        int a=in()-1,b=in()-1;
        g[a].pb(b);
        g[b].pb(a);
    }
    DFS(0,-1);
    dfs(0,-1);
    sort(all(mem),[](auto x,auto y){
        return x.len>y.len;
    });
    for(auto e:mem){
        // cout<<e.l+1<<" "<<e.r+1<<" "<<e.lnext+1<<" "<<e.rnext+1<<" "<<e.cnt<<endl;
        chmax(dp[e.lnext][e.r],dp[e.l][e.r]+e.cnt);
        chmax(dp[e.rnext][e.l],dp[e.l][e.r]+e.cnt);
        dp[e.r][e.lnext]=dp[e.lnext][e.r];
        dp[e.l][e.rnext]=dp[e.rnext][e.l];
    }
    ll ma=0;
    rep(i,n)rep(j,n){
        chmax(ma,dp[i][j]);
    }
    cout<<ma<<endl;
}