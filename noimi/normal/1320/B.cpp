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


main(){
    int n=in(),m=in();
    vector<vec> g;
    g.resize(n);
    rep(i,m){
        int a=in()-1,b=in()-1;
        g[b].pb(a);
    }
    int k=in();
    queue<int> q;
    vec a;
    rep(i,k)a.pb(in()-1);
    int t=a.back();
    q.emplace(t);
    vec d(n,-1000) , twice(n);
    int cnt=0;
    while(!q.empty()){
        queue<int> next;
        while(!q.empty()){
            int p=q.front();q.pop();
            if(d[p]<cnt and d[p]!=-1000)continue;
            if(d[p]==cnt){
                twice[p]=1;
                continue;
            }
            d[p]=cnt;
            for(auto e:g[p]){
                if(d[e]!=-1000)continue;
                next.emplace(e);
            }
        }
        cnt++;
        q=next;
    }
    int mi=0,ma=0;
    int now=d[a[0]];
    rep2(i,1,k-1){
        if(d[a[i]]>=d[a[i-1]]){
            mi++;ma++;
        }
        else{
            if(twice[a[i-1]])ma++;
        }
    }
    // print(d);
    cout<<mi<<" "<<ma<<endl;
}