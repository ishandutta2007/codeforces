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
#define INF 100000000
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
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15);
    int tc=1;
    // tc=in();
    while(tc--){
        go();
    }
    return 0;
}

vector<vec> g,h;
vec visited[2],vis;
bool roop=0;
vec ans;
bool dfs(int x,int c){
    if(c and h[x].empty()){
        ans.pb(x+1);
        return true;
    }
    if(visited[c][x]){
        if(vis[x])
        roop=1;
        return false;
    }
    if(visited[c^1][x]){
        if(vis[x])
        roop=1;
    }
    visited[c][x]=vis[x]=1;
    for(auto e:h[x]){
        if(dfs(e,c^1)){
            ans.pb(x+1);return true;
        }
    }
    vis[x]=0;
    return false;
}
void go(){
    int n=in(),m=in();
    vec st;
    g.resize(n);
    h.resize(n);
    visited[0].resize(n);
    visited[1].resize(n);
    vis.resize(n);
    rep(i,n){
        int c=in();
        if(c==0)st.eb(i);
        rep(j,c){
            int u=in()-1;
            g[u].pb(i);
            h[i].pb(u);
        }
    }
    int s=in();
    if(dfs(s-1,0)){
        reverse(all(ans));
        cout<<"Win\n";
        print(ans);
    }
    else{
        if(roop)cout<<"Draw\n";
        else cout<<"Lose\n";
    }

        
            
}