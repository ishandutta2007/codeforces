#pragma GCC optimize("O3")
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
#include <deque>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <chrono>
#include <random>
#include <time.h>
#include <fstream>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pb push_back
#define eb emplace_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define vec2 vector<vec>
#define vecll2 vector<vecll>
#define vec3 vector<vec2d>
#define vecll3 vector<vecll2d>
#define fi first
#define se second
#define endl "\n"
#define all(c) begin(c),end(c)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {ll x;cin>>x;return x;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline void print(vector<T> v){for(T e:v)cout<<e<<" ";cout<<endl;}
template<class T> inline void print(pair<T,T> p){cout<<"("<<p.first<<","<<p.second<<") ";}
template<class T> inline void print(vector<pair<T,T>> v){for(auto e:v)print(e); cout<<endl;}
void print(vector<vec> v){for(auto e:v){for(auto ee:e)cout<<ee<<" ";cout<<endl;}}
void print(map<int,int> mp){for(auto e:mp)cout<<e.first<<" "<<e.second<<endl;cout<<endl;}

vector<vec> G;
bool flag=1;
vec t;
vec dfs(int x){
    if(G[x].size()){
        vec res;
        for(auto e:G[x]){
            vec now=dfs(e);
            for(auto c:now){
                if(res.size()==t[x])res.pb(x);
                res.pb(c);
            }
        }
        if(res.size()==t[x])res.pb(x);
        if(res.size()<t[x])flag=0;
        return res;
    }
    else{
        if(t[x])flag=0;
        return {x};
    }
}
main(){
    int n=in();G.resize(n);t.resize(n);
    int r;
    rep(i,n){
        int a=in()-1,b=in();
        if(a==-1)r=i;
        else{
            G[a].pb(i);
        }
        t[i]=b;
    }
    vec ans(n),tmp=dfs(r);
    if(!flag){
        cout<<"NO\n";return 0;
    }
    cout<<"YES\n";
    rep(i,n)ans[tmp[i]]=i+1;
    rep(i,n){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}