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
#define vec2ll(a,b) vector<vecll>(a,vecll(b))
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


    
void go();





main(){
    ios
    // int Testcases=1;
    int Testcases=in();
    while(Testcases--){
        go();
    }
    return 0;
}

int n,m;
vecll a;
vector<vec> g;
vector<pll> dfs(int x,int p){
    vector<pll> tmp;
    tmp.eb(0,a[x]);
    for(auto e:g[x]){
        if(e==p)continue;
        vector<pll> res=dfs(e,x);
        vector<pll> next(res.size()+tmp.size()-1,{-INT_MAX,-INT_MAX});
        rep(i,res.size()){
            rep(j,tmp.size()){
                if(chmax(next[i+j].fi,res[i].fi+tmp[j].fi)){
                    next[i+j].se=res[i].se+tmp[j].se;
                }
                else if(next[i+j].fi==res[i].fi+tmp[j].fi){
                    chmax(next[i+j].se,res[i].se+tmp[j].se);
                }
            }
        }
        tmp=next;
    }
    tmp.eb(tmp.back().fi+(tmp.back().se>0),0);
    rep3(i,tmp.size()-1,1){
        if(tmp[i-1].fi+(tmp[i-1].se>0) > tmp[i].fi){
            tmp[i].fi=tmp[i-1].fi+(tmp[i-1].se>0);
            tmp[i].se=0;
        }
        else if(tmp[i-1].fi+(tmp[i-1].se>0) == tmp[i].fi){
            chmax(tmp[i].se,0ll);
        }
    }
    // print(tmp);
    return tmp;
}
void go(){
    n=in();
    m=in();
    a=vecll(n);
    g=vector<vec>(n);
    rep(i,n){
        a[i]-=in();
    }
    rep(i,n)a[i]+=in();
    rep(i,n-1){
        int x=in()-1,y=in()-1;
        g[x].pb(y);
        g[y].pb(x);
    }
    vector<pll> ans=dfs(0,-1);
    m--;
    cout<<ans[m].fi+(ans[m].se>0)<<endl;
}