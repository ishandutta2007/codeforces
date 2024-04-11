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
// #define INF 100000000
using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {ll x;cin>>x;return x;}
string stin() {string s;cin>>s;return s;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline void print(pair<T,T> p){cout<<"("<<p.first<<","<<p.second<<") ";}
template<class T> inline void print(vector<pair<T,T>> v){for(auto e:v)print(e); cout<<endl;}
template<class T> inline void print(T v){for(auto e:v)cout<<e<<" ";cout<<endl;}


vector<vec> g;
vec d,d2;
vec rt;
int dfs(int x,int p,int root){
    rt[x]=root;
    int ma[2]={};
    for(auto e:g[x])
    if(e!=p){
        chmax(ma[1],dfs(e,x,root));
        if(ma[0]<ma[1])swap(ma[0],ma[1]);
    }
    d[x]=ma[0];
    d2[x]=ma[1];
    return ma[0]+1;
}

void dfs2(int x,int p,int t){
    for(auto e:g[x]){
        if(e==p)continue;
        if(d[e]+1==d[x])dfs2(e,x,max(d2[x]+1,t+1));
        else dfs2(e,x,max(d[x]+1,t+1));
    }
    chmax(d[x],t);
}
vector<vec> mem,mem2;
vec diameter;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15);
    int n=in();
    g.resize(n);d.resize(n);d2.resize(n);rt.resize(n);
    rt=vec(n,-1);
    int m=in(),q=in();
    rep(i,m){
        int a=in()-1,b=in()-1;
        g[a].pb(b);
        g[b].pb(a);
    }
    mem.resize(n);mem2.resize(n);
    rep(i,n){
        if(rt[i]==-1){
            dfs(i,-1,i);
            dfs2(i,-1,0);
        }
    }
    // print(rt);
    diameter.resize(n);
    rep(i,n){
        mem[rt[i]].pb(d[i]);
        chmax(diameter[rt[i]],d[i]);
    }
    rep(i,n){
        if(!mem[i].empty()){
            sort(all(mem[i]));
            mem2[i].pb(0);
            for(auto e:mem[i])mem2[i].pb(mem2[i].back()+e);
        }
    }
    vecpii v;
    rep(i,q){
        int a=rt[in()-1],b=rt[in()-1];
        v.eb(a,b);
    }
    vec id;
    rep(i,q)id.pb(i);
    sort(all(id),[&](int x,int y){return v[x]<v[y];});
    double preans;
    vector<double> ANS(q);
    rep(i,q){
        int e=id[i];
        int a=v[e].fi,b=v[e].se;
        if(a==b){
            ANS[id[i]]=-100;
            preans=-100;
        }
        else{
            if(i and v[e] == v[id[i-1]]){ANS[id[i]]=preans;continue;}
            long double ans=(long double)mem2[a].back()*mem[b].size()+(long double)mem2[b].back()*mem[a].size();
            int D = max(diameter[a],diameter[b]);
            if(mem[a].size()>mem[b].size())swap(a,b);
            rep(i,mem[a].size()){
                int t=lb(mem[b],D-1-mem[a][i]);
                ans+=((ll)D*t-mem2[b][t]-(ll)t*mem[a][i]-t);
            }
            ans/=(long double)(mem[a].size()*mem[b].size());
            ans+=1;
            preans=ans;
            ANS[id[i]]=ans;
        }
    }
    for(auto e:ANS){
        if(e<-1)cout<<-1<<endl;
        else cout<<e<<endl;
    }
}