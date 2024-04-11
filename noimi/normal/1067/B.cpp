// #pragma GCC optimize("O3")
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

vector<vec> g;

vec d;
void dfs(int x,int p,int t,int &ma,int &mem){
    d[x]=t;
    if(chmax(ma,t))mem=x;
    for(auto e:g[x]){
        if(e!=p){
            dfs(e,x,t+1,ma,mem);
        }
    }
}
bool f=1;
int center(int n){
    d.resize(n);
    int ma=-1,mem;
    dfs(0,-1,0,ma,mem);
    int mem2;ma=-1;
    dfs(mem,-1,0,ma,mem2);
    vec r={mem2};
    while(mem2!=mem){
        ma--;
        for(auto e:g[mem2]){
            if(d[e]==ma){
                r.pb(e);
                mem2=e;
                break;
            }
        }
    }
    if(r.size()%2==0)f=0;
    return r[r.size()/2];
}
    

main(){
    ios
    int n=in(),k=in();
    g.resize(n);
    rep(i,n-1){
        int a=in()-1,b=in()-1;
        g[a].pb(b);
        g[b].pb(a);
    }
    int cen=center(n);
    rep(i,n){
        if(i!=cen)
        {
            if(g[i].size()<4 and g[i].size()!=1)f=0;
        }
        else{
            if(g[i].size()<3)f=0;
        }
    }
    int x,y;
    dfs(cen,-1,0,x,y);
    rep(i,n){
        if(i!=cen and g[i].size()==1 and d[i]!=k)f=0;
    }
    cout<< (f ? "Yes\n" : "No\n");
}